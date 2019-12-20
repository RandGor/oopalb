///////////////////////////////////////////////////////////
//  painted.h
//  Implementation of the Class painted
//  Created on:      20-дек-2019 12:34:03
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_1FA6AECE_C988_4c7b_ABB3_933CEF4930CE__INCLUDED_)
#define EA_1FA6AECE_C988_4c7b_ABB3_933CEF4930CE__INCLUDED_

#include "contour.h"
#include "brush.h"

class painted : public brush, public contour
{

public:
	painted();
	painted(brush Brush, contour Contour);
	virtual ~painted();
	void Draw(HDC hdc);
	void load(const char* name1, const char* name2);
	void save(const char* name);

};
#endif // !defined(EA_1FA6AECE_C988_4c7b_ABB3_933CEF4930CE__INCLUDED_)
