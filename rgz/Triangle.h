///////////////////////////////////////////////////////////
//  Triangle.h
//  Implementation of the Class Triangle
//  Created on:      20-дек-2019 12:33:38
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_4F9AE8D4_E76F_459d_BC76_A2E1F4E0A0B6__INCLUDED_)
#define EA_4F9AE8D4_E76F_459d_BC76_A2E1F4E0A0B6__INCLUDED_

class Triangle
{

public:
	Triangle();
	virtual ~Triangle();
	virtual void Draw(HDC hdc) =0;
	virtual void load(const char* name) =0;
	virtual void save(const char* name) =0;

};
#endif // !defined(EA_4F9AE8D4_E76F_459d_BC76_A2E1F4E0A0B6__INCLUDED_)
