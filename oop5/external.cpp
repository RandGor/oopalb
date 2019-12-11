#include "external.h"


void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 25;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void clear()
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	RECT rt;
	GetClientRect(hwnd, &rt);

	system("cls");
	HPEN hCurrPen, hOldPen;
	HBRUSH hCurrBrush, hOldBrush;
	hCurrPen = CreatePen(PS_SOLID, 1, COLOR_BACKGROUND);
	hCurrBrush = CreateSolidBrush(COLOR_BACKGROUND);
	hOldPen = SelectPen(hdc, hCurrPen);
	hOldBrush = SelectBrush(hdc, hCurrBrush);
	GetClientRect(hwnd, &rt);
	Rectangle(hdc, 0, 0, rt.right, rt.bottom);
	SelectPen(hdc, hOldPen);
	DeletePen(hCurrPen);
	SelectBrush(hdc, hOldBrush);
	DeleteBrush(hCurrBrush);
}


void clearConsole() {
	clear();
	//system("cls");
	//system("cls");
}