#include "painted.h"

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