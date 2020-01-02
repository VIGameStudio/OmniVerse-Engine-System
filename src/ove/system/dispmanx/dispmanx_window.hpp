#pragma once

#include <ove/system/window.hpp>

#include <bcm_host.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>

namespace ove
{
	namespace system
	{
		struct dispmanx_window_t : public window_t
		{
		public:
			dispmanx_window_t();
			~dispmanx_window_t();

			virtual bool create(const window_config_t& config);

			virtual void close();

			virtual bool shouldClose();

			virtual void pollEvents();

			virtual void swapBuffers();

			virtual void setTitle(const char* title);

			virtual void setSize(core::u32 width, core::u32 height);

			virtual const char* getTitle();

			virtual void getSize(core::u32& width, core::u32& height);

		private:
			EGLDisplay m_display;
			EGLContext m_context;
			EGLSurface m_surface;
			EGL_DISPMANX_WINDOW_T m_window;

			std::string m_title;
			bool m_shouldClose;
		};
	}
}