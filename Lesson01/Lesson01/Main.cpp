#include <tchar.h>
#include <Windows.h>
#include "CELLWinApp.hpp"

int CALLBACK _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevIns, LPTSTR lpCmdLine, int nShowCmd)
{
	CELLWinApp app(hInstance);

	app.main(800,600);
	return 0;
}