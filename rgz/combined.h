///////////////////////////////////////////////////////////
//  combined.h
//  Implementation of the Class combined
//  Created on:      11-дек-2019 23:55:23
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_188087E6_A419_478b_A50A_237C2B96A03B__INCLUDED_)
#define EA_188087E6_A419_478b_A50A_237C2B96A03B__INCLUDED_

#include "painted.h"

class combined
{

public:
	virtual ~combined();

	combined();
	void Draw(HDC hdc);
	void addExt(painted Ext);
	void save(const char* name);
	void load(const char* name1, const char* name2);
	void checkSizeTC();
	void getIntern(painted& t);
	void getExt(painted& t);

private:
	painted ext;
	painted intern;

};
#endif // !defined(EA_188087E6_A419_478b_A50A_237C2B96A03B__INCLUDED_)
