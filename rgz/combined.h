///////////////////////////////////////////////////////////
//  combined.h
//  Implementation of the Class combined
//  Created on:      10-дек-2019 21:45:33
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_1EE96F87_12D3_4a84_99AA_3FDBC197BEA7__INCLUDED_)
#define EA_1EE96F87_12D3_4a84_99AA_3FDBC197BEA7__INCLUDED_

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
#endif // !defined(EA_1EE96F87_12D3_4a84_99AA_3FDBC197BEA7__INCLUDED_)
