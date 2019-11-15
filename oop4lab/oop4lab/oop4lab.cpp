#include "external.h"
#include "combined.h"
#include "error.h"

void main()
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	bool tosleep = false;

	Triangle *triangle;
	brush Brush = brush();
	contour Contour = contour();
	painted Painted = painted();
	combined Combined = combined();

	char c = 0;
	do
	{
		clearConsole();
		printf_s("Menu:\n1 - Load data\n2 - Save data\n3 - Draw figure\nEsc - Exit\n");
		c = _getch();
		try
		{
			//if (_kbhit()) {
				//clearConsole();
				//printf_s("Menu:\n1 - Load data\n2 - Save data\n3 - Draw figure\nEsc - Exit\n");
				//c = _getch();

				switch (c)
				{
				case 49:	//1 - Load
					clearConsole();
					printf_s("Menu:\n1 - Load brush\n2 - Load contour\n3 - Load points to combined figure\n4 - Exit\n");
					c = _getch();
					clearConsole();
					switch (c)
					{
					case 49:	//1 - Brush
						Brush.load("inbrush.txt");
						printf_s("Brush data loaded.");
						break;
					case 50:	//2 - Contour
						Contour.load("incontour.txt");
						printf_s("Contour data loaded.");
						break;
					case 51:	//2 - Points to combined
						Combined.load("incombined.txt");
						printf_s("Combined data loaded.");
						break;
					}
					break;
				case 50:	//2 - Save
					clearConsole();
					printf_s("Menu:\n1 - Save brush\n2 - Save contour\n3 - Save points to combined figure\n4 - Exit\n");
					c = _getch();
					clearConsole();
					switch (c)
					{
					case 49:	//1 - Brush
						Brush.save("outbrush.txt");
						printf_s("Brush data saved.");
						break;
					case 50:	//2 - Contour
						Contour.save("outcontour.txt");
						printf_s("Contour data saved.");
						break;
					case 51:	//2 - Points to combined
						Combined.save("outcombined.txt");
						printf_s("Contour data saved.");
						break;
					}
					break;
				case 51:	//3 - Draw

					clearConsole();
					printf_s("Menu:\n1 - Draw contour\n2 - Draw painted figure\n3 - Draw combined figure\n4 - Exit\n");
					c = _getch();
					RECT rt;

					int oldx = 0, oldy = 0;
					int rtx = 0, rty = 0;
					do {
						tosleep = true;
						clearConsole();
						GetClientRect(hwnd, &rt);
						rtx = rt.right;
						rty = rt.bottom;

						if (oldx != rtx || oldy != rty) {
							hidecursor();
							clearConsole();
							oldx = rtx;
							oldy = rty;

							Sleep(50);
							tosleep = false;
						}


							try
							{
								switch (c)
								{
								case 49:	//1 - Contour
									triangle = &Contour;
									triangle->Draw(hdc);
									break;
								case 50:	//2 - Painted
									triangle = &Painted;
									triangle->Draw(hdc);
									break;
								case 51:	//3 - Combined
									triangle = &Combined;
									triangle->Draw(hdc);
									break;
								}
							}
							catch (int exception)
							{
								printf_s("Increase window size(current is %d : %d)", rtx, rty);
							}
						if (_kbhit()) {
							c = _getch();
						}
						if (tosleep)
							Sleep(50);
					} while (c != 13);
					clearConsole();

					break;
				}
			//}
		}
		catch (int exception)
		{
			switch (exception)
			{
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
			case ERR_CANNOT_OPEN_INPUT_FILE:
				printf_s("Cannot open input file");
				break;
			}
			printf_s("\nPress any key to go back to menu");
			_getch();
		}
	} while (c != 27);

	ReleaseDC(hwnd, hdc);
}