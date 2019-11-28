#ifndef COMBINED_H
#define COMBINED_H

#include "painted.h"
#include "contour.h"

class combined : public painted {		//������ � �������
private:
	painted ext;
	painted intern;
public:
	combined() {}
	combined(painted external, painted internal) : ext(external), intern(internal) {}

	void Draw(HDC hdc);
	void checkSizeTC();
};

#endif