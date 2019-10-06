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
		void drawTriangle(HDC hdc); //��������� ������������
		void drawCounter(HDC hdc);	//�������
		void drawCut(HDC hdc);		//������������ � �������
		void mainDraw(HDC hdc);		//��������� ������

		void setMode(int new_mode);		//��� ������
		void getMode(int &curr_mode);

		void setPoints(POINT *new_points); //����� ������������
		void getPoints(POINT *curr_points);

		void setCPoints(POINT *new_Cpoints); //����� ������������ ��� ������
		void getCPoints(POINT *curr_Cpoints);

		void setBorder(int new_border); //������� �������
		void getBorder(int &curr_border);

		void setStyle(int new_style); //����� ����(�������)
		void getStyle(int &curr_style);

		void setColor(COLORREF new_tcolor); //���� ����(�������)
		void getColor(COLORREF &curr_tcolor);

		void setBStyle(int new_bstyle); //����� ����� (�������)
		void getBStyle(int &curr_bstyle);

		void setBColor(COLORREF new_bcolor); //���� �����(�������)
		void getBColor(COLORREF &curr_bcolor);

		void checkSizeTC(POINT *new_Cpoints); //������ �� ����� � �����������
		void checkSizeT( int rtx, int rty); //������ �� ����������� � ����
		void checkSizeT( HDC hdc );			//������ �� ����������� � ����

		void readInf(const char name[]);	//���� ������������ �� �����
		void saveInf(const char name[]);	//����� ������������ � ����

		void move_horizontally(int delta);	//����� ������ �� �����������
		void move_vertically(int delta);	//����� ������ �� ���������
};

#endif