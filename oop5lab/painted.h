#ifndef PAINTED_H
#define PAINTED_H

#include "brush.h"
#include "contour.h"

class painted : public brush, public contour {			// Закрашенная фигура
public:
	painted() {}
	painted(brush Brush, contour Contour);

	void Draw(HDC hdc);
};

#endif