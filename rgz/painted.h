///////////////////////////////////////////////////////////
//  painted.h
//  Implementation of the Class painted
//  Created on:      10-дек-2019 21:45:33
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_66BB75F3_73E0_4c9b_8179_9614F695FE9D__INCLUDED_)
#define EA_66BB75F3_73E0_4c9b_8179_9614F695FE9D__INCLUDED_

#include "contour.h"
#include "brush.h"

class painted : public brush, public contour
{

public:
	painted();
	painted(brush Brush, contour Contour);
	virtual ~painted();
	void load(const char* name1, const char* name2);
	void save(const char* name);
	void Draw(HDC hdc);

};
#endif // !defined(EA_66BB75F3_73E0_4c9b_8179_9614F695FE9D__INCLUDED_)
