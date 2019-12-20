///////////////////////////////////////////////////////////
//  brush.h
//  Implementation of the Class brush
//  Created on:      20-дек-2019 12:33:56
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_0184FF9C_5E11_4f15_A47F_0D49171E1B4E__INCLUDED_)
#define EA_0184FF9C_5E11_4f15_A47F_0D49171E1B4E__INCLUDED_

class brush
{

public:
	brush();
	virtual ~brush();
	void getBColor(COLORREF& curr_bcolor);
	void getBStyle(int& curr_bstyle);
	void load(const char* name);
	void save(const char* name);
	void setBColor(COLORREF new_bcolor);
	void setBStyle(int new_bstyle);

protected:
	COLORREF bcolor;
	int bstyle;

};
#endif // !defined(EA_0184FF9C_5E11_4f15_A47F_0D49171E1B4E__INCLUDED_)
