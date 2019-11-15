#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <windows.h>  
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include "error.h"

class Triangle {
public:
	virtual void Draw(HDC hdc) = 0;
	virtual void load(const char name[]) = 0;
	virtual void save(const char name[]) = 0;
};

#endif