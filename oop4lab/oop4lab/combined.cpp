#include "combined.h"
#include "error.h"

void combined::setFCPoints(POINT *new_Cpoints) {
	checkSizeTC(new_Cpoints);
	for (int i = 0; i < 3; i++)
		if (new_Cpoints[i].x < 0 || new_Cpoints[i].y < 0)
			throw ERR_NEGATIVE_POINTS;
	if ((new_Cpoints[2].x - new_Cpoints[0].x)*(new_Cpoints[1].y - new_Cpoints[0].y) == (new_Cpoints[2].y - new_Cpoints[0].y)*(new_Cpoints[1].x - new_Cpoints[0].x))
		throw ERR_POINTS_ONLINE;
	for (int i = 0; i < 3; i++)
		Cpoints[i] = new_Cpoints[i];
}
void combined::getFCPoints(POINT *&curr_Cpoints) {
	for (int i = 0; i < 3; i++) curr_Cpoints[i] = Cpoints[i];
}

void combined::Draw(HDC hdc) {
	checkSizeT(hdc);

	COLORREF buffcolor = color;
	if (border == 0)
		buffcolor = bcolor;

	HPEN hMyPen = CreatePen(style, border, buffcolor);
	LOGBRUSH* logBrush = new LOGBRUSH;

	logBrush->lbStyle = (bstyle == 0) ? BS_SOLID : BS_HATCHED;
	logBrush->lbHatch = bstyle - 1;
	logBrush->lbColor = bcolor;
	HBRUSH hMyBrush = CreateBrushIndirect(logBrush);

	SelectPen(hdc, hMyPen);
	SelectBrush(hdc, hMyBrush);
	Polygon(hdc, points, 3);

	DeletePen(hMyPen);
	delete logBrush;
	DeleteBrush(hMyBrush);


	HPEN hMyPen2 = CreatePen(0, 0, RGB(0, 0, 0));
	HBRUSH hMyBrush2 = CreateSolidBrush(RGB(0, 0, 0));
	SelectPen(hdc, hMyPen2);
	SelectBrush(hdc, hMyBrush2);
	Polygon(hdc, Cpoints, 3);
	DeletePen(hMyPen2);
	DeleteBrush(hMyBrush2);
}

void combined::save(const char name[]) {
	FILE *f;
	fopen_s(&f, name, "w");

	for (int i = 0; i < 3; i++)
		fprintf_s(f, "%d %d\n", Cpoints[i].x, Cpoints[i].y);

	fclose(f);
}
void combined::load(const char name[]) {
	FILE *f;
	fopen_s(&f, name, "rt");
	if (f == NULL) throw ERR_CANNOT_OPEN_INPUT_FILE;
	POINT Cpoints[3];

	for (int i = 0; i < 3; i++)
		fscanf_s(f, "%d%d", &(Cpoints[i].x), &(Cpoints[i].y));
	try
	{
		setFCPoints(Cpoints);
	}
	catch (int exception)
	{
		throw exception;
	}
	fclose(f);
}

void combined::checkSizeTC(POINT *new_Cpoints) {
	int a, b, c;
	for (int i = 0; i < 3; i++) {
		a = (points[0].x - new_Cpoints[i].x)*(points[1].y - points[0].y) - (points[1].x - points[0].x)*(points[0].y - new_Cpoints[i].y);
		b = (points[1].x - new_Cpoints[i].x)*(points[2].y - points[1].y) - (points[2].x - points[1].x)*(points[1].y - new_Cpoints[i].y);
		c = (points[2].x - new_Cpoints[i].x)*(points[0].y - points[2].y) - (points[0].x - points[2].x)*(points[2].y - new_Cpoints[i].y);
		if (!((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)))
			throw ERR_WRONG_CUT_POINTS;
	}
}

void combined::checkSizeT(HDC hdc) {
	RECT rt;
	GetClientRect(WindowFromDC(hdc), &rt);
	int rtx = rt.right;
	int rty = rt.bottom;
	for (int i = 0; i < 3; i++)
		if (points[i].x < 0 || points[i].y < 0)
			throw ERR_NEGATIVE_POINTS;
		else if (points[i].x > rtx || points[i].y > rty)
			throw ERR_WRONG_SIZE;
}