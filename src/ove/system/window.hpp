#pragma once

#include <ove/system/input.hpp>
#include <ove/core/util/types.hpp>

#include <string>
#include <functional>

namespace ove
{
	namespace system
	{
		struct window_config_t
		{
			std::string title = "";
			core::u32 x = 0;
			core::u32 y = 0;
			core::u32 width = 0;
			core::u32 height = 0;
			bool vsync = false;
			core::u8 msaa = 0;
		};

		struct input_receiver_t
		{
		protected:
			virtual void onWindowClose(struct window_t* pWin) = 0;

			virtual void onWindowFocus(struct window_t* pWin, bool focused) = 0;

			virtual void onWindowSize(struct window_t* pWin, core::u32 w, core::u32 h) = 0;

			virtual void onWindowPos(struct window_t* pWin, core::u32 xpos, core::u32 ypos) = 0;

			virtual void onWindowMouseBtn(struct window_t* pWin, core::u8 button, bool pressed) = 0;

			virtual void onWindowCursorPos(struct window_t* pWin, core::f64 xpos, core::f64 ypos) = 0;

			virtual void onWindowCursorEnter(struct window_t* pWin, bool entered) = 0;

			virtual void onWindowScroll(struct window_t* pWin, core::f64 dx, core::f64 dy) = 0;

			virtual void onWindowKey(struct window_t* pWin, core::u8 key, bool pressed) = 0;

			virtual void onWindowChar(struct window_t* pWin, core::u32 c) = 0;
		};

		struct window_t
		{
		public:
			using window_close_fn = std::function<void(window_t * pWin)>;

			using window_focus_fn = std::function<void(window_t * pWin, bool focused)>;

			using window_size_fn = std::function<void(window_t * pWin, core::u32 w, core::u32 h)>;

			using window_pos_fn = std::function<void(window_t * pWin, core::u32 xpos, core::u32 ypos)>;

			using window_mouse_btn_fn = std::function<void(window_t*, core::u8 button, bool pressed)>;

			using window_cursor_pos_fn = std::function<void(window_t * pWin, core::f64 xpos, core::f64 ypos)>;

			using window_cursor_enter_fn = std::function<void(window_t * pWin, bool entered)>;

			using window_scroll_fn = std::function<void(window_t * pWin, core::f64 dx, core::f64 dy)>;

			using window_key_fn = std::function<void(window_t * pWin, core::u8 key, bool pressed)>;

			using window_char_fn = std::function<void(window_t * pWin, core::u32 c)>;

		public:
			virtual bool create(const window_config_t& config) = 0;

			virtual void close() = 0;

			virtual bool shouldClose() = 0;

			virtual void pollEvents() = 0;

			virtual void swapBuffers() = 0;

			virtual void setTitle(const char* title) = 0;

			virtual void setSize(core::u32 width, core::u32 height) = 0;

			virtual const char* getTitle() const = 0;

			virtual void getSize(core::u32& width, core::u32& height) const = 0;

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

			inline bool isKeyDown(core::u16 keycode) const { return m_keys[keycode]; }

			inline bool isButtonDown(core::u8 button) const { return m_buttons[button]; }

			inline void getMousePos(core::i32& x, core::i32& y) const { x = m_mouseX; y = m_mouseY; }

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

			core::u8 m_keys[KEYS_STATE_MAXSIZE] = { 0 };

			core::u8 m_buttons[BUTTON_STATE_MAXSIZE] = { 0 };

			core::i32 m_mouseX = 0;

			core::i32 m_mouseY = 0;
		};
	}
}