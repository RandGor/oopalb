#ifndef COMBINED_H
#define COMBINED_H

#include "painted.h"

class combined {
private:
	painted ext;
	painted intern;
public:
	combined() {};

	void Draw(HDC hdc);
	void addExt(painted Ext);
	void save(const char name[]);
	void load(const char name1[], const char name2[]);
	void checkSizeTC();

	void getIntern(painted &t);
	void getExt(painted &t);
};

#endif