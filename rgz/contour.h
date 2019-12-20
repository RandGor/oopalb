///////////////////////////////////////////////////////////
//  contour.h
//  Implementation of the Class contour
//  Created on:      20-дек-2019 12:33:50
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_8ADD8F40_A3A0_4446_BE2F_825E59912EA8__INCLUDED_)
#define EA_8ADD8F40_A3A0_4446_BE2F_825E59912EA8__INCLUDED_

#include "Triangle.h"

class contour : public Triangle
{

public:
	virtual ~contour();

	contour();
	void checkSizeT(HDC hdc);
	void Draw(HDC hdc);
	void getBorder(int & curr_border);
	void getColor(COLORREF & curr_color);
	void getPoints(POINT * curr_points);
	void getStyle(int & curr_style);
	void load(const char* name);
	void save(const char* name);
	void setBorder(int new_border);
	void setColor(COLORREF new_color);
	void setPoints(POINT * new_points);
	void setStyle(int new_style);

protected:
	int border;
	COLORREF color;
	POINT points[3];
	int style;

};
#endif // !defined(EA_8ADD8F40_A3A0_4446_BE2F_825E59912EA8__INCLUDED_)
