#pragma once
#include <windows.h>  
#include <windowsx.h>  
#include <stdio.h>
#include <conio.h>

class Triangle {
	public:
		POINT points[3];
		int style;
		COLORREF color;
		int border, bstyle;
		COLORREF bcolor;
};

bool checkTriangle(Triangle* triangle);
bool checkSizeT(Triangle* triangle, int rtx, int rty);
bool checkSizeTC(Triangle* triangle, Triangle* triangle2Cut);

int readInf(Triangle* triangle, Triangle* triangle2Cut);

void hidecursor();

void drawTriangle(HDC hdc, Triangle* triangle);
void drawCounter(HDC hdc, Triangle* triangle);
void draw—ut(HDC hdc, Triangle* triangle2—ut);