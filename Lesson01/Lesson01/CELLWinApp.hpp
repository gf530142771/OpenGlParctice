#pragma once
#include <Windows.h>
#include <tchar.h>
class CELLWinApp
{
protected:
	static LRESULT CALLBACK wndProc(HWND hWnd, UINT msg, WPARAM uParam, LPARAM lParam)
	{
		// 		switch (msg)
		// 		{
		// 		case WM_CREATE:
		// 			break;
		// 		case WM_DESTROY:
		// 			break;
		// 		case WM_CLOSE:
		// 			PostQuitMessage(0);
		// 			break;
		// 		default:
		// 			return DefWindowProc(hWnd, msg, uParam, lParam);
		// 			break;
		// 		}
		// 		return S_OK;
		CELLWinApp* pThis = (CELLWinApp*)GetWindowLong(hWnd, GWL_USERDATA);
		if (pThis)
		{
			pThis->onEvent(hWnd, msg, uParam, lParam);
		}

		if (WM_CREATE == msg)
		{
			CREATESTRUCT* pStruct = (CREATESTRUCT*)lParam;
			SetWindowLong(hWnd, GWL_USERDATA, (DWORD_PTR)pStruct->lpCreateParams);
		}

		return DefWindowProc(hWnd, msg, uParam, lParam);
	}
protected:
	HWND _hWnd;
	HINSTANCE _hInstance;
public:
	CELLWinApp(HINSTANCE _hInstance)
	{
		/*
		window 创建窗口
		*/
		//1.注册一个创建窗口类
		WNDCLASSEX wndClassex;
		memset(&wndClassex, 0, sizeof(wndClassex));
		wndClassex.cbSize = sizeof(wndClassex);
		wndClassex.style = CS_VREDRAW | CS_HREDRAW |CS_OWNDC;
		wndClassex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wndClassex.hCursor = LoadCursor(_hInstance,IDC_ARROW);

		wndClassex.lpszClassName = _T("CELLWinApp");

		wndClassex.lpfnWndProc = wndProc;
		wndClassex.hIcon = 0;
		wndClassex.lpszMenuName = 0;

		RegisterClassEx(&wndClassex);

		this->_hInstance = _hInstance;
	}

	virtual ~CELLWinApp()
	{
		UnregisterClass(_T("CELLWinApp"), _hInstance);
	}

	virtual LRESULT CALLBACK onEvent(HWND hWnd, UINT msg, WPARAM uParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CLOSE:
			break;
		case WM_DESTROY:
		{
						   PostQuitMessage(0);
		}
			break;
		case WM_LBUTTONDOWN:
			break;
		case WM_LBUTTONUP:
			break;
		case WM_MOUSEMOVE:
			break;
		case WM_RBUTTONUP:
			break;
		case WM_RBUTTONDOWN:
			break;
		default:
			return DefWindowProc(hWnd, msg, uParam, lParam);
			break;
		}
		return S_OK;
	}

	int main(int width, int height)
	{
		//2.创建窗口
		_hWnd = CreateWindow(_T("CELLWinApp"), _T("CELLWinApp"), WS_OVERLAPPEDWINDOW, 0, 0, width, height, 0, 0, _hInstance, this);
		if (_hWnd == 0)
		{
			return -1;
		}
		//3.更新窗口
		UpdateWindow(_hWnd);
		//4.显示窗口
		ShowWindow(_hWnd, SW_MAXIMIZE);

		//消息循环
		MSG msg = { 0 };

		while (msg.message != WM_QUIT)
		{
			if (msg.message == WM_CLOSE || msg.message == WM_DESTROY)
			{
				break;
			}

			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				Sleep(1);
			}
		}
		return 0;
	}
};

