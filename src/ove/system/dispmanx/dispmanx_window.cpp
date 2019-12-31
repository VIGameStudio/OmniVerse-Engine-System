#include "dispmanx_window.hpp"

#include <iostream>
#include <GLES2/gl2.h>

using namespace ove;
using namespace core;
using namespace system;

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

bool dispmanx_window_t::create(const char* title, u32 width, u32 height)
{
	m_title = title;

	bcm_host_init();

	// Initialize Dispmanx.
	DISPMANX_ELEMENT_HANDLE_T dispman_element;
	DISPMANX_DISPLAY_HANDLE_T dispman_display;
	DISPMANX_UPDATE_HANDLE_T dispman_update;
	VC_RECT_T dst_rect;
	VC_RECT_T src_rect;

	// Fullscreen
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

	EGLConfig config;
	EGLint num_config;

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
	if (eglChooseConfig(m_display, attribute_list, &config, 1, &num_config) != EGL_TRUE)
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
	m_context = eglCreateContext(m_display, config, EGL_NO_CONTEXT, context_attributes);
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

	m_surface = eglCreateWindowSurface(m_display, config, &m_window, NULL);
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
	return nullptr;
}

void dispmanx_window_t::getSize(u32& width, u32& height)
{
}