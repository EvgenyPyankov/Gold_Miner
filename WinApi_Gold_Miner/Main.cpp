#include "stdafx.h"
#include "Main.h"
#include "Renderer.h"

#include "Mineral.h"
#include "LevelGenerator.h"
#include "Constants.h"
#include "Converter.h"
#include "Hook.h"
#include <list>

#define MAX_LOADSTRING 100
#define LEVEL_TIMER 1
#define HOOK_TIMER 2
#define RENDER_TIMER 3

HINSTANCE hInst;                              
WCHAR szTitle[MAX_LOADSTRING];                 
WCHAR szWindowClass[MAX_LOADSTRING];            

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
Mineral* detectCollision();

int timeOut = 30;
int renderTimer;
int hookTimer;
Hook hook;
Levels currentLevel;
list<Mineral> minerals;


void init(HWND hWnd)
{
	currentLevel = One;
	minerals = LevelGenerator::getMinerals(currentLevel);
	hook = Hook(0.5, 0.0);
	renderTimer = SetTimer(hWnd, RENDER_TIMER, timeOut, NULL);
	hookTimer = SetTimer(hWnd, HOOK_TIMER, 30, NULL);

}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPI_GOLD_MINER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI_GOLD_MINER));

    MSG msg;



    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI_GOLD_MINER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPI_GOLD_MINER);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   CW_USEDEFAULT, CW_USEDEFAULT, WIDTH, HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   init(hWnd);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

Mineral* detectCollision()
{
	double xHook = hook.getX();
	double yHook = hook.getY();
	for (Mineral mineral : minerals) {
		double x = xHook - mineral.getX();
		double y = yHook - mineral.getY();
		if ((x*x + y*y) < mineral.getR()*mineral.getR()) {
			return &mineral;
		}

	}
	return NULL;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_TIMER:
	{
		switch (wParam)
		{
		case RENDER_TIMER:
			InvalidateRect(hWnd, NULL, false);
			return 0;
		case LEVEL_TIMER:
			return 0;
		case HOOK_TIMER:
			hook.calculatePosition();
		
				//hook.hookState = Backward;
				Mineral* mineral = detectCollision();
				if (mineral != NULL) {
					hook.grabMineral(mineral);
					//KillTimer(hWnd, hookTimer);
				}
				
			return 0;

		}
		break;
	}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
		Renderer::render(hWnd, hook, minerals);
        }
        break;
	case WM_KEYDOWN:
	{
		switch (wParam) {
		case VK_SPACE:

			break;
		case VK_LEFT:

			break;
		case VK_RIGHT:

			break;
		case VK_UP:

			break;
		case VK_DOWN:
			hook.pullHook();
			break;
		}
	}
	break;
    case WM_DESTROY:
		KillTimer(hWnd, renderTimer);
		KillTimer(hWnd, hookTimer);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}



// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
