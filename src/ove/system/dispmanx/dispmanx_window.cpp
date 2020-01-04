#include "dispmanx_window.hpp"

#include <ove/system/input.hpp>

#include <iostream>
#include <GLES2/gl2.h>

//#include <stdio.h>
//#include <unistd.h>
//#include <errno.h>

#include <dirent.h>
#include <regex.h>
#include <fcntl.h>
#include <linux/input.h>

using namespace ove::core;
using namespace ove::system;

dispmanx_window_t::dispmanx_window_t()
{
}

dispmanx_window_t::~dispmanx_window_t()
{
	eglDestroyContext(m_display, m_context);
	eglDestroySurface(m_display, m_surface);
	eglTerminate(m_display);
}

static const char* eglGetErrorStr();

bool dispmanx_window_t::create(const window_config_t& config)
{
	m_title = config.title;

	bcm_host_init();

	// Initialize Dispmanx.
	DISPMANX_ELEMENT_HANDLE_T dispman_element;
	DISPMANX_DISPLAY_HANDLE_T dispman_display;
	DISPMANX_UPDATE_HANDLE_T dispman_update;
	VC_RECT_T dst_rect;
	VC_RECT_T src_rect;

	u32 width, height;
	if (graphics_get_display_size(0, &width, &height) < 0)
	{
		std::cerr << "Failed to get display size!" << std::endl;
		return false;
	}

	dst_rect.x = 0;
	dst_rect.y = 0;
	dst_rect.width = width;
	dst_rect.height = height;

	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.width = width << 16;
	src_rect.height = height << 16;

	dispman_display = vc_dispmanx_display_open(0); // LCD
	dispman_update = vc_dispmanx_update_start(0);
	dispman_element = vc_dispmanx_element_add(
		dispman_update,
		dispman_display,
		0, &dst_rect,
		0, &src_rect,
		DISPMANX_PROTECTION_NONE,
		0, 0,
		DISPMANX_NO_ROTATE);

	// Initialize EGL.
	static const EGLint attribute_list[] =
	{
		EGL_RED_SIZE, 8,
		EGL_GREEN_SIZE, 8,
		EGL_BLUE_SIZE, 8,
		EGL_ALPHA_SIZE, 8,
		EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
		EGL_NONE
	};

	static const EGLint context_attributes[] =
	{
		EGL_CONTEXT_CLIENT_VERSION, 2,
		EGL_NONE
	};

	EGLConfig eglConfig;
	EGLint elgNumConfig;

	// Get an EGL display connection.
	m_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	if (m_display == EGL_NO_DISPLAY)
	{
		std::cerr << "Failed to get EGL display! Error: " << eglGetErrorStr() << std::endl;
		return false;
	}

	int major, minor;

	// Initialize the EGL display connection.
	if (eglInitialize(m_display, &major, &minor) != EGL_TRUE)
	{
		std::cerr << "Failed to initialize EGL! Error: " << eglGetErrorStr() << std::endl;
		eglTerminate(m_display);
		return false;
	}

	std::cout << "Initialized EGL version: " << major << "." << minor << std::endl;

	// Get an appropriate EGL frame buffer configuration.
	if (eglChooseConfig(m_display, attribute_list, &eglConfig, 1, &elgNumConfig) != EGL_TRUE)
	{
		std::cerr << "Failed to configure EGL!" << std::endl;
		eglTerminate(m_display);
		return false;
	}

	// Get an appropriate EGL frame buffer configuration.
	if (eglBindAPI(EGL_OPENGL_ES_API) != EGL_TRUE)
	{
		std::cerr << "Failed to bind EGL API!" << std::endl;
		eglTerminate(m_display);
		return false;
	}

	// Create an EGL rendering context.
	m_context = eglCreateContext(m_display, eglConfig, EGL_NO_CONTEXT, context_attributes);
	if (m_context == EGL_NO_CONTEXT)
	{
		std::cerr << "Failed to create EGL context!" << std::endl;
		eglDestroyContext(m_display, m_context);
		eglTerminate(m_display);
		return false;
	}

	// Link the Dispmanx window to the EGL window surface.
	m_window.element = dispman_element;
	m_window.width = width;
	m_window.height = height;
	vc_dispmanx_update_submit_sync(dispman_update);

	m_surface = eglCreateWindowSurface(m_display, eglConfig, &m_window, NULL);
	if (m_surface == EGL_NO_SURFACE)
	{
		std::cerr << "Failed to create EGL surface!" << std::endl;
		eglDestroySurface(m_display, m_surface);
		eglTerminate(m_display);
		return false;
	}

	// Connect the context to the surface.
	if (eglMakeCurrent(m_display, m_surface, m_surface, m_context) != EGL_TRUE)
	{
		std::cerr << "Failed to bind EGL context!" << std::endl;
		eglDestroySurface(m_display, m_surface);
		eglTerminate(m_display);
		return false;
	}

	m_shouldClose = false;

	return true;
}

static const char* eglGetErrorStr()
{
	switch (eglGetError())
	{
	case EGL_SUCCESS:
		return "The last function succeeded without error.";
	case EGL_NOT_INITIALIZED:
		return "EGL is not initialized, or could not be initialized, for the specified EGL display connection.";
	case EGL_BAD_ACCESS:
		return "EGL cannot access a requested resource (for example a context is bound in another thread).";
	case EGL_BAD_ALLOC:
		return "EGL failed to allocate resources for the requested operation.";
	case EGL_BAD_ATTRIBUTE:
		return "An unrecognized attribute or attribute value was passed in the attribute list.";
	case EGL_BAD_CONTEXT:
		return "An EGLContext argument does not name a valid EGL rendering context.";
	case EGL_BAD_CONFIG:
		return "An EGLConfig argument does not name a valid EGL frame buffer configuration.";
	case EGL_BAD_CURRENT_SURFACE:
		return "The current surface of the calling thread is a window, pixel buffer or pixmap that is no longer valid.";
	case EGL_BAD_DISPLAY:
		return "An EGLDisplay argument does not name a valid EGL display connection.";
	case EGL_BAD_SURFACE:
		return "An EGLSurface argument does not name a valid surface (window, pixel buffer or pixmap) configured for GL rendering.";
	case EGL_BAD_MATCH:
		return "Arguments are inconsistent (for example, a valid context requires buffers not supplied by a valid surface).";
	case EGL_BAD_PARAMETER:
		return "One or more argument values are invalid.";
	case EGL_BAD_NATIVE_PIXMAP:
		return "A NativePixmapType argument does not refer to a valid native pixmap.";
	case EGL_BAD_NATIVE_WINDOW:
		return "A NativeWindowType argument does not refer to a valid native window.";
	case EGL_CONTEXT_LOST:
		return "A power management event has occurred. The application must destroy all contexts and reinitialise OpenGL ES state and objects to continue rendering.";
	default:
		break;
	}
	return "Unknown error!";
}

void dispmanx_window_t::close()
{
	m_shouldClose = true;
}

bool dispmanx_window_t::shouldClose()
{
	return m_shouldClose;
}

void dispmanx_window_t::pollEvents()
{
	// http://www.peteronion.org.uk/PiProgs/input.c

	//static int first = 1;
	//static int mouseFd = -1;
	//static int keyboardFd = -1;
	//struct input_event ev[64];
	//int rd;

	//// Set up the devices on the first call
	//if (first)
	//{
	//	DIR* dirp;
	//	struct dirent* dp;
	//	regex_t kbd, mouse;

	//	char fullPath[1024];
	//	static const char* dirName = "/dev/input";
	//	int result;

	//	if (regcomp(&kbd, "event-kbd", 0) != 0)
	//	{
	//		printf("regcomp for kbd failed\n");
	//		m_shouldClose = true;
	//		return;
	//	}

	//	if (regcomp(&mouse, "event-mouse", 0) != 0)
	//	{
	//		printf("regcomp for mouse failed\n");
	//		m_shouldClose = true;
	//		return;
	//	}

	//	if ((dirp = opendir(dirName)) == NULL) {
	//		perror("couldn't open '/dev/input/by-id'");
	//		m_shouldClose = true;
	//		return;
	//	}

	//	// Find any files that match the regex for keyboard or mouse
	//	do
	//	{
	//		if ((dp = readdir(dirp)) != NULL)
	//		{
	//			//printf("readdir (%s)\n", dp->d_name);
	//			if (regexec(&kbd, dp->d_name, 0, NULL, 0) == 0)
	//			{
	//				printf("match for the kbd = %s\n", dp->d_name);
	//				sprintf(fullPath, "%s/%s", dirName, dp->d_name);
	//				keyboardFd = open(fullPath, O_RDONLY | O_NONBLOCK);
	//				printf("%s Fd = %d\n", fullPath, keyboardFd);
	//				printf("Getting exclusive access: ");
	//				result = ioctl(keyboardFd, EVIOCGRAB, 1);
	//				printf("%s\n", (result == 0) ? "SUCCESS" : "FAILURE");
	//			}
	//			if (regexec(&mouse, dp->d_name, 0, NULL, 0) == 0)
	//			{
	//				printf("match for the kbd = %s\n", dp->d_name);
	//				sprintf(fullPath, "%s/%s", dirName, dp->d_name);
	//				mouseFd = open(fullPath, O_RDONLY | O_NONBLOCK);
	//				printf("%s Fd = %d\n", fullPath, mouseFd);
	//				printf("Getting exclusive access: ");
	//				result = ioctl(mouseFd, EVIOCGRAB, 1);
	//				printf("%s\n", (result == 0) ? "SUCCESS" : "FAILURE");
	//			}
	//		}
	//	} while (dp != NULL);

	//	closedir(dirp);

	//	regfree(&kbd);
	//	regfree(&mouse);

	//	first = 0;
	//	if ((keyboardFd == -1) || (mouseFd == -1))
	//	{
	//		printf("pollevents failed\n");
	//		m_shouldClose = true;
	//		return;
	//	}
	//}

	//// Read events from mouse
	//rd = read(mouseFd, ev, sizeof(ev));
	//if (rd > 0)
	//{
	//	int count, n;
	//	struct input_event* evp;

	//	count = rd / sizeof(struct input_event);
	//	n = 0;
	//	while (count--)
	//	{
	//		evp = &ev[n++];
	//		if (evp->type == 1)
	//		{
	//			switch (evp->code)
	//			{
	//			case BTN_LEFT:
	//				m_buttons[MBTN_LEFT] = evp->value;
	//				break;

	//			case BTN_MIDDLE:
	//				m_buttons[MBTN_MIDDLE] = evp->value;
	//				break;

	//			case BTN_RIGHT:
	//				m_buttons[MBTN_RIGHT] = evp->value;
	//				break;
	//			}
	//		}

	//		if (evp->type == 2)
	//		{
	//			if (evp->code == 0)
	//			{
	//				// Mouse Left/Right
	//				printf("Mouse moved left/right %d\n", evp->value);
	//			}

	//			if (evp->code == 1)
	//			{
	//				// Mouse Up/Down
	//				printf("Mouse moved up/down %d\n", evp->value);
	//			}
	//		}
	//	}
	//}

	//// Read events from keyboard
	//rd = read(keyboardFd, ev, sizeof(ev));
	//if (rd > 0)
	//{
	//	int count, n;
	//	struct input_event* evp;

	//	count = rd / sizeof(struct input_event);
	//	n = 0;
	//	while (count--)
	//	{
	//		evp = &ev[n++];
	//		if (evp->type == 1)
	//		{
	//			if (evp->value == 1)
	//			{
	//				if (evp->code == KEY_LEFTCTRL)
	//				{
	//					printf("Left Control key pressed\n");
	//				}
	//				if (evp->code == KEY_LEFTMETA)
	//				{
	//					printf("Left Meta key pressed\n");
	//				}
	//				if (evp->code == KEY_LEFTSHIFT)
	//				{
	//					printf("Left Shift key pressed\n");
	//				}
	//			}

	//			/*if ((evp->code == KEY_Q) && (evp->value == 1))
	//			{
	//				m_shouldClose = true;
	//				return;
	//			}*/
	//		}
	//	}
	//}
}

void dispmanx_window_t::swapBuffers()
{
	eglSwapBuffers(m_display, m_surface);
}

void dispmanx_window_t::setTitle(const char* title)
{
}

void dispmanx_window_t::setSize(u32 width, u32 height)
{
}

const char* dispmanx_window_t::getTitle()
{
	return m_title.c_str();
}

void dispmanx_window_t::getSize(u32& width, u32& height)
{
	graphics_get_display_size(0, &width, &height);
}