#include "brush.h"
#include "error.h"

void brush::setBStyle(int new_bstyle) {
	if (new_bstyle < 0 || new_bstyle > 6) throw ERR_WRONG_BSTYLE;
	bstyle = new_bstyle;
}
void brush::getBStyle(int &curr_bstyle) {
	curr_bstyle = bstyle;
}

void brush::setBColor(COLORREF new_bcolor) {
	if (GetRValue(new_bcolor) > 255 || GetRValue(new_bcolor) < 0 || GetGValue(new_bcolor) > 255 || GetGValue(new_bcolor) < 0 || GetBValue(new_bcolor) > 255 || GetBValue(new_bcolor) < 0) throw ERR_WRONG_BCOLOR;
	bcolor = new_bcolor;
}
void brush::getBColor(COLORREF &curr_bcolor) {
	curr_bcolor = bcolor;
}

void brush::save(const char name[]) {
	FILE *f;
	fopen_s(&f, name, "at");
	int brgb[3];

	fprintf_s(f, "%d\n", bstyle);								//bstyle

	brgb[0] = GetRValue(bcolor);
	brgb[1] = GetGValue(bcolor);
	brgb[2] = GetBValue(bcolor);

	for (int i = 0; i < 3; i++)									//bcolor					
		fprintf_s(f, "%d ", brgb[i]);

	fclose(f);
}
void brush::load(const char name[]) {
	FILE *f;
	fopen_s(&f, name, "rt");
	if (f == NULL)
		throw ERR_CANNOT_OPEN_INPUT_FILE;
	int brgb[3], bstyle;
	COLORREF bcolor;

	fscanf_s(f, "%d", &(bstyle));								//bstyle
	for (int i = 0; i < 3; i++)									//bcolor					
		fscanf_s(f, "%d", &(brgb[i]));
	bcolor = RGB(brgb[0], brgb[1], brgb[2]);

	try
	{
		setBStyle(bstyle);
		setBColor(bcolor);
	}
	catch (int exception)
	{
		throw exception;
	}
	fclose(f);
}