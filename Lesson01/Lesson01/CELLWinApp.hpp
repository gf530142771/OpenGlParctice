#pragma once
#include <Windows.h>
#include <tchar.h>
class CELLWinApp
{
protected:
	HWND _hWnd;
	HINSTANCE _hInstance;
public:
	CELLWinApp(HINSTANCE _hInstance)
	{
		/*
		window ��������
		*/
		//1.ע��һ������������
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

	static LRESULT CALLBACK wndProc(HWND hWnd, UINT msg, WPARAM uParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CREATE:
			break;
		case WM_DESTROY:
			break;
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, msg, uParam, lParam);
			break;
		}
		return S_OK;
	}

	int main(int width ,int height)
	{
		//2.��������
		_hWnd = CreateWindow(_T("CELLWinApp"), _T("CELLWinApp"),WS_OVERLAPPEDWINDOW,0,0,width,height,0,0,_hInstance,this);
		if (_hWnd == 0)
		{
			return -1;
		}
		//3.���´���
		UpdateWindow(_hWnd);
		//4.��ʾ����
		ShowWindow(_hWnd, SW_MAXIMIZE);

		//��Ϣѭ��
		MSG msg = { 0 };

		while (GetMessage(&msg,0,0,0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return 1;
	}
};

