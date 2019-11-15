#ifndef CONTOUR_H
#define CONTOUR_H

#include "triangle.h"

class contour : public Triangle {		//Фигура-контур..Перо
protected:
	COLORREF color;
	int style, border;
	POINT points[3];
public:
	contour() : color(NULL), style(NULL), border(NULL), points{NULL, NULL, NULL} {}

	void setStyle(int new_bstyle);
	void getStyle(int &curr_bstyle);

	void setColor(COLORREF new_bcolor);
	void getColor(COLORREF &curr_bcolor);

	void setBorder(int new_border);
	void getBorder(int &curr_border);

	void setPoints(POINT *new_points);
	void getPoints(POINT *curr_points);

	void Draw(HDC hdc);
	void save(const char name[]);
	void load(const char name[]);

	void checkSizeT(HDC hdc);
};

#endif