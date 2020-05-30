// WindowsProject2.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "WindowsProject2.h"
#include <iostream>
//#define WM_LBUTTONDOWN      
#define MAX_LOADSTRING 100

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#define RGB(r, g, b) ((COLORREF)(((BYTE)(r) | ((WORD)(g) << 8)) | ((DWORD)(BYTE)(b)) << 16)))
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
	wc.hbrBackground = CreateSolidBrush(RGB(255, 211, 0); 	// Заполнение окна белым цветом 
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;


	// Регистрация класса окна
	if (!RegisterClass(&wc)) return 0;

	// Создание окна 
	hWnd = CreateWindow(WinName,			// Имя класса окна 
		_T("я пытался"), 		// Заголовок окна 
		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 Размеры окна 
		CW_USEDEFAULT, 				// width 
		CW_USEDEFAULT, 				// Height 
		HWND_DESKTOP, 				// Дескриптор родительского окна 
		NULL, 						// Нет меню 
		This, 						// Дескриптор приложения 
		NULL); 					// Дополнительной информации нет 

	
		
	ShowWindow(hWnd, mode); 				// Показать окно
	// Цикл обработки сообщений 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
	}
	return 0;
	
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	LOGFONT font;
	font.lfHeight = 50;// Устанавливает высоту шрифта или символа
	font.lfWidth = 0;// Устанавливает среднюю ширину символов в шрифте
	font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
	font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
	font.lfWeight = 50;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
	font.lfItalic = 0;// Устанавливает курсивный шрифт 
	font.lfUnderline = 0;// Устанавливает подчеркнутый шрифт
	font.lfStrikeOut = 0;// Устанавливает зачеркнутый шрифт
	//font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
	//font.lfOutPrecision = 0;// Устанавливает точность вывода
	//font.lfClipPrecision = 0;// Устанавливает точность отсечения
	//font.lfQuality = 0;// Устанавливает качество вывода
	//font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта
	HFONT hfont;
	hfont = ::CreateFontIndirect(&font);
	std::cout << "Event" << message << std::endl;

	switch (message)		 // Обработчик сообщений
	{

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			HPEN hPenOld;
			HPEN hEllipsePen;
			COLORREF qEllipseColor = (HS_VERTICAL, RGB(48, 213, 200);
			hEllipsePen = CreatePen(PS_SOLID, 200, qEllipseColor);
			hPenOld = (HPEN)SelectObject(hdc, hEllipsePen);
			Arc(hdc, 400, 250, 800, 400, 0, 0, 0, 0);
			SelectObject(hdc, hPenOld);
			DeleteObject(hEllipsePen);
			
			SetTextColor(hdc, RGB(0, 0, 255);
			SetBkColor(hdc, RGB(48, 213, 200);
			TextOut(hdc, 550, 300, L"Якубов", 6);
			//EndPaint(hWnd, &ps);
			return 0;
		}

		case WM_LBUTTONDOWN:
		{
			InvalidateRect(hWnd, NULL, TRUE);
			HDC hdc = BeginPaint(hWnd, &ps);
			HPEN hPenOld;
			HPEN hEllipsePen;
			COLORREF qEllipseColor = (HS_VERTICAL, RGB(48, 213, 200));
			hEllipsePen = CreatePen(PS_SOLID, 200, qEllipseColor);
			hPenOld = (HPEN)SelectObject(hdc, hEllipsePen);
			Arc(hdc, 400, 250, 800, 400, 0, 0, 0, 0);
			SelectObject(hdc, hPenOld);
			DeleteObject(hEllipsePen);

			SetTextColor(hdc, RGB(0, 0, 255));
			SetBkColor(hdc, RGB(48, 213, 200));
			//TextOut(hdc, 550, 300, L"", 6);
			EndPaint(hWnd, &ps);
			break;
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}

}


