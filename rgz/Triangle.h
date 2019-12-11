///////////////////////////////////////////////////////////
//  Triangle.h
//  Implementation of the Class Triangle
//  Created on:      11-дек-2019 23:55:24
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_88C31D38_6AF9_4d8b_B777_D90C4D39AB98__INCLUDED_)
#define EA_88C31D38_6AF9_4d8b_B777_D90C4D39AB98__INCLUDED_

class Triangle
{

public:
	Triangle();
	virtual ~Triangle();
	virtual void Draw(HDC hdc) =0;
	virtual void save(const char* name) =0;
	virtual void load(const char* name) =0;

};
#endif // !defined(EA_88C31D38_6AF9_4d8b_B777_D90C4D39AB98__INCLUDED_)
