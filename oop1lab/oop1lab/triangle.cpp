#pragma once
#include "triangle.h"


bool checkTriangle(Triangle* triangle) {
	return !((triangle->points[2].x - triangle->points[0].x) * (triangle->points[1].y - triangle->points[0].y) == (triangle->points[2].y - triangle->points[0].y) * (triangle->points[1].x - triangle->points[0].x));
}

bool checkSizeT(Triangle* triangle, int rtx, int rty) {
	for (int i = 0; i < 3; i++) {
		if (triangle->points[i].x < 0 || triangle->points[i].x > rtx || triangle->points[i].y < 0 || triangle->points[i].y > rty)
			return 0;
	}
	return 1;
}

bool checkSizeTC(Triangle* triangle, Triangle* triangle2Cut) {
	int a, b, c;
	for (int i = 0; i < 3; i++) {
		a = (triangle->points[0].x - triangle2Cut->points[i].x) * (triangle->points[1].y - triangle->points[0].y) - (triangle->points[1].x - triangle->points[0].x) * (triangle->points[0].y - triangle2Cut->points[i].y);
		b = (triangle->points[1].x - triangle2Cut->points[i].x) * (triangle->points[2].y - triangle->points[1].y) - (triangle->points[2].x - triangle->points[1].x) * (triangle->points[1].y - triangle2Cut->points[i].y);
		c = (triangle->points[2].x - triangle2Cut->points[i].x) * (triangle->points[0].y - triangle->points[2].y) - (triangle->points[0].x - triangle->points[2].x) * (triangle->points[2].y - triangle2Cut->points[i].y);
		if (!((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))) return false;
	}
	return true;
}

int readInf(Triangle* triangle, Triangle* triangle2Cut) {
	FILE* f;
	fopen_s(&f, "input.txt", "r");
	if (f == NULL) { printf_s("Can not open input file"); return -1; };
	int mode, bcolor[3], color[3];
	fscanf_s(f, "%d", &mode);
	for (int i = 0; i < 3; i++)
		fscanf_s(f, "%d%d", &(triangle->points[i].x), &(triangle->points[i].y));

	fscanf_s(f, "%d", &(triangle->style));
	for (int i = 0; i < 3; i++)
		fscanf_s(f, "%d", &(color[i]));

	fscanf_s(f, "%d", &(triangle->border));
	fscanf_s(f, "%d", &(triangle->bstyle));
	for (int i = 0; i < 3; i++)
		fscanf_s(f, "%d", &(bcolor[i]));


	triangle->bcolor = RGB(bcolor[0], bcolor[1], bcolor[2]);
	triangle->color = RGB(color[0], color[1], color[2]);

	if (mode != 2) return mode;

	for (int i = 0; i < 3; i++)
		fscanf_s(f, "%d%d", &(triangle2Cut->points[i].x), &(triangle2Cut->points[i].y));

	fclose(f);
	return mode;
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 25;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void drawTriangle(HDC hdc, Triangle* triangle) {
	COLORREF buffcolor = triangle->bcolor;//
	if (triangle->border == 0)
		buffcolor = triangle->color;

	HPEN hMyPen = CreatePen(triangle->bstyle, triangle->border, buffcolor);
	LOGBRUSH* logBrush = new LOGBRUSH;

	logBrush->lbStyle = (triangle->style == 0) ? BS_SOLID : BS_HATCHED;
	logBrush->lbHatch = triangle->style - 1;
	logBrush->lbColor = triangle->color;
	HBRUSH hMyBrush = CreateBrushIndirect(logBrush);

	SelectPen(hdc, hMyPen);
	SelectBrush(hdc, hMyBrush);
	Polygon(hdc, triangle->points, 3);
	DeletePen(hMyPen);
	delete logBrush;
	DeleteBrush(hMyBrush);
}

void drawCounter(HDC hdc, Triangle* triangle) {
	HPEN hMyPen = CreatePen(triangle->bstyle, triangle->border, triangle->bcolor);
	SelectPen(hdc, hMyPen);
	POINT ppt[4] = { triangle->points[0],triangle->points[1],triangle->points[2],triangle->points[0] };
	Polyline(hdc, ppt, 4);
	DeletePen(hMyPen);
}

void drawÑut(HDC hdc, Triangle* triangle2Ñut) {
	HPEN hMyPen = CreatePen(0, 0, RGB(0, 0, 0));
	HBRUSH hMyBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectPen(hdc, hMyPen);
	SelectBrush(hdc, hMyBrush);
	Polygon(hdc, triangle2Ñut->points, 3);
	DeletePen(hMyPen);
	DeleteBrush(hMyBrush);
}