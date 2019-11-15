#ifndef ERROR_H
#define ERROR_H

#define ERR_CANNOT_OPEN_INPUT_FILE -2
#define ERR_WRONG_SIZE -1
#define ERR_NEGATIVE_POINTS 0
#define ERR_POINTS_ONLINE 1
#define ERR_NEGATIVE_BORDER 2
#define ERR_WRONG_STYLE 3
#define ERR_WRONG_BSTYLE 4
#define ERR_WRONG_COLOR 5
#define ERR_WRONG_BCOLOR 6
#define ERR_WRONG_CUT_POINTS 7

class error {
public:
	virtual void checkSizeT(HDC hdc) = 0;
	virtual void checkSizeTC(HDC hdc) = 0;
};

#endif