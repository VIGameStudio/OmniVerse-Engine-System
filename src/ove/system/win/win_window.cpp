#include "win_window.hpp"

#include <ove/system/input.hpp>
#include <ove/system/win/win_input.hpp>

#include <iostream>
#include <array>

//#include <gl/GL.h>
#include <glad/glad.h>
//#include <glad/glad_wgl.h>

//#include <d3d11.h>

using namespace ove::core;
using namespace ove::system;

std::array<u8, 0xff> createKeycodeMap()
{
	std::array<u8, 0xff> map;
	for (size_t i = 0; i < 0xff; ++i)
	{
		map[i] = KB_NONE;
	}

	map[WIN_KB_A] = KB_A;
	map[WIN_KB_B] = KB_B;
	map[WIN_KB_C] = KB_C;
	map[WIN_KB_D] = KB_D;
	map[WIN_KB_E] = KB_E;
	map[WIN_KB_F] = KB_F;
	map[WIN_KB_G] = KB_G;
	map[WIN_KB_H] = KB_H;
	map[WIN_KB_I] = KB_I;
	map[WIN_KB_J] = KB_J;
	map[WIN_KB_K] = KB_K;
	map[WIN_KB_L] = KB_L;
	map[WIN_KB_M] = KB_M;
	map[WIN_KB_N] = KB_N;
	map[WIN_KB_O] = KB_O;
	map[WIN_KB_P] = KB_P;
	map[WIN_KB_Q] = KB_Q;
	map[WIN_KB_R] = KB_R;
	map[WIN_KB_S] = KB_S;
	map[WIN_KB_T] = KB_T;
	map[WIN_KB_U] = KB_U;
	map[WIN_KB_V] = KB_V;
	map[WIN_KB_W] = KB_W;
	map[WIN_KB_X] = KB_X;
	map[WIN_KB_Y] = KB_Y;
	map[WIN_KB_Z] = KB_Z;

	map[WIN_KB_0] = KB_0;
	map[WIN_KB_1] = KB_1;
	map[WIN_KB_2] = KB_2;
	map[WIN_KB_3] = KB_3;
	map[WIN_KB_4] = KB_4;
	map[WIN_KB_5] = KB_5;
	map[WIN_KB_6] = KB_6;
	map[WIN_KB_7] = KB_7;
	map[WIN_KB_8] = KB_8;
	map[WIN_KB_9] = KB_9;

	map[WIN_KB_ENTER] = KB_ENTER;
	map[WIN_KB_ESCAPE] = KB_ESCAPE;
	map[WIN_KB_BACKSPACE] = KB_BACKSPACE;
	map[WIN_KB_TAB] = KB_TAB;
	map[WIN_KB_SPACE] = KB_SPACE;
	map[WIN_KB_MINUS] = KB_MINUS;
	map[WIN_KB_EQUAL] = KB_EQUAL;
	map[WIN_KB_LEFTBRACE] = KB_LEFTBRACE;
	map[WIN_KB_RRIGHTBRACE] = KB_RRIGHTBRACE;
	map[WIN_KB_BACKSLASH] = KB_BACKSLASH;
	map[WIN_KB_HASHTILDE] = KB_HASHTILDE;
	map[WIN_KB_SEMICOLON] = KB_SEMICOLON;
	map[WIN_KB_APOSTROPHE] = KB_APOSTROPHE;
	map[WIN_KB_GRAVE] = KB_GRAVE;
	map[WIN_KB_COMMA] = KB_COMMA;
	map[WIN_KB_DOT] = KB_DOT;
	map[WIN_KB_SLASH] = KB_SLASH;
	map[WIN_KB_CAPSLOCK] = KB_CAPSLOCK;

	map[WIN_KB_F1] = KB_F1;
	map[WIN_KB_F2] = KB_F2;
	map[WIN_KB_F3] = KB_F3;
	map[WIN_KB_F4] = KB_F4;
	map[WIN_KB_F5] = KB_F5;
	map[WIN_KB_F6] = KB_F6;
	map[WIN_KB_F7] = KB_F7;
	map[WIN_KB_F8] = KB_F8;
	map[WIN_KB_F9] = KB_F9;
	map[WIN_KB_F10] = KB_F10;
	map[WIN_KB_F11] = KB_F11;
	map[WIN_KB_F12] = KB_F12;
	map[WIN_KB_SYSRQ] = KB_SYSRQ;
	map[WIN_KB_SCROLLLOCK] = KB_SCROLLLOCK;
	map[WIN_KB_PAUSE] = KB_PAUSE;
	map[WIN_KB_INSERT] = KB_INSERT;
	map[WIN_KB_HOME] = KB_HOME;
	map[WIN_KB_PAGEUP] = KB_PAGEUP;
	map[WIN_KB_DELETE] = KB_DELETE;
	map[WIN_KB_END] = KB_END;
	map[WIN_KB_PAGEDOWN] = KB_PAGEDOWN;

	map[WIN_KB_RIGHT] = KB_RIGHT;
	map[WIN_KB_LEFT] = KB_LEFT;
	map[WIN_KB_DOWN] = KB_DOWN;
	map[WIN_KB_UP] = KB_UP;

	map[WIN_KB_LEFTCTRL] = KB_LEFTCTRL;
	map[WIN_KB_LEFTSHIFT] = KB_LEFTSHIFT;
	map[WIN_KB_LEFTALT] = KB_LEFTALT;
	map[WIN_KB_RIGHTCTRL] = KB_RIGHTCTRL;
	map[WIN_KB_RIGHTSHIFT] = KB_RIGHTSHIFT;
	map[WIN_KB_RIGHTALT] = KB_RIGHTALT;

	return map;
}

u8 convertKeycode(u8 k)
{
	static std::array<u8, 0xff> s_kcmap = createKeycodeMap();
	return s_kcmap[k];
}

win_window_t::win_window_t()
{
	m_windowHandle = NULL;
	m_deviceContext = NULL;
	m_glContext = NULL;

	m_title = "";
	m_shouldClose = true;
}

win_window_t::~win_window_t()
{
	wglMakeCurrent(NULL, NULL);
	ReleaseDC(m_windowHandle, m_deviceContext);
	wglDeleteContext(m_glContext);
	DestroyWindow(m_windowHandle);
}

LONG WINAPI WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool win_window_t::create(const window_config_t& config)
{
	m_title = config.title;

	int pf;
	PIXELFORMATDESCRIPTOR pfd;
	static HINSTANCE hInstance = 0;

	const char* const windowClassStr = "OpenGL";

	// Only register the window class once - use hInstance as a flag.
	if (!hInstance)
	{
		hInstance = GetModuleHandle(NULL);

		WNDCLASSEX wc;
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wc.hInstance = hInstance;
		wc.lpszClassName = windowClassStr;
		wc.lpszMenuName = "";
		wc.style = CS_OWNDC;
		wc.lpfnWndProc = (WNDPROC)WndProc;

		if (!RegisterClassEx(&wc))
		{
			MessageBox(NULL, "RegisterClassEx() failed: Cannot register window class.", "Error", MB_OK);
			return false;
		}
	}

	m_windowHandle = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		windowClassStr,
		config.title.c_str(),
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		config.x, config.y, config.width, config.height,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (!m_windowHandle)
	{
		MessageBox(NULL, "CreateWindow() failed: Cannot create a window.", "Error", MB_OK);
		return false;
	}

	SetWindowLongPtr(m_windowHandle, GWLP_USERDATA, (long)this);

	m_deviceContext = GetDC(m_windowHandle);

	// There is no guarantee that the contents of the stack that become
	// the pfd are zero-ed, therefore make sure to clear these bits.
	memset(&pfd, 0, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;

	pf = ChoosePixelFormat(m_deviceContext, &pfd);
	if (pf == 0)
	{
		MessageBox(NULL, "ChoosePixelFormat() failed: Cannot find a suitable pixel format.", "Error", MB_OK);
		return false;
	}

	if (SetPixelFormat(m_deviceContext, pf, &pfd) == FALSE)
	{
		MessageBox(NULL, "SetPixelFormat() failed: Cannot set format specified.", "Error", MB_OK);
		return false;
	}

	DescribePixelFormat(m_deviceContext, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	/*GLint attribs[] =
	{
		// Here we ask for OpenGL 3.3
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 3,
		// Uncomment this for forward compatibility mode
		//WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		// Uncomment this for Compatibility profile
		//WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
		// We are using Core profile here
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0
	};

	m_glContext = wglCreateContextAttribsARB(m_deviceContext, 0, attribs);*/
	m_glContext = wglCreateContext(m_deviceContext);
	wglMakeCurrent(m_deviceContext, m_glContext);

	if (!gladLoadGL())
	{
		printf("Failed to load glad!\n");
		return false;
	}

	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

	ReleaseDC(m_windowHandle, m_deviceContext);

	ShowWindow(m_windowHandle, SW_SHOWDEFAULT);
	UpdateWindow(m_windowHandle);

	m_shouldClose = false;

	return true;
}

LONG WINAPI WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	win_window_t* win = reinterpret_cast<win_window_t*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	if (win != nullptr)
	{
		return win->wndProc(hWnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LONG WINAPI win_window_t::wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static PAINTSTRUCT ps;

	switch (uMsg)
	{
	case WM_SIZE:
		if (m_size_fn != nullptr)
		{
			m_size_fn(this, LOWORD(lParam), HIWORD(lParam));
		}
		PostMessage(hWnd, WM_PAINT, 0, 0);
		return 0;

	case WM_CHAR:
		if (m_char_fn != nullptr)
		{
			m_char_fn(this, wParam);
		}
		return 0;

	case WM_KEYDOWN:
		m_keys[convertKeycode(wParam)] = true;
		if (m_key_fn != nullptr)
		{
			m_key_fn(this, convertKeycode(wParam), true);
		}
		return 0;

	case WM_KEYUP:
		m_keys[convertKeycode(wParam)] = false;
		if (m_key_fn != nullptr)
		{
			m_key_fn(this, convertKeycode(wParam), false);
		}
		return 0;

	case WM_LBUTTONDOWN:
		m_buttons[MBTN_LEFT] = true;
		if (m_mouse_btn_fn != nullptr)
		{
			m_mouse_btn_fn(this, MBTN_LEFT, true);
		}
		return 0;

	case WM_MBUTTONDOWN:
		m_buttons[MBTN_MIDDLE] = true;
		if (m_mouse_btn_fn != nullptr)
		{
			m_mouse_btn_fn(this, MBTN_MIDDLE, true);
		}
		return 0;

	case WM_RBUTTONDOWN:
		m_buttons[MBTN_RIGHT] = true;
		if (m_mouse_btn_fn != nullptr)
		{
			m_mouse_btn_fn(this, MBTN_RIGHT, true);
		}
		return 0;

	case WM_LBUTTONUP:
		m_buttons[MBTN_LEFT] = false;
		if (m_mouse_btn_fn != nullptr)
		{
			m_mouse_btn_fn(this, MBTN_LEFT, false);
		}
		return 0;

	case WM_MBUTTONUP:
		m_buttons[MBTN_MIDDLE] = false;
		if (m_mouse_btn_fn != nullptr)
		{
			m_mouse_btn_fn(this, MBTN_MIDDLE, false);
		}
		return 0;

	case WM_RBUTTONUP:
		m_buttons[MBTN_RIGHT] = false;
		if (m_mouse_btn_fn != nullptr)
		{
			m_mouse_btn_fn(this, MBTN_RIGHT, false);
		}
		return 0;

	case WM_MOUSEMOVE:
		m_mouseX = LOWORD(lParam);
		m_mouseY = HIWORD(lParam);
		if (m_cursor_pos_fn != nullptr)
		{
			m_cursor_pos_fn(this, m_mouseX, m_mouseY);
		}
		return 0;

	case WM_MOUSEWHEEL:
		if (m_scroll_fn != nullptr)
		{
			m_scroll_fn(this, 0, (((int)wParam) >> 16) / WHEEL_DELTA);
		}
		return 0;

	case WM_CLOSE:
	case WM_DESTROY:
		close();
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void win_window_t::close()
{
	m_shouldClose = true;
	if (m_close_fn != nullptr)
	{
		m_close_fn(this);
	}
}

bool win_window_t::shouldClose()
{
	return m_shouldClose;
}

void win_window_t::pollEvents()
{
	MSG msg;
	while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void win_window_t::swapBuffers()
{
	SwapBuffers(m_deviceContext);
	glFinish();
}

void win_window_t::setTitle(const char* title)
{
	m_title = title;
	SetWindowText(m_windowHandle, title);
}

void win_window_t::setSize(u32 width, u32 height)
{
}

const char* win_window_t::getTitle() const
{
	return m_title.c_str();
}

void win_window_t::getSize(u32& width, u32& height) const
{
	RECT rect;
	if (GetClientRect(m_windowHandle, &rect))
	{
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
	}
}

void win_window_t::setMousePos(i32 x, i32 y)
{
}

cursor_t* win_window_t::loadCursor()
{
	return nullptr;
}

cursor_t* win_window_t::loadSystemCursor(u8 type)
{
	return nullptr;
}

void win_window_t::setCursor(cursor_t* cursor)
{
}

void win_window_t::setInputMode(u8 target, u8 mode)
{
}

u8 win_window_t::getInputMode(u8 target)
{
	return 0;
}

const char* win_window_t::getClipboardString()
{
	if (!OpenClipboard(nullptr))
	{
		return "";
	}

	HANDLE hData = GetClipboardData(CF_TEXT);
	if (hData == nullptr)
	{
		return "";
	}

	char* pszText = static_cast<char*>(GlobalLock(hData));
	if (pszText == nullptr)
	{
		return "";
	}

	GlobalUnlock(hData);
	CloseClipboard();

	return pszText;
}

void win_window_t::setClipboardString(const char* text)
{
	const size_t len = strlen(text) + 1;
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), text, len);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem); // CF_UNICODETEXT for wchar_t*
	CloseClipboard();
}
