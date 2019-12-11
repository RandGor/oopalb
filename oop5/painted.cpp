#include "painted.h"


painted::painted(brush Brush, contour Contour) {
	 Brush.getBColor(this->bcolor);
	 Brush.getBStyle(this->bstyle);

	 Contour.getPoints(this->points);
	 Contour.getBorder(this->border);
	 Contour.getColor(this->color);
	 Contour.getStyle(this->style);
}

void painted::Draw(HDC hdc) {
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
}

void painted::save(const char name[]) {
	brush::save(name);
	contour::save(name);
}

void painted::load(const char name1[], const char name2[]) {
	brush::load(name1);
	contour::load(name2);
}
