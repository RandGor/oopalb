#ifndef COMBINED_H
#define COMBINED_H

#include "painted.h"
#include "contour.h"

class combined : public painted {		//Фигура с вырезом
private:
	POINT Cpoints[3];
public:
	combined() : Cpoints{NULL,NULL, NULL} {}
	combined(POINT Cpoints[3]) : Cpoints{ Cpoints[0],Cpoints[1], Cpoints[2] } {}

	void setFCPoints(POINT *new_Cpoints);
	void getFCPoints(POINT *&curr_Cpoints);

	void Draw(HDC hdc);
	void save(const char name[]);
	void load(const char name[]);

	void checkSizeTC(POINT *new_Cpoints);
	void checkSizeT(HDC hdc);
};

#endif