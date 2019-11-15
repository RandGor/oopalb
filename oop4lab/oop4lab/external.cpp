#include "external.h"


void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 25;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void clearConsole() {
	system("cls");
	system("cls");
}