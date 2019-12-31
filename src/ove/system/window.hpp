#pragma once

#include <ove/system/input.hpp>
#include <ove/core/util/types.hpp>

namespace ove {
	namespace system {
		struct window_t {
		public:
			typedef void (*window_close_fn)(window_t* win);

			typedef void (*window_focus_fn)(window_t* win, bool focused);

			typedef void (*window_size_fn)(window_t* win, core::u32 w, core::u32 h);

			typedef void (*window_pos_fn)(window_t* win, core::u32 xpos, core::u32 ypos);

			typedef void (*window_mouse_btn_fn)(window_t* win, core::i32 button, core::i32 action, core::i32 mods);

			typedef void (*window_cursor_pos_fn)(window_t* win, core::f64 xpos, core::f64 ypos);

			typedef void (*window_cursor_enter_fn)(window_t* win, bool entered);

			typedef void (*window_scroll_fn)(window_t* win, core::f64 xoff, core::f64 yoff);

			typedef void (*window_key_fn)(window_t* win, core::i32 key, core::i32 scanCode, core::i32 action, core::i32 mods);

			typedef void (*window_char_fn)(window_t* win, core::u32 c);

		public:
			virtual bool create(const char* title, core::u32 width, core::u32 height) = 0;

			virtual void close() = 0;

			virtual bool shouldClose() = 0;

			virtual void pollEvents() = 0;

			virtual void swapBuffers() = 0;

			virtual void setTitle(const char* title) = 0;

			virtual void setSize(core::u32 width, core::u32 height) = 0;

			virtual const char* getTitle() = 0;

			virtual void getSize(core::u32& width, core::u32& height) = 0;

		public:
			void setCloseCallback(window_close_fn callback);

			void setFocusCallback(window_focus_fn callback);

			void setSizeCallback(window_size_fn callback);

			void setPositionCallback(window_pos_fn callback);

			void setMouseButtonCallback(window_mouse_btn_fn callback);

			void setCursorPosCallback(window_cursor_pos_fn callback);

			void setCursorEnterCallback(window_cursor_enter_fn callback);

			void setScrollCallback(window_scroll_fn callback);

			void setKeyCallback(window_key_fn callback);

			void setCharCallback(window_char_fn callback);

		protected:
			window_close_fn m_close_fn;

			window_focus_fn m_focus_fn;

			window_size_fn m_size_fn;

			window_pos_fn m_pos_fn;

			window_mouse_btn_fn m_mouse_btn_fn;

			window_cursor_pos_fn m_cursor_pos_fn;

			window_cursor_enter_fn m_cursor_enter_fn;

			window_scroll_fn m_scroll_fn;

			window_key_fn m_key_fn;

			window_char_fn m_char_fn;
		};
	}
}