#ifndef TRIANGLE_H
#define TRIANGLE_H

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
#define ERR_WRONG_MODE 8

#include <windows.h>  
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>

class Triangle {
	private:
		POINT points[3], Cpoints[3];
		int style, bstyle, border, mode;
		COLORREF color, bcolor;
	public:
		void drawTriangle(HDC hdc); //Рисование треугольника
		void drawCounter(HDC hdc);	//Контура
		void drawCut(HDC hdc);		//Треугольника с вырезом
		void mainDraw(HDC hdc);		//Рисование фигуры

		void setMode(int new_mode);		//Тип фигуры
		void getMode(int &curr_mode);

		void setPoints(POINT *new_points); //Точки треугольника
		void getPoints(POINT *curr_points);

		void setCPoints(POINT *new_Cpoints); //Точки треугольника для выреза
		void getCPoints(POINT *curr_Cpoints);

		void setBorder(int new_border); //Толщина контура
		void getBorder(int &curr_border);

		void setStyle(int new_style); //Стиль пера(контура)
		void getStyle(int &curr_style);

		void setColor(COLORREF new_tcolor); //Цвет пера(контура)
		void getColor(COLORREF &curr_tcolor);

		void setBStyle(int new_bstyle); //Стиль кисти (заливки)
		void getBStyle(int &curr_bstyle);

		void setBColor(COLORREF new_bcolor); //Цвет кисти(заливки)
		void getBColor(COLORREF &curr_bcolor);

		void checkSizeTC(POINT *new_Cpoints); //Входит ли вырез в треугольник
		void checkSizeT( int rtx, int rty); //Входит ли треугольник в окно
		void checkSizeT( HDC hdc );			//Входит ли треугольник в окно

		void readInf(const char name[]);	//Ввод треугольника из файла
		void saveInf(const char name[]);	//Вывод треугольника в файл

		void move_horizontally(int delta);	//Сдвиг фигуры по горизонтали
		void move_vertically(int delta);	//Сдвиг фигуры по вертикали
};

#endif