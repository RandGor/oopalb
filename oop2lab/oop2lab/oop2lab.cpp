#include "external.h"
#include "triangle.h"

void main()
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	RECT rt;
	HPEN hOldPen = GetStockPen(BLACK_PEN);
	HBRUSH hOldBrush = GetStockBrush(WHITE_BRUSH);

	int oldx = 0, oldy = 0;
	int rtx = 0, rty = 0;
	Triangle triangle = Triangle();
	int mode;
	int shift = 2;
	bool tosleep = false;
	hidecursor();
	try
	{
		triangle.readInf("input.txt");
		triangle.getMode(mode);
		char c = 0;
		do {
			tosleep = true;
			GetClientRect(hwnd, &rt);
			rtx = rt.right;
			rty = rt.bottom;
			if (oldx != rtx || oldy != rty)
			{
				hidecursor();
				clearConsole();
				oldx = rtx;
				oldy = rty;
				try
				{
					Sleep(50);
					tosleep = false;
					triangle.mainDraw(hdc);
				}
				catch (int exception)
				{
					printf_s("Increase window size(current is %d : %d)", rtx, rty);
				}
			}
			if (_kbhit()) {
				c = _getch();
				switch (c)
				{
				case 49:
					triangle.saveInf("output.txt");
					printf_s("\t\tPreset saved.");
					break;
				case 119:
					triangle.move_vertically(-shift);
					break;
				case 115:
					triangle.move_vertically(shift);
					break;
				case 97:
					triangle.move_horizontally(-shift);
					break;
				case 100:
					triangle.move_horizontally(shift);
					break;
				case 113:
					triangle.move_vertically(-shift);
					triangle.move_horizontally(-shift);
					break;
				case 122:
					triangle.move_vertically(shift);
					triangle.move_horizontally(-shift);
					break;
				case 101:
					triangle.move_vertically(-shift);
					triangle.move_horizontally(shift);
					break;
				case 99:
					triangle.move_vertically(shift);
					triangle.move_horizontally(shift);
					break;
				}
				try
				{
					if (c==49 || c == 119 || c == 115 || c == 97 || c == 100 || c == 113 || c == 122 || c == 101 || c == 99)
					{
						clearConsole();
						Sleep(50);
						tosleep = false;
						triangle.mainDraw(hdc);
					}
				}
				catch (int exception)
				{
					switch (exception)
					{
						case ERR_NEGATIVE_POINTS:
							printf_s("Negative coords");
							break;
						case ERR_WRONG_SIZE:
							printf_s("Increase window size(current is %d : %d)", rtx, rty);
							break;
						default:
							throw exception;
					}
				}
			}
			if (tosleep)
				Sleep(50);
		} while (c != 27);
		clearConsole();
	}
	catch (int exception)
	{
		clearConsole();
		switch (exception)
		{
		case ERR_CANNOT_OPEN_INPUT_FILE:
			printf_s("Can not open input file");
			break;
		case ERR_WRONG_MODE:
			printf_s("Wrong mode (should be in range [0,2])");
			break;
		case ERR_NEGATIVE_POINTS:
			printf_s("Negative coords");
			break;
		case ERR_POINTS_ONLINE:
			printf_s("Points belong to line");
			break;
		case ERR_NEGATIVE_BORDER:
			printf_s("Negative border value");
			break;
		case ERR_WRONG_STYLE:
			printf_s("Wrong brush style value(should be in range[0,6])");
			break;
		case ERR_WRONG_BSTYLE:
			printf_s("Wrong pen style value(should be in range[0, 6])");
			break;
		case ERR_WRONG_COLOR:
			printf_s("Wrong brush color value (each color should be in range[0,255])");
			break;
		case ERR_WRONG_BCOLOR:
			printf_s("Wrong pen color value (each color should be in range[0,255])");
			break;
		case ERR_WRONG_CUT_POINTS:
			printf_s("Second triangle cannot be placed in the first one");
			break;
		}
		_getch();
	}
	SelectPen(hdc, hOldPen);
	SelectBrush(hdc, hOldBrush);
	ReleaseDC(hwnd, hdc);
}