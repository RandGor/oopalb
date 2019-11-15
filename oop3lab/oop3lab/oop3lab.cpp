#include "external.h"
#include "triangle.h"
#include "stack.h"
#define N 30

void main()
{
	HWND hwnd = GetConsoleWindow();

	Stack stack = Stack(N);
	Triangle triangle = Triangle();

	char c = 0;

	printf_s("Menu:\n1 - Push triangle into stack from buffer\n2 - Pop triangle from stack into buffer\n3 - Print stack(push Enter for every element)\n4 - Find in stack by color and buffer it\n5 - Save stack into file\n6 - Image triangle in buffer\n7 - Load triangle from file\n");
	do
	{
		try
		{
			if (_kbhit()) {
				clearConsole();
				printf_s("Menu:\n1 - Push triangle into stack from buffer\n2 - Pop triangle from stack into buffer\n3 - Print stack(push Enter for every element)\n4 - Find in stack by color and buffer it\n5 - Save stack into file\n6 - Image triangle in buffer\n7 - Load triangle from file\n");
				c = _getch();
				switch (c)
				{
				case 49:	//1 - push
					stack.Push(triangle);
					printf_s("Element pushed successfully!\n");
					break;
				case 50:	//2 - pop
					triangle = stack.Pop();
					printf_s("Element popped successfully!\n");
					break;
				case 51:	//3 - print
					clearConsole();
					stack.Print(hwnd);
					break;
				case 52:	//4 - find
					int color[3];
					printf_s("Set color in format R G B : \n");
					for (int i = 0; i < 3; i++) scanf_s("%d", &color[i]);

					triangle = stack.find(color);
					printf_s("Triangle found and buffered!\n");
					break;
				case 53:	//5 - save
					FILE *f;
					fopen_s(&f, "stackout.txt", "w");
					fclose(f);
					stack.Save("stackout.txt");
					printf_s("Your stack saved into stackout.txt\n");
					break;
				case 54:	//6 - рисование текущего треугольника
					clearConsole();
					triangle.mainDraw(hwnd);
					clearConsole();
					break;
				case 55:	//7 - загрузить треугольник из файла
					triangle.readInf("input.txt");
					printf_s("Triangle loaded successfully!\n");
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
		}
	} while (c != 27);
}