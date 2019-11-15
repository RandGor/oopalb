#ifndef PAINTED_H
#define PAINTED_H

#include "brush.h"
#include "contour.h"

class painted : public brush, public contour {			// Закрашенная фигура
public:
	void Draw(HDC hdc);
};

#endif