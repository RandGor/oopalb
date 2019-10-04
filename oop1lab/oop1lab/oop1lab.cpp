#include <windows.h>  
#include <windowsx.h>  
#include <stdio.h>
#include <conio.h>
#include "triangle.h"


void main()
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	RECT rt;
	HPEN hOldPen = GetStockPen(BLACK_PEN);
	HBRUSH hOldBrush = GetStockBrush(WHITE_BRUSH);

	int oldx = 0, oldy = 0;
	int rtx = 0, rty = 0;

	Triangle* triangle = new Triangle;
	Triangle* triangle2put = new Triangle;
	int mode = readInf(triangle, triangle2put);

	if (!checkTriangle(triangle)) {
		printf("\nYour triangle is wrong");
		_getch();
		return;
	}
	if (mode == 2 && !checkTriangle(triangle2put)) {
		printf("\nYour 2nd triangle is wrong");
		_getch();
		return;
	}
	if (mode == 2 && !checkSizeTC(triangle, triangle2put)) {
		printf("\nYour 2nd triangle doesn't fit in 1st one");
		_getch();
		return;
	}

	char c = 0;
	do {
		GetClientRect(hwnd, &rt);
		rtx = rt.right;
		rty = rt.bottom;
		if (oldx != rtx || oldy != rty)
		{
			system("CLS");
			hidecursor();
			oldx = rtx;
			oldy = rty;
			if (checkSizeT(triangle, rtx, rty)) {
				Sleep(50);
				switch (mode)
				{
					case 0:
						drawTriangle(hdc, triangle); 
						break;
					case 1:
						drawCounter(hdc, triangle); 
						break;
					case 2:
						drawTriangle(hdc, triangle);
						draw—ut(hdc, triangle2put);
						break;
				}
			}
			else
				printf_s("Increase window size(current is %d : %d)", rtx, rty);
		}
		if (_kbhit()) {
			c = _getch();
		}
		Sleep(50);
	} while (c != 27);
	system("CLS");
	SelectPen(hdc, hOldPen);
	SelectBrush(hdc, hOldBrush);
	ReleaseDC(hwnd, hdc);
}