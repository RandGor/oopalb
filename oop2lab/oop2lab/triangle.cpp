#include "triangle.h"

void Triangle::drawTriangle(HDC hdc) {
	checkSizeT(hdc);

	COLORREF buffcolor = bcolor;
	if (border == 0)
		buffcolor = color;

	HPEN hMyPen = CreatePen(bstyle, border, buffcolor);
	LOGBRUSH* logBrush = new LOGBRUSH;

	logBrush->lbStyle = (style == 0) ? BS_SOLID : BS_HATCHED;
	logBrush->lbHatch = style - 1;
	logBrush->lbColor = color;
	HBRUSH hMyBrush = CreateBrushIndirect(logBrush);

	SelectPen(hdc, hMyPen);
	SelectBrush(hdc, hMyBrush);
	Polygon(hdc, points, 3);
	DeletePen(hMyPen);
	delete logBrush;
	DeleteBrush(hMyBrush);
}

void Triangle::drawCounter(HDC hdc) {
	checkSizeT(hdc);
	HPEN hMyPen = CreatePen(bstyle, border, bcolor);
	SelectPen(hdc, hMyPen);
	POINT ppt[4] = { points[0],points[1],points[2],points[0] };
	Polyline(hdc, ppt, 4);
	DeletePen(hMyPen);
}
void Triangle::drawCut(HDC hdc) {
	checkSizeT(hdc);
	HPEN hMyPen = CreatePen(0, 0, RGB(0, 0, 0));
	HBRUSH hMyBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectPen(hdc, hMyPen);
	SelectBrush(hdc, hMyBrush);
	Polygon(hdc, Cpoints, 3);
	DeletePen(hMyPen);
	DeleteBrush(hMyBrush);
}

void Triangle::mainDraw(HDC hdc) {
	switch (mode)
	{
	case 0:
		drawTriangle(hdc);
		break;
	case 1:
		drawCounter(hdc);
		break;
	case 2:
		drawTriangle(hdc);
		drawCut(hdc);
		break;
	}
}

void Triangle::setMode(int new_mode) {
	if (mode < 0 || mode > 2) throw ERR_WRONG_MODE;
	mode = new_mode;
}

void Triangle::getMode(int &curr_mode) {
	curr_mode = mode;
}

void Triangle::setPoints(POINT *new_points) {
	for (int i = 0; i < 3; i++)
		if (new_points[i].x < 0 || new_points[i].y < 0)
			throw ERR_NEGATIVE_POINTS;
	if ((new_points[2].x - new_points[0].x)*(new_points[1].y - new_points[0].y) == (new_points[2].y - new_points[0].y)*(new_points[1].x - new_points[0].x))
		throw ERR_POINTS_ONLINE;
	for (int i = 0; i < 3; i++)
		points[i] = new_points[i];
}
void Triangle::getPoints(POINT *curr_points) {
	for (int i = 0; i < 3; i++) curr_points[i] = points[i];
}

void Triangle::setCPoints(POINT *new_Cpoints) {
	checkSizeTC(new_Cpoints);
	for (int i = 0; i < 3; i++)
		if (new_Cpoints[i].x < 0 || new_Cpoints[i].y < 0)
			throw ERR_NEGATIVE_POINTS;
	if ((new_Cpoints[2].x - new_Cpoints[0].x)*(new_Cpoints[1].y - new_Cpoints[0].y) == (new_Cpoints[2].y - new_Cpoints[0].y)*(new_Cpoints[1].x - new_Cpoints[0].x))
		throw ERR_POINTS_ONLINE;
	for (int i = 0; i < 3; i++)
		Cpoints[i] = new_Cpoints[i];
}

void Triangle::getCPoints(POINT *curr_Cpoints) {
	for (int i = 0; i < 3; i++) curr_Cpoints[i] = Cpoints[i];
}

void Triangle::setBorder(int new_border) {
	if (new_border < 0) throw ERR_NEGATIVE_BORDER;
	border = new_border;
}
void Triangle::getBorder(int &curr_border) {
	curr_border = border;
}

void Triangle::setStyle(int new_style) {
	if (new_style < 0 || new_style > 6) throw ERR_WRONG_STYLE;
	style = new_style;
}
void Triangle::getStyle(int &curr_style) {
	curr_style = style;
}

void Triangle::setColor(COLORREF new_color) {
	if (GetRValue(new_color) > 255 || GetRValue(new_color) < 0 || GetGValue(new_color) > 255 || GetGValue(new_color) < 0 || GetBValue(new_color) > 255 || GetBValue(new_color) < 0) throw ERR_WRONG_COLOR;
	color = new_color;
}
void Triangle::getColor(COLORREF &curr_color) {
	curr_color = color;
}

void Triangle::setBStyle(int new_bstyle) {
	if (new_bstyle < 0 || new_bstyle > 6) throw ERR_WRONG_BSTYLE;
	bstyle = new_bstyle;
}
void Triangle::getBStyle(int &curr_bstyle) {
	curr_bstyle = bstyle;
}

void Triangle::setBColor(COLORREF new_bcolor) {
	if (GetRValue(new_bcolor) > 255 || GetRValue(new_bcolor) < 0 || GetGValue(new_bcolor) > 255 || GetGValue(new_bcolor) < 0 || GetBValue(new_bcolor) > 255 || GetBValue(new_bcolor) < 0) throw ERR_WRONG_BCOLOR;
	bcolor = new_bcolor;
}
void Triangle::getBColor(COLORREF &curr_bcolor) {
	curr_bcolor = bcolor;
}

void Triangle::checkSizeTC(POINT *new_Cpoints) {
	int a, b, c;
	for (int i = 0; i < 3; i++) {
		a = (points[0].x - new_Cpoints[i].x)*(points[1].y - points[0].y) - (points[1].x - points[0].x)*(points[0].y - new_Cpoints[i].y);
		b = (points[1].x - new_Cpoints[i].x)*(points[2].y - points[1].y) - (points[2].x - points[1].x)*(points[1].y - new_Cpoints[i].y);
		c = (points[2].x - new_Cpoints[i].x)*(points[0].y - points[2].y) - (points[0].x - points[2].x)*(points[2].y - new_Cpoints[i].y);
		if (!((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)))
			throw ERR_WRONG_CUT_POINTS;
	}
}

void Triangle::checkSizeT(int rtx, int rty) {
	for (int i = 0; i < 3; i++)
		if (points[i].x < 0 || points[i].y < 0)
			throw ERR_NEGATIVE_POINTS;
		else if (points[i].x > rtx || points[i].y > rty)
			throw ERR_WRONG_SIZE;
}

void Triangle::checkSizeT(HDC hdc) {
	RECT rt;
	GetClientRect(WindowFromDC(hdc), &rt);
	int rtx = rt.right;
	int rty = rt.bottom;
	checkSizeT(rtx, rty);
}

void Triangle::readInf(const char name[]) {
	FILE *f;
	fopen_s(&f, name, "rt");
	if (f == NULL)
		throw ERR_CANNOT_OPEN_INPUT_FILE;
	int brgb[3], rgb[3], style, bstyle, border;
	COLORREF bcolor, color;
	POINT points[3], Cpoints[3];

	fscanf_s(f, "%d", &mode);									//mode
	for (int i = 0; i < 3; i++)
		fscanf_s(f, "%d%d", &(points[i].x), &(points[i].y));	//points
	fscanf_s(f, "%d", &(style));								//style
	for (int i = 0; i < 3; i++)									//color
		fscanf_s(f, "%d", &(rgb[i]));
	color = RGB(rgb[0], rgb[1], rgb[2]);

	fscanf_s(f, "%d", &(border));								//border
	fscanf_s(f, "%d", &(bstyle));								//bstyle
	for (int i = 0; i < 3; i++)									//bcolor					
		fscanf_s(f, "%d", &(brgb[i]));
	bcolor = RGB(brgb[0], brgb[1], brgb[2]);


	if (mode == 2)
		for (int i = 0; i < 3; i++)
			fscanf_s(f, "%d%d", &(Cpoints[i].x), &(Cpoints[i].y));
	try
	{
		setPoints(points);
		setStyle(style);
		setColor(color);
		setBStyle(bstyle);
		setBColor(bcolor);
		setBorder(border);
		if (mode == 2)
			setCPoints(Cpoints);
	}
	catch (int exception)
	{
		throw exception;
	}

	fclose(f);
}

void Triangle::saveInf(const char name[]) {
	FILE *f;
	fopen_s(&f, name, "w");
	int brgb[3], rgb[3];

	fprintf_s(f, "%d\n\n", mode);								//mode

	for (int i = 0; i < 3; i++)
		fprintf_s(f, "%d %d\n", points[i].x, points[i].y);		//points

	fprintf_s(f, "\n%d\n", style);								//style

	rgb[0] = GetRValue(color);
	rgb[1] = GetGValue(color);
	rgb[2] = GetBValue(color);

	for (int i = 0; i < 3; i++)									//color
		fprintf_s(f, "%d ", rgb[i]);

	fprintf_s(f, "\n\n%d\n\n", border);							//border
	fprintf_s(f, "\n\n%d\n", bstyle);							//bstyle

	brgb[0] = GetRValue(bcolor);
	brgb[1] = GetGValue(bcolor);
	brgb[2] = GetBValue(bcolor);

	for (int i = 0; i < 3; i++)									//bcolor					
		fprintf_s(f, "%d ", brgb[i]);


	if (mode == 2)
		for (int i = 0; i < 3; i++)									//Cpoints(ToCut)
			fprintf_s(f, "%d %d\n", Cpoints[i].x, Cpoints[i].y);
	fclose(f);
}
void Triangle::move_horizontally(int delta) {
	for (int i = 0; i < 3; i++) {
		points[i].x += delta;
		if (mode == 2)
			Cpoints[i].x += delta;
	}
}

void Triangle::move_vertically(int delta) {
	for (int i = 0; i < 3; i++) {
		points[i].y += delta;
		if (mode == 2)
			Cpoints[i].y += delta;
	}
}
