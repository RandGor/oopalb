///////////////////////////////////////////////////////////
//  painted.h
//  Implementation of the Class painted
//  Created on:      11-дек-2019 23:55:24
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_093713F2_6FA4_44a4_839D_8CD5D79036A5__INCLUDED_)
#define EA_093713F2_6FA4_44a4_839D_8CD5D79036A5__INCLUDED_

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
#endif // !defined(EA_093713F2_6FA4_44a4_839D_8CD5D79036A5__INCLUDED_)
