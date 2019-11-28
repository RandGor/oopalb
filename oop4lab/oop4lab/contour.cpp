#include "contour.h"
#include "error.h"

void contour::setStyle(int new_style) {
	if (new_style < 0 || new_style > 6) throw ERR_WRONG_STYLE;
	style = new_style;
}
void contour::getStyle(int &curr_style) {
	curr_style = style;
}

void contour::setColor(COLORREF new_color) {
	if (GetRValue(new_color) > 255 || GetRValue(new_color) < 0 || GetGValue(new_color) > 255 || GetGValue(new_color) < 0 || GetBValue(new_color) > 255 || GetBValue(new_color) < 0) throw ERR_WRONG_COLOR;
	color = new_color;
}
void contour::getColor(COLORREF &curr_color) {
	curr_color = color;
}

void contour::setBorder(int new_border) {
	if (new_border < 0) throw ERR_NEGATIVE_BORDER;
	border = new_border;
}
void contour::getBorder(int &curr_border) {
	curr_border = border;
}

void contour::setPoints(POINT *new_points) {
	for (int i = 0; i < 3; i++)
		if (new_points[i].x < 0 || new_points[i].y < 0)
			throw ERR_NEGATIVE_POINTS;
	if ((new_points[2].x - new_points[0].x)*(new_points[1].y - new_points[0].y) == (new_points[2].y - new_points[0].y)*(new_points[1].x - new_points[0].x))
		throw ERR_POINTS_ONLINE;
	for (int i = 0; i < 3; i++)
		points[i] = new_points[i];
}
void contour::getPoints(POINT *curr_points) {
	for (int i = 0; i < 3; i++) curr_points[i] = points[i];
}

void contour::Draw(HDC hdc) {
	checkSizeT(hdc);
	HPEN hMyPen = CreatePen(style, border, color);
	SelectPen(hdc, hMyPen);
	POINT ppt[4] = { points[0],points[1],points[2],points[0] };
	Polyline(hdc, ppt, 4);
	DeletePen(hMyPen);
}

void contour::save(const char name[]) {
	FILE *f;
	fopen_s(&f, name, "w");
	int rgb[3];

	for (int i = 0; i < 3; i++)
		fprintf_s(f, "%d %d\n", points[i].x, points[i].y);

	fprintf_s(f, "\n%d", style);
	fprintf_s(f, "%d\n", border);
	rgb[0] = GetRValue(color);
	rgb[1] = GetGValue(color);
	rgb[2] = GetBValue(color);

	for (int i = 0; i < 3; i++)
		fprintf_s(f, "%d ", rgb[i]);

	

	fclose(f);
}
void contour::load(const char name[]) {
	FILE *f;
	fopen_s(&f, name, "rt");
	if (f == NULL) throw ERR_CANNOT_OPEN_INPUT_FILE;
	int rgb[3], style, border;
	COLORREF color;
	POINT points[3];

	for (int i = 0; i < 3; i++)
		fscanf_s(f, "%d%d", &(points[i].x), &(points[i].y));

	fscanf_s(f, "%d", &(style));
	fscanf_s(f, "%d", &(border));

	for (int i = 0; i < 3; i++)
		fscanf_s(f, "%d", &(rgb[i]));
	color = RGB(rgb[0], rgb[1], rgb[2]);


	try
	{
		setPoints(points);
		setStyle(style);
		setColor(color);
		setBorder(border);
	}
	catch (int exception)
	{
		throw exception;
	}

	fclose(f);
}

void contour::checkSizeT(HDC hdc) {
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