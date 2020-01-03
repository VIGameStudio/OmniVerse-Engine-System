#include "win_window.hpp"

#include <ove/system/input.hpp>
#include <ove/system/win/win_input.hpp>

#include <array>

#include <gl/GL.h>
//#include <d3d11.h>

using namespace ove::core;
using namespace ove::system;

std::array<u8, 0xff> createKeycodeMap()
{
	std::array<u8, 0xff> map;

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

	m_glContext = wglCreateContext(m_deviceContext);
	wglMakeCurrent(m_deviceContext, m_glContext);

	ReleaseDC(m_windowHandle, m_deviceContext);

	ShowWindow(m_windowHandle, SW_SHOWDEFAULT);
	UpdateWindow(m_windowHandle);

	m_shouldClose = false;

	return true;
}

LONG WINAPI WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	win_window_t* win = reinterpret_cast<win_window_t*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	if (win) return win->wndProc(hWnd, uMsg, wParam, lParam);
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LONG WINAPI win_window_t::wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static PAINTSTRUCT ps;

	switch (uMsg)
	{
	case WM_SIZE:
		// width: LOWORD(lParam), height: HIWORD(lParam)
		PostMessage(hWnd, WM_PAINT, 0, 0);
		return 0;

	case WM_CHAR:
		return 0;

	case WM_KEYDOWN:
		m_keys[convertKeycode(wParam)] = true;
		return 0;

	case WM_KEYUP:
		m_keys[convertKeycode(wParam)] = false;
		return 0;

	case WM_LBUTTONDOWN:
		m_buttons[MBTN_LEFT] = true;
		return 0;

	case WM_MBUTTONDOWN:
		m_buttons[MBTN_MIDDLE] = true;
		return 0;

	case WM_RBUTTONDOWN:
		m_buttons[MBTN_RIGHT] = true;
		return 0;

	case WM_LBUTTONUP:
		m_buttons[MBTN_LEFT] = false;
		return 0;

	case WM_MBUTTONUP:
		m_buttons[MBTN_MIDDLE] = false;
		return 0;

	case WM_RBUTTONUP:
		m_buttons[MBTN_RIGHT] = false;
		return 0;

	case WM_MOUSEMOVE:
		m_mouseX = LOWORD(lParam);
		m_mouseY = HIWORD(lParam);
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

const char* win_window_t::getTitle()
{
	return m_title.c_str();
}

void win_window_t::getSize(u32& width, u32& height)
{
	/*RECT rc;

	GetClientRect(m_windowHandle, &rc);
	width = rc.right - rc.left;
	height = rc.bottom - rc.top;

	GetWindowRect(m_windowHandle, &rc);
	width = rc.right - rc.left;
	height = rc.bottom - rc.top;*/
}