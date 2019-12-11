///////////////////////////////////////////////////////////
//  brush.h
//  Implementation of the Class brush
//  Created on:      10-дек-2019 21:45:33
//  Original author: Kappa
///////////////////////////////////////////////////////////

#if !defined(EA_D2EC6E17_DFBC_41f5_A067_519653A217CF__INCLUDED_)
#define EA_D2EC6E17_DFBC_41f5_A067_519653A217CF__INCLUDED_

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
#endif // !defined(EA_D2EC6E17_DFBC_41f5_A067_519653A217CF__INCLUDED_)
