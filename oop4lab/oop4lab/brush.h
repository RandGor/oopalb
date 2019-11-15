#ifndef BRUSH_H
#define BRUSH_H

#include "triangle.h"
#include "error.h"

class brush {		//Кисть
protected:
	COLORREF bcolor;
	int bstyle;
public:
	brush() {};

	void setBStyle(int new_bstyle);
	void getBStyle(int &curr_bstyle);

	void setBColor(COLORREF new_bcolor);
	void getBColor(COLORREF &curr_bcolor);

	void save(const char name[]);
	void load(const char name[]);
};

#endif