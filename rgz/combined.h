///////////////////////////////////////////////////////////
//  combined.h
//  Implementation of the Class combined
//  Created on:      20-дек-2019 12:34:09
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_0517600C_24E6_4425_BCFB_E6F859F1C38C__INCLUDED_)
#define EA_0517600C_24E6_4425_BCFB_E6F859F1C38C__INCLUDED_

#include "painted.h"

class combined
{

public:
	virtual ~combined();

	combined();
	void addExt(painted Ext);
	void checkSizeTC();
	void Draw(HDC hdc);
	void getExt(painted& t);
	void getIntern(painted& t);
	void load(const char* name1, const char* name2);
	void save(const char* name);

private:
	painted ext;
	painted intern;

};
#endif // !defined(EA_0517600C_24E6_4425_BCFB_E6F859F1C38C__INCLUDED_)
