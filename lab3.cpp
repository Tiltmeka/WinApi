// Art_C.cpp : Определяет точку входа для приложения.
//
#include "stdafx.h"
#include <stdlib.h>
#include <random>
#include "lab3.h"
#include <string>
#define MAX_LOADSTRING 100
#define RGB(r, g, b) ((COLORREF)(((BYTE)(r) | ((WORD)(g) << 8)) | ((DWORD)(BYTE)(b)) << 16)))


using namespace std;

#include <Windows.h>
#include <tchar.h>
#include <string>
#include <atlstr.h>


#define windowWidth 380
#define windowHeight 420
#define buttonWidth 78
#define buttonHeight 50


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("MainFrame");

int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
	HINSTANCE Prev, 	// В современных системах всегда 0 
	LPTSTR cmd, 		// Командная строка 
	int mode) 		// Режим отображения окна
{
	HWND hWnd;		// Дескриптор главного окна программы 
	MSG msg; 		// Структура для хранения сообщения 
	WNDCLASS wc; 	// Класс окна
	// Определение класса окна 
	wc.hInstance = This;
	wc.lpszClassName = WinName; 				// Имя класса окна 
	wc.lpfnWndProc = WndProc; 					// Функция окна 
	wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
	wc.hCursor = LoadCursor(NULL, IDC_CROSS); 		// Стандартный курсор 
	wc.lpszMenuName = NULL; 					// Нет меню 
	wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
	wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// Заполнение окна белым цветом 


	// Регистрация класса окна
	if (!RegisterClass(&wc)) return 0;

	// Создание окна 
	hWnd = CreateWindow(WinName,			// Имя класса окна 
		_T("Висельница"), 		// Заголовок окна 
		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 Размеры окна 
		windowWidth, 				// width 
		windowHeight, 				// Height 
		HWND_DESKTOP, 				// Дескриптор родительского окна 
		NULL, 						// Нет меню 
		This, 						// Дескриптор приложения 
		NULL); 					// Дополнительной информации нет 

	ShowWindow(hWnd, mode); 				// Показать окно
	UpdateWindow(hWnd);
	// Цикл обработки сообщений 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
	}
	return 0;
}

// Оконная функция вызывается операционной системой
// и получает сообщения из очереди для данного приложения

struct Unit
{
	int r = 0, g = 255, b = 0;
	int x1, x2;
	int y1 = 50;
	int y2 = 100;
};



static bool c = false;
static int star_count = 6;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst;
	static HWND hWndStatic;
	static HWND hWndStatic1;
	static HWND hWndStatic2;
	static HWND hWndEdit;
	static HWND hWndButton;
	PAINTSTRUCT ps;
	RECT rectangle;
	RECT rectangle1;
	HDC hdc;
	int count, test;
	static int lenght;
	string word = "винапи";
	static Unit mas[5];
	static int fail_counter = 4;
	mas[0].x1 = 40;
	//	mas[0].y1 = 50;
	mas[0].x2 = 90;
	//mas[0].y2 = 100;
	int test1;
	TCHAR test_string[20];
	char test_string2[20];
	wchar_t test_wchar[20];
	static char L[30] = "Ваше слово содержит   букв";
	static wchar_t D[30];
	static char word1[10];
	static wchar_t wordw[10];
	static wchar_t wordd[30];
	static char wordds[10];
	static bool incorr = false;
	static bool fail = false;
	static bool win = false;



	for (int i = 1; i < 5; i++)
	{
		mas[i].x1 = mas[i - 1].x1 + 56;
		mas[i].x2 = mas[i - 1].x2 + 56;
	}

	lenght = word.length();
	for (int i = 0; i < lenght; i++)
	{
		word1[i] = word[i];
		wordds[i] = '*';
	}
	if (!c)
		MultiByteToWideChar(CP_ACP, 0, wordds, -1, wordd, 10);

	c = true;
	MultiByteToWideChar(CP_ACP, 0, word1, -1, wordw, 10);
	char N[2];
	_itoa_s(lenght, N, 2, 10);
	L[20] = N[0];


	switch (message)		 // Обработчик сообщений
	{


	case WM_CREATE: // сообщение создания окна
	{
		hWndStatic = CreateWindow(
			_T("static"),
			_T("Попытки"),
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_CENTER,
			119,
			11,
			125,
			17,
			hWnd,
			0,
			NULL,
			NULL);
		hWndStatic1 = CreateWindow(
			_T("static"),
			_T(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			0,
			300,
			205,
			17,
			hWnd,
			0,
			NULL,
			NULL);

		hWndStatic2 = CreateWindow(
			_T("static"),
			wordd,
			WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
			40,
			120,
			275,
			17,
			hWnd,
			0,
			NULL,
			NULL);

		hWndButton = CreateWindow(
			_T("button"),
			_T("Ответить"),
			WS_VISIBLE | WS_CHILD | SS_CENTER,
			0,
			360,
			65,
			23,
			hWnd,
			0,
			NULL,
			NULL);
		hWndEdit = CreateWindow(
			_T("edit"),
			_T(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_RIGHT,
			0,
			330,
			65,
			23,
			hWnd,
			0,
			NULL,
			NULL);
		ShowWindow(hWndEdit, SW_SHOWNORMAL);
		MultiByteToWideChar(CP_ACP, 0, L, -1, D, 30);
		SetWindowText(hWndStatic1, D);


		break;

	}
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		for (int i = 0; i < 5; i++)
		{
			rectangle = { mas[i].x1 ,mas[i].y1, mas[i].x2 ,mas[i].y2 };
			FillRect(hdc, &rectangle, CreateSolidBrush(RGB(mas[i].r, mas[i].g, mas[i].b));
			FrameRect(hdc, &rectangle, CreateSolidBrush(RGB(0, 0, 0));
		}
		//rectangle = { 0, 50, 366, 100 };
		//FillRect(hdc, &rectangle, CreateSolidBrush(RGB(0, 255, 0));
		//FrameRect(hdc, &rectangle,CreateSolidBrush(RGB(0, 0, 0));
		EndPaint(hWnd, &ps);
		break;

	}
	
	case WM_COMMAND:
	{

		if (lParam == (LPARAM)hWndButton && !(win || fail))
		{
			test1 = GetWindowText(hWndEdit, test_wchar, 20);
			incorr = true;
			win = false;
			fail = false;

			for (int i = 0; i < lenght; i++)
			{
				if (test_wchar[0] == wordw[i])
				{
					wordd[i] = test_wchar[0];
					incorr = false;
					star_count--;
				}
			}

			if (incorr)
			{
				if (fail_counter >= 0)
				{
					mas[fail_counter].r = 255;
					mas[fail_counter].g = 0;
					hdc = GetDC(hWnd);
					rectangle = { mas[fail_counter].x1, mas[fail_counter].y1, mas[fail_counter].x2, mas[fail_counter].y2 };
					FillRect(hdc, &rectangle, CreateSolidBrush(RGB(mas[fail_counter].r, mas[fail_counter].g, mas[fail_counter].b));
					FrameRect(hdc, &rectangle, CreateSolidBrush(RGB(0, 0, 0));
					ReleaseDC(hWnd, hdc);
					fail_counter--;

				}

				if (fail_counter == -1)
				{
					fail = true;
				}
			}
			SetWindowText(hWndStatic2, wordd);

			if (star_count == 0)
			{
				win = true;
			}
			if (fail)
			{
				MessageBox(hWnd, TEXT("ВЫ ПРОИГРАЛИ!!!"), TEXT(""), MB_OK);
				SetWindowText(hWndStatic, _T("ПОРАЖЕНИЕ"));
			}
			if (win)
			{
				MessageBox(hWnd, TEXT("ВЫ ВЫИГРАЛИ!!!"), TEXT(""), MB_OK);
				SetWindowText(hWndStatic, _T("ПОБЕДА"));
			}
			SetWindowText(hWndEdit, _T(""));
		}



		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break; 			// Завершение программы  
	default: 			// Обработка сообщения по умолчанию 
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


//test = rand() % 4;
//word = words[test];
//lenght = word.length();

/*hWndEdit = CreateWindow(
				 _T("edit"),
				 _T("0"),
				 WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
				 200,
				 11,
				 245,
				 13,
				 hWnd,
				 0,
				 NULL,
				 NULL);





				 rectangle = { 0, 50, 366, 100 };
			FillRect(hdc, &rectangle, CreateSolidBrush(RGB(0, 255, 0));
			rectangle = { 60, 50, 61, 100 };
			FillRect(hdc, &rectangle, CreateSolidBrush(RGB(0, 0, 0));
			rectangle = { 121, 50, 122, 100 };
			FillRect(hdc, &rectangle, CreateSolidBrush(RGB(0, 0, 0));
			rectangle = { 182, 50, 183, 100 };
			FillRect(hdc, &rectangle, CreateSolidBrush(RGB(0, 0, 0));
			rectangle = { 243, 50, 244, 100 };
			FillRect(hdc, &rectangle, CreateSolidBrush(RGB(0, 0, 0));
			rectangle = { 305, 50, 306, 100 };
			FillRect(hdc, &rectangle, CreateSolidBrush(RGB(0, 0, 0));

			case WM_USER + 1:
	{

		if (fail_counter >= 0)
		{
			mas[fail_counter].r = 255;
			mas[fail_counter].g = 0;
			hdc = GetDC(hWnd);
			rectangle = { mas[fail_counter].x1, mas[fail_counter].y1, mas[fail_counter].x2, mas[fail_counter].y2 };
			FillRect(hdc, &rectangle, CreateSolidBrush(RGB(mas[fail_counter].r, mas[fail_counter].g, mas[fail_counter].b));
			FrameRect(hdc, &rectangle, CreateSolidBrush(RGB(0, 0, 0));
			ReleaseDC(hWnd, hdc);
			fail_counter--;

		}


		//hdc = GetDC(hWnd);
		//rectangle = { 0, 50, 366, 100 };
		//FillRect(hdc, &rectangle, CreateSolidBrush(RGB(255, 0, 0));
		//ReleaseDC(hWnd, hdc);
		break;
	}
			*/
