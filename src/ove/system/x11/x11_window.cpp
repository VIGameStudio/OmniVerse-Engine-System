#include "x11_window.hpp"

using namespace ove;
using namespace core;
using namespace system;

#define GLX_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB 0x2092
typedef GLXContext(*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);

// Helper to check for extension string presence.  Adapted from:
//   http://www.opengl.org/resources/features/OGLextensions/
static bool isExtensionSupported(const char* extList, const char* extension)
{
	const char* start;
	const char* where, * terminator;

	/* Extension names should not have spaces. */
	where = strchr(extension, ' ');
	if (where || *extension == '\0')
		return false;

	/* It takes a bit of care to be fool-proof about parsing the
	 OpenGL extensions string. Don't be fooled by sub-strings,
	 etc. */
	for (start = extList;;) {
		where = strstr(start, extension);

		if (!where)
			break;

		terminator = where + strlen(extension);

		if (where == start || *(where - 1) == ' ')
			if (*terminator == ' ' || *terminator == '\0')
				return true;

		start = terminator;
	}

	return false;
}

static bool ctxErrorOccurred = false;
static int ctxErrorHandler(Display* dpy, XErrorEvent* ev)
{
	ctxErrorOccurred = true;
	return 0;
}

bool x11_window_t::create(const char* title, u32 width, u32 height)
{
	m_pDisplay = XOpenDisplay(NULL);

	if (m_pDisplay == nullptr) {
		// Cannot connect to X server
		return false;
	}

	GLint attribs[] = {
		GLX_X_RENDERABLE, True,
		GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
		GLX_RENDER_TYPE, GLX_RGBA_BIT,
		GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
		GLX_RED_SIZE, 8,
		GLX_GREEN_SIZE, 8,
		GLX_BLUE_SIZE, 8,
		GLX_ALPHA_SIZE, 8,
		GLX_DEPTH_SIZE, 24,
		GLX_STENCIL_SIZE, 8,
		GLX_DOUBLEBUFFER, True,
		//GLX_SAMPLE_BUFFERS, 1,
		//GLX_SAMPLES, 4,
		None
	};

	int glx_major, glx_minor;

	// FBConfigs were added in GLX version 1.3.
	if (!glXQueryVersion(m_pDisplay, &glx_major, &glx_minor) || ((glx_major == 1) && (glx_minor < 3)) || (glx_major < 1)) {
		printf("Invalid GLX version");
		return false;
	}

	printf("Getting matching framebuffer configs\n");
	int fbcount;
	GLXFBConfig* fbc = glXChooseFBConfig(m_pDisplay, DefaultScreen(m_pDisplay), attribs, &fbcount);
	if (!fbc) {
		printf("Failed to retrieve a framebuffer config\n");
		return false;
	}
	printf("Found %d matching FB configs.\n", fbcount);

	// Pick the FB config/visual with the most samples per pixel
	printf("Getting XVisualInfos\n");
	int best_fbc = -1, worst_fbc = -1, best_num_samp = -1, worst_num_samp = 999;

	int i;
	for (i = 0; i < fbcount; ++i) {
		XVisualInfo* vi = glXGetVisualFromFBConfig(m_pDisplay, fbc[i]);
		if (vi) {
			int samp_buf, samples;
			glXGetFBConfigAttrib(m_pDisplay, fbc[i], GLX_SAMPLE_BUFFERS, &samp_buf);
			glXGetFBConfigAttrib(m_pDisplay, fbc[i], GLX_SAMPLES, &samples);

			printf("  Matching fbconfig %d, visual ID 0x%2x: SAMPLE_BUFFERS = %d,"
				" SAMPLES = %d\n",
				i, vi->visualid, samp_buf, samples);

			if (best_fbc < 0 || samp_buf && samples > best_num_samp)
				best_fbc = i, best_num_samp = samples;
			if (worst_fbc < 0 || !samp_buf || samples < worst_num_samp)
				worst_fbc = i, worst_num_samp = samples;
		}
		XFree(vi);
	}

	GLXFBConfig bestFbc = fbc[best_fbc];

	// Be sure to free the FBConfig list allocated by glXChooseFBConfig()
	XFree(fbc);

	// Get a visual
	XVisualInfo* vi = glXGetVisualFromFBConfig(m_pDisplay, bestFbc);

	//m_root = DefaultRootWindow(m_pDisplay);

	printf("Creating colormap\n");
	XSetWindowAttributes swa;
	//Colormap cmap;
	swa.colormap = XCreateColormap(m_pDisplay, RootWindow(m_pDisplay, vi->screen), vi->visual, AllocNone);
	swa.background_pixmap = None;
	swa.border_pixel = 0;
	swa.event_mask = StructureNotifyMask | ExposureMask | KeyPressMask;

	printf("Creating window\n");
	m_window = XCreateWindow(m_pDisplay, RootWindow(m_pDisplay, vi->screen), 0, 0, width, height, 0, vi->depth, InputOutput, vi->visual, CWBorderPixel | CWColormap | CWEventMask, &swa);

	if (!m_window) {
		printf("Failed to create window.\n");
		return false;
	}

	// Done with the visual info data
	XFree(vi);

	XStoreName(m_pDisplay, m_window, title);
	m_title = title;

	XSelectInput(m_pDisplay, m_window,
		ExposureMask | PointerMotionMask | ButtonPressMask | ButtonReleaseMask | EnterWindowMask | LeaveWindowMask | KeyPressMask | KeyReleaseMask | FocusChangeMask);

	XMapWindow(m_pDisplay, m_window);

	// Get the default screen's GLX extension list
	const char* glxExts = glXQueryExtensionsString(m_pDisplay,
		DefaultScreen(m_pDisplay));

	// NOTE: It is not necessary to create or make current to a context before
	// calling glXGetProcAddressARB
	glXCreateContextAttribsARBProc glXCreateContextAttribsARB = 0;
	glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc)
		glXGetProcAddressARB((const GLubyte*)"glXCreateContextAttribsARB");

	// Install an X error handler so the application won't exit if GL 3.0
	// context allocation fails.
	//
	// Note this error handler is global.  All display connections in all threads
	// of a process use the same error handler, so be sure to guard against other
	// threads issuing X commands while this code is running.
	ctxErrorOccurred = false;
	int (*oldHandler)(Display*, XErrorEvent*) = XSetErrorHandler(&ctxErrorHandler);

	// Check for the GLX_ARB_create_context extension string and the function.
	// If either is not present, use GLX 1.3 context creation method.
	if (!isExtensionSupported(glxExts, "GLX_ARB_create_context") || !glXCreateContextAttribsARB) {
		printf("glXCreateContextAttribsARB() not found"
			" ... using old-style GLX context\n");
		m_context = glXCreateNewContext(m_pDisplay, bestFbc, GLX_RGBA_TYPE, 0, True);
	}

	// If it does, try to get a GL context!
	else {
		int context_attribs[] = {
			GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
			GLX_CONTEXT_MINOR_VERSION_ARB, 3,
			GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
			//GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
			None
		};

		printf("Creating context\n");
		m_context = glXCreateContextAttribsARB(m_pDisplay, bestFbc, 0,
			True, context_attribs);

		// Sync to ensure any errors generated are processed.
		XSync(m_pDisplay, False);
		if (!ctxErrorOccurred && m_context)
			printf("Created GL context\n");
		else {
			// Couldn't create GL context. Fall back to old-style 2.x context.
			// When a context version below 3.0 is requested, implementations will
			// return the newest context version compatible with OpenGL versions less
			// than version.
			// GLX_CONTEXT_MAJOR_VERSION_ARB = 1
			context_attribs[1] = 1;
			// GLX_CONTEXT_MINOR_VERSION_ARB = 0
			context_attribs[3] = 0;

			ctxErrorOccurred = false;

			printf("Failed to create GL context ... using old-style GLX context\n");
			m_context = glXCreateContextAttribsARB(m_pDisplay, bestFbc, 0,
				True, context_attribs);
		}
	}

	// Sync to ensure any errors generated are processed.
	XSync(m_pDisplay, False);

	// Restore the original error handler
	XSetErrorHandler(oldHandler);

	if (ctxErrorOccurred || !m_context) {
		printf("Failed to create an OpenGL context\n");
		return false;
	}

	// Verifying that context is a direct context
	if (!glXIsDirect(m_pDisplay, m_context)) {
		printf("Indirect GLX rendering context obtained\n");
	}
	else {
		printf("Direct GLX rendering context obtained\n");
	}

	glXMakeCurrent(m_pDisplay, m_window, m_context);

	m_wmDeleteMessage = XInternAtom(m_pDisplay, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(m_pDisplay, m_window, &m_wmDeleteMessage, 1);

	m_shouldClose = false;

	return true;
}

void x11_window_t::close()
{
	glXMakeCurrent(m_pDisplay, None, NULL);
	glXDestroyContext(m_pDisplay, m_context);
	XDestroyWindow(m_pDisplay, m_window);
	//XFreeColormap(display, cmap);
	XCloseDisplay(m_pDisplay);
}

void x11_window_t::pollEvents()
{
	while (!m_shouldClose && XPending(m_pDisplay)) {
		XNextEvent(m_pDisplay, &m_event);

		switch (m_event.type) {
		case Expose:
			XGetWindowAttributes(m_pDisplay, m_window, &m_attribs);
			break;

		case ButtonPress:
			switch (m_event.xbutton.button) {
			case Button1:
				if (m_mouse_btn_fn) {
					m_mouse_btn_fn(this, BUTTON_1, BUTTON_PRESSED, 0);
				}
				break;
			case Button2:
				if (m_mouse_btn_fn) {
					m_mouse_btn_fn(this, BUTTON_2, BUTTON_PRESSED, 0);
				}
				break;
			case Button3:
				if (m_mouse_btn_fn) {
					m_mouse_btn_fn(this, BUTTON_3, BUTTON_PRESSED, 0);
				}
				break;
			case Button4:
				if (m_scroll_fn) {
					m_scroll_fn(this, 0, 100);
				}
				break;
			case Button5:
				if (m_scroll_fn) {
					m_scroll_fn(this, 0, -100);
				}
				break;
			}
			break;

		case ButtonRelease:
			switch (m_event.xbutton.button) {
			case Button1:
				if (m_mouse_btn_fn) {
					m_mouse_btn_fn(this, BUTTON_1, BUTTON_RELEASED, 0);
				}
				break;
			case Button2:
				if (m_mouse_btn_fn) {
					m_mouse_btn_fn(this, BUTTON_2, BUTTON_RELEASED, 0);
				}
				break;
			case Button3:
				if (m_mouse_btn_fn) {
					m_mouse_btn_fn(this, BUTTON_3, BUTTON_RELEASED, 0);
				}
				break;
			case Button4:
				if (m_scroll_fn) {
					m_scroll_fn(this, 0, 100);
				}
				break;
			case Button5:
				if (m_scroll_fn) {
					m_scroll_fn(this, 0, -100);
				}
				break;
			}
			break;

		case MotionNotify:
			if (m_cursor_pos_fn) {
				m_cursor_pos_fn(this, m_event.xmotion.x, m_event.xmotion.y);
			}
			break;

		case EnterNotify:
			if (m_cursor_enter_fn) {
				m_cursor_enter_fn(this, true);
			}
			break;

		case LeaveNotify:
			if (m_cursor_enter_fn) {
				m_cursor_enter_fn(this, false);
			}
			break;

		case FocusIn:
			if (m_focus_fn) {
				m_focus_fn(this, true);
			}
			break;

		case FocusOut:
			if (m_focus_fn) {
				m_focus_fn(this, false);
			}
			break;

		case KeyPress:
			if (m_key_fn) {
				m_key_fn(this, m_event.xkey.keycode, 0, KEY_PRESSED, 0);
			}
			break;

		case KeyRelease:
			if (m_key_fn) {
				m_key_fn(this, m_event.xkey.keycode, 0, KEY_RELEASED, 0);
			}
			break;

		case ClientMessage:
			if (m_event.xclient.data.l[0] == (long int)m_wmDeleteMessage) {
				if (m_close_fn) {
					m_close_fn(this);
				}
				m_shouldClose = true;
				close();
			}
			break;
		}
	}
}

void x11_window_t::swapBuffers()
{
	glXSwapBuffers(m_pDisplay, m_window);
}

bool x11_window_t::shouldClose()
{
	return m_shouldClose;
}

void x11_window_t::setTitle(const char* title)
{
	XStoreName(m_pDisplay, m_window, title);
	m_title = title;
}

void x11_window_t::setSize(u32 width, u32 height)
{
	XMoveResizeWindow(m_pDisplay, m_window, 0, 0, width, height);
}

const char* x11_window_t::getTitle()
{
	return m_title;
}

void x11_window_t::getSize(u32& width, u32& height)
{
	width = m_attribs.width;
	height = m_attribs.height;
}