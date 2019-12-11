///////////////////////////////////////////////////////////
//  contour.h
//  Implementation of the Class contour
//  Created on:      11-дек-2019 23:55:24
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_0D61719A_326B_4ac8_ADB0_DFD73A1336E8__INCLUDED_)
#define EA_0D61719A_326B_4ac8_ADB0_DFD73A1336E8__INCLUDED_

#include "Triangle.h"

class contour : public Triangle
{

public:
	virtual ~contour();

	contour();
	void setStyle(int new_style);
	void getStyle(int & curr_style);
	void setColor(COLORREF new_color);
	void getColor(COLORREF & curr_color);
	void setBorder(int new_border);
	void getBorder(int & curr_border);
	void setPoints(POINT * new_points);
	void getPoints(POINT * curr_points);
	void Draw(HDC hdc);
	void save(const char* name);
	void load(const char* name);
	void checkSizeT(HDC hdc);

protected:
	COLORREF color;
	int border;
	int style;
	POINT points[3];

};
#endif // !defined(EA_0D61719A_326B_4ac8_ADB0_DFD73A1336E8__INCLUDED_)
