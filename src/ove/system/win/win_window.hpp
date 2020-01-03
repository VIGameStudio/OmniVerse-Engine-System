#pragma once

#include <ove/system/window.hpp>
#include <windows.h>

namespace ove {
	namespace system {
		struct win_window_t : public window_t {
		public:
			win_window_t();
			~win_window_t();

			virtual bool create(const window_config_t& config);

			virtual void close();

			virtual bool shouldClose();

			virtual void pollEvents();

			virtual void swapBuffers();

			virtual void setTitle(const char* title);

			virtual void setSize(core::u32 width, core::u32 height);

			virtual const char* getTitle();

			virtual void getSize(core::u32& width, core::u32& height);

		public:
			LONG WINAPI wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		private:
			HWND m_windowHandle;
			HDC m_deviceContext;
			HGLRC m_glContext;

			std::string m_title;
			bool m_shouldClose;
		};
	}
}