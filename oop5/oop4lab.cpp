#include "external.h"
#include "combined.h"
#include "error.h"
#include "stack.h"
#define N 30

void main()
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	bool tosleep = false;

	Triangle *triangle;
	brush Brush;
	painted SecPainted;

	contour Contour;
	painted MainPainted;
	combined Combined;

	Stack<contour> stack_c = Stack<contour>(N);
	Stack<painted> stack_p = Stack<painted>(N);
	Stack<combined> stack_cb = Stack<combined>(N);

	RECT rt;
	int oldx = 0, oldy = 0;
	int rtx = 0, rty = 0;

	char c = 0;
	printf_s("Menu:\n1 - Push into stack\n2 - Pop from stack\n3 - Print stack\n4 - Find figure in stack by color\n5 - Save stack into file\n6 - Draw figure in buffer\n7 - Load figure into buffer from file\nEsc - Exit\n");
	do
	{
		try
		{
			if (_kbhit()) {
				clearConsole();
				printf_s("Menu:\n1 - Push into stack\n2 - Pop from stack\n3 - Print stack\n4 - Find figure in stack by color\n5 - Save stack into file\n6 - Draw figure in buffer\n7 - Load figure into buffer from file\nEsc - Exit\n");
				c = _getch();
				switch (c)
				{
				case 49:	//1 - push
					clearConsole();
					printf_s("Stack for\n1 - Contours\n2 - Painted triangles\n3 - Combined figures\n");
					c = _getch();
					switch (c)
					{
					case 49:	//1 - push contour
						stack_c.Push(Contour);
						printf_s("Element pushed successfully!\n");
						break;
					case 50:	//2 - push painted
						stack_p.Push(MainPainted);
						printf_s("Element pushed successfully!\n");
						break;
					case 51:	//3 - push combined
						stack_cb.Push(Combined);
						printf_s("Element pushed successfully!\n");
						break;
					}
					break;
				case 50:	//2 - pop
					clearConsole();
					printf_s("Stack for\n1 - Contours\n2 - Painted triangles\n3 - Combined figures\n");
					c = _getch();
					switch (c)
					{
					case 49:	//1 - pop contour
						Contour = stack_c.Pop();
						printf_s("Element popped successfully!\n");
						break;
					case 50:	//2 - pop painted
						MainPainted = stack_p.Pop();
						printf_s("Element popped successfully!\n");
						break;
					case 51:	//3 - pop combined
						Combined = stack_cb.Pop();
						printf_s("Element popped successfully!\n");
						break;
					}
					break;
				case 51:	//3 - print
					clearConsole();
					printf_s("Stack for\n1 - Contours\n2 - Painted triangles\n3 - Combined figures\n");
					c = _getch();
					switch (c)
					{
					case 49:	//1 - print contour
						clearConsole();
						stack_c.Print(hdc);
						break;
					case 50:	//2 - print painted
						clearConsole();
						stack_p.Print(hdc);
						break;
					case 51:	//3 - print combined
						clearConsole();
						stack_cb.Print(hdc);
						break;
					}
					break;
				case 52:	//4 - find
					clearConsole();
					printf_s("Stack for\n1 - Contours\n2 - Painted triangles\n3 - Combined figures\n");
					c = _getch();
					int color[3];
					switch (c)
					{
					case 49:	//1 - find contour
						printf_s("Set color in format R G B : \n");
						for (int i = 0; i < 3; i++) scanf_s("%d", &color[i]);

						Contour = stack_c.find(color);
						printf_s("contour found and buffered!\n");
						break;
					case 50:	//2 - find painted
						printf_s("Set color in format R G B : \n");
						for (int i = 0; i < 3; i++) scanf_s("%d", &color[i]);

						MainPainted = stack_p.find(color);
						printf_s("painted found and buffered!\n");
						break;
					case 51:	//3 - find combined
						printf_s("Set color in format R G B : \n");
						for (int i = 0; i < 3; i++) scanf_s("%d", &color[i]);

						Combined = stack_cb.find(color);
						printf_s("Triangle found and buffered!\n");
						break;
					}
					break;
				case 53:	//5 - save
					clearConsole();
					printf_s("Stack for\n1 - Contours\n2 - Painted triangles\n3 - Combined figures\n");
					c = _getch();
					FILE *f;
					switch (c)
					{
					case 49:	//1 - save contour
						fopen_s(&f, "stackout_cont.txt", "w");
						fclose(f);
						stack_c.Save("stackout_cont.txt");
						printf_s("Your stack with contours saved into stackout_contour.txt\n");
						break;
					case 50:	//2 - save painted
						fopen_s(&f, "stackout_painted.txt", "w");
						fclose(f);
						stack_p.Save("stackout_painted.txt");
						printf_s("Your stack with painted triangles saved into stackout_painted.txt\n");
						break;
					case 51:	//3 - save combined
						fopen_s(&f, "stackout_comb.txt", "w");
						fclose(f);
						stack_cb.Save("stackout_comb.txt");
						printf_s("Your stack with combined figures saved into stackout_comb.txt\n");
						break;
					}
					break;
				case 54:	//6 - рисование текущего треугольника
					clearConsole();
					printf_s("Stack for\n1 - Contours\n2 - Painted triangles\n3 - Combined figures\n");
					c = _getch();
					
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
								triangle = &MainPainted;
								triangle->Draw(hdc);
								break;
							case 51:	//3 - Combined
								Combined.Draw(hdc);
								break;
							}
						}
						catch (int exception)
						{
							switch (exception) {
							case ERR_WRONG_SIZE:
								printf_s("Increase window size(current is %d : %d)", rtx, rty);
								break;
							case ERR_WRONG_CUT_POINTS:
								printf_s("Second triangle cannot be placed in the first one");
								break;
							}
						}
						if (_kbhit()) {
							c = _getch();
						}
						if (tosleep)
							Sleep(50);
					} while (c != 13);
					clearConsole();

					break;
				case 55:	//7 - загрузить треугольник из файла
					clearConsole();
					printf_s("Stack for\n1 - Contours\n2 - Painted triangles\n3 - Combined figures\n");
					c = _getch();
					switch (c)
					{
					case 49:	//1 - load contour
						Contour.load("incontour.txt");
						printf_s("Contour loaded succesfully!\n");
						break;
					case 50:	//2 - load painted
						Brush.load("inbrush.txt");
						printf_s("Painted triangle loaded succesfully!\n");
						MainPainted = painted(Brush, Contour);
						break;
					case 51:	//3 - load combined
						Combined.load("inbrush_combined.txt", "incontour_combined.txt");
						printf_s("Combined figure loaded succesfully!\n");
						Combined.addExt(MainPainted);
						break;
					}
					break;
				}
			}
		}
		catch (int exception)
		{
			switch (exception)
			{
			case ERR_EMPTY:
				printf_s("Can't pop/print any element! Your stack is empty.\n");
				break;
			case ERR_FULL:
				printf_s("Can't add an element! Your stack is full.\n");
				break;
			case ERR_NOT_FOUND:
				printf_s("There is no triangle with such color.\n");
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