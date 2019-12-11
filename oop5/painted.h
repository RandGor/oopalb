#ifndef PAINTED_H
#define PAINTED_H

#include "brush.h"
#include "contour.h"

class painted : public brush, public contour {			// ����������� ������
public:
	painted() {}
	painted(brush Brush, contour Contour);

	void save(const char name[]);
	void load(const char name1[], const char name2[]);

	void Draw(HDC hdc);
};

#endif