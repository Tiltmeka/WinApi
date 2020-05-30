// lab4.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "lab4.h"
#include <fstream>
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB4));

    MSG msg;

    // Цикл основного сообщения:
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



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB4);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, _TEXT("THREADS"), WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 600, 600, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   HMENU WINAPI a;
   HMENU Menu = CreateMenu();
   HMENU hPopupMenu1 = CreatePopupMenu();
   HMENU hPopupMenu2 = CreatePopupMenu();
   HMENU hPopupMenu3 = CreatePopupMenu();
   AppendMenu(Menu, MF_STRING | MF_POPUP, (UINT)hPopupMenu1, L"&Включить");
   {
	   AppendMenu(hPopupMenu1, MF_STRING, 100, L"Нечётные числа");
	   AppendMenu(hPopupMenu1, MF_STRING, 200, L"Чётные числа");
	   AppendMenu(hPopupMenu1, MF_STRING, 300, L"Прогресс");
   }
   AppendMenu(Menu, MF_STRING | MF_POPUP, (UINT)hPopupMenu3, L"&Очистка");
   {
	   AppendMenu(hPopupMenu3, MF_STRING, 700, L"Нечётные числа");
	   AppendMenu(hPopupMenu3, MF_STRING, 800, L"Чётные числа");
   }
  // AppendMenu(Menu, MF_STRING | MF_POPUP, (UINT)hPopupMenu2, L"&Открыть");
  // {
//	   AppendMenu(hPopupMenu2, MF_STRING, 400, L"Text 1");
//	   AppendMenu(hPopupMenu2, MF_STRING, 500, L"Text 1");
 //  }
   SetMenu(hWnd, Menu);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//





static HWND Static1;
static HWND Static2;
HANDLE hThread1;
HANDLE hThread2;
HANDLE hThread3;
HANDLE hThread4;
HANDLE hThread5;
HANDLE hThread6;
DWORD WINAPI Thread1(LPVOID t);
DWORD WINAPI Thread2(LPVOID t);
DWORD WINAPI Thread3(LPVOID t);
DWORD WINAPI Thread4(LPVOID t);
DWORD WINAPI Thread5(LPVOID t);
DWORD WINAPI Thread6(LPVOID t);
BOOL thread1_working = false;
BOOL thread2_working = false;
BOOL thread3_working = false;
BOOL thread4_working = false;
BOOL thread5_working = false;
BOOL thread6_working = false;
static int progress1;
static int progress2;
static int number1 = 1;
static int number2 = 1000;
int test = 228;
static char procent1[4] = "   ";
static char procent2[4] = "   ";
static char realtime1[4];
static char realtime2[4];
static wchar_t middle1[4];
static wchar_t middle2[4];
DWORD WINAPI Thread1(LPVOID t)
{
	
	std::fstream out;
	HDC hdc = GetDC(HWND(t));
	out.open("E:\\testtest\\test1.txt");
	for (int i = 1; i < 11; i++)
	{
		out << number1 << std::endl;
		progress1 = i * 10;
		number1+=2;
		Sleep(1000);
	}
	return 0;
}
DWORD WINAPI Thread2(LPVOID t)
{	
	std::fstream out;
	HDC hdc = GetDC(HWND(t));
	out.open("E:\\testtest\\test2.txt");
	for (int i = 1; i < 11; i++)
	{	
		out << number2 << std::endl;
		progress2 = i*10;
		number2 -= 2;
		Sleep(2000);
	}
	return 0;
}
DWORD WINAPI Thread3(LPVOID t)
{
	while (true)
	{
		_itoa_s(progress1, realtime1, 4, 10);
		procent1[0] = realtime1[0];
		procent1[1] = realtime1[1];
		procent1[2] = realtime1[2];
		MultiByteToWideChar(CP_ACP, 0, procent1, -1, middle1, 4);
		SetWindowText(Static1, middle1);

		_itoa_s(progress2, realtime2, 4, 10);
		procent2[0] = realtime2[0];
		procent2[1] = realtime2[1];
		procent2[2] = realtime2[2];
		MultiByteToWideChar(CP_ACP, 0, procent2, -1, middle2, 4);
		SetWindowText(Static2, middle2);
		Sleep(1000);
	}
	return 0;
}
DWORD WINAPI Thread4(LPVOID t)
{
	int number2 = 1000;
	std::fstream out;
	HDC hdc = GetDC(HWND(t));
	out.open("E:\\testtest\\test1.txt");
	for (int i = 0; i < 20; i++)
	{
		out << " " << std::endl;
	}
	progress1 = 0;
	return 0;
}
DWORD WINAPI Thread5(LPVOID t)
{
	int number2 = 1000;
	std::fstream out;
	HDC hdc = GetDC(HWND(t));
	out.open("E:\\testtest\\test2.txt");
	for (int i = 0; i < 20; i++)
	{
		out << " " << std::endl;
	}
	progress2 = 0;
	return 0;
}





HDC hdc;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		
		HDC hdc = BeginPaint(hWnd, &ps);
		
		TextOut(hdc, 0, 0, L"Прогресс заполнения нечётных -", 30);
		TextOut(hdc, 0, 30, L"Прогресс заполнения чётных -", 28);
		EndPaint(hWnd, &ps);

	}
	case WM_CREATE:
	{
		Static1 = CreateWindow(
			_T("static"),
			_T(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_RIGHT,
			225,
			1,
			30,
			15,
			hWnd,
			0,
			NULL,
			NULL);
		Static2 = CreateWindow(
			_T("static"),
			_T(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_RIGHT,
			210,
			31,
			30,
			15,
			hWnd,
			0,
			NULL,
			NULL);
		//SetWindowText(Static1, _T("100"));
		//SetWindowText(Static2, _T("100"));
	}
    case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case 100: //запись нечетных
		{
			thread1_working = true;
			hThread1 = CreateThread(NULL, 0, Thread1, hWnd, 0, NULL);
			break;

		}
		case 200: //запись четных
		{
			thread2_working = true;
			hThread2 = CreateThread(NULL, 0, Thread2, hWnd, 0, NULL);
			break;
		}
		case 300: //запись прогресса
		{
			//InvalidateRect(hWnd, NULL, TRUE);
			
			thread3_working = true;
			hThread3 = CreateThread(NULL, 0, Thread3, hWnd, 0, NULL);
			break;
		}
		case 700: //очистка нечетных
		{
			thread4_working = true;
			hThread4 = CreateThread(NULL, 0, Thread4, hWnd, 0, NULL);
			break;
		}
		case 800: //очистка четных
		{

			thread5_working = false;
			hThread5 = CreateThread(NULL, 0, Thread5, hWnd, 0, NULL);
			break;
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
		}
	}
	
        break;
    case WM_DESTROY:
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
  /*case 400: //остановка нечетных 
		{

			thread1_working = false;
			break;
		}
		case 500: //остановка четных
		{
			TerminateThread(hThread2, 0);
			thread2_working = false;
			break;
		}
		case 600: //остановка прогресса
		{

			thread3_working = false;
			break;
		}
		
		
		 AppendMenu(Menu, MF_STRING | MF_POPUP, (UINT)hPopupMenu2, L"&Отключить");
   {
	   AppendMenu(hPopupMenu2, MF_STRING, 400, L"Нечётные числа");
	   AppendMenu(hPopupMenu2, MF_STRING, 500, L"Чётные числа");
	   AppendMenu(hPopupMenu2, MF_STRING, 600, L"Прогресс");
   }
   
   
   */