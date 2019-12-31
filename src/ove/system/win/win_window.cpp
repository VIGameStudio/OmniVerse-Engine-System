#include "win_window.hpp"

#include <GL/GL.h>
#pragma comment (lib, "opengl32.lib")

//#include <d3d11.h>
//#pragma comment (lib, "d3d11.lib")

using namespace ove;
using namespace core;
using namespace system;

win_window_t* pWindow = nullptr;

LONG WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

win_window_t::win_window_t()
{
	m_windowHandle = NULL;
	m_deviceContext = NULL;
	m_glContext = NULL;

	m_title = nullptr;
	m_shouldClose = true;
}

win_window_t::~win_window_t()
{
	wglMakeCurrent(NULL, NULL);
	ReleaseDC(m_windowHandle, m_deviceContext);
	wglDeleteContext(m_glContext);
	DestroyWindow(m_windowHandle);
}

bool win_window_t::create(const char* title, u32 width, u32 height)
{
	m_title = title;

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
		wc.lpfnWndProc = (WNDPROC)WindowProc;

		if (!RegisterClassEx(&wc))
		{
			MessageBox(NULL, "RegisterClassEx() failed: Cannot register window class.", "Error", MB_OK);
			return false;
		}
	}

	if (pWindow == nullptr)
	{
		pWindow = this;
	}

	u32 x = 0;
	u32 y = 0;

	m_windowHandle = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		windowClassStr,
		title,
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		x, y, width, height,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (!m_windowHandle)
	{
		MessageBox(NULL, "CreateWindow() failed: Cannot create a window.", "Error", MB_OK);
		return false;
	}

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

LONG WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static PAINTSTRUCT ps;

	switch (uMsg)
	{
	case WM_PAINT:
		//glClearColor(1, 0, 0, 1);
		//glClear(GL_COLOR_BUFFER_BIT);

		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_SIZE:
		//glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));

		PostMessage(hWnd, WM_PAINT, 0, 0);
		return 0;

	case WM_CHAR:
		switch (wParam)
		{
		case 27: // ESC key
			pWindow->close();
			PostQuitMessage(0);
			break;
		}
		return 0;

	case WM_LBUTTONDOWN:
		return 0;

	case WM_CLOSE:
		pWindow->close();
		PostQuitMessage(0);
		return 0;

	case WM_DESTROY:
		pWindow->close();
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
	return m_title;
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