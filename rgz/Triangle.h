///////////////////////////////////////////////////////////
//  Triangle.h
//  Implementation of the Class Triangle
//  Created on:      10-дек-2019 21:45:34
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_7CEE42E1_2890_4d3e_AEA9_113FB3083A04__INCLUDED_)
#define EA_7CEE42E1_2890_4d3e_AEA9_113FB3083A04__INCLUDED_

class Triangle
{

public:
	Triangle();
	virtual ~Triangle();
	virtual void Draw(HDC hdc) =0;
	virtual void save(const char* name) =0;
	virtual void load(const char* name) =0;

};
#endif // !defined(EA_7CEE42E1_2890_4d3e_AEA9_113FB3083A04__INCLUDED_)
