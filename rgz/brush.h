///////////////////////////////////////////////////////////
//  brush.h
//  Implementation of the Class brush
//  Created on:      11-дек-2019 23:55:23
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_A3503D64_505C_4ee5_8648_374DAF15A863__INCLUDED_)
#define EA_A3503D64_505C_4ee5_8648_374DAF15A863__INCLUDED_

class brush
{

public:
	brush();
	virtual ~brush();
	void setBStyle(int new_bstyle);
	void getBStyle(int& curr_bstyle);
	void setBColor(COLORREF new_bcolor);
	void getBColor(COLORREF& curr_bcolor);
	void save(const char* name);
	void load(const char* name);

protected:
	COLORREF bcolor;
	int bstyle;

};
#endif // !defined(EA_A3503D64_505C_4ee5_8648_374DAF15A863__INCLUDED_)
