#pragma once

#include <ove/system/window.hpp>
#include <windows.h>

namespace ove
{
	namespace system
	{
		struct win_window_t : public window_t {
		public:
			win_window_t();
			~win_window_t();

			virtual bool create(const window_config_t& config) override;

			virtual void close() override;

			virtual bool shouldClose() override;

			virtual void pollEvents() override;

			virtual void swapBuffers() override;

			virtual void setTitle(const char* title) override;

			virtual void setSize(core::u32 width, core::u32 height) override;

			virtual const char* getTitle() const override;

			virtual void getSize(core::u32& width, core::u32& height) const override;

			virtual void setMousePos(core::i32 x, core::i32 y) override;

			virtual cursor_t* loadCursor() override;

			virtual cursor_t* loadSystemCursor(core::u8 type) override;

			virtual void setCursor(cursor_t* cursor) override;

			virtual void setInputMode(core::u8 target, core::u8 mode) override;

			virtual core::u8 getInputMode(core::u8 target) override;

			virtual const char* getClipboardString() override;

			virtual void setClipboardString(const char* text) override;

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