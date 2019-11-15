#include "stack.h"

Stack::Stack(int N) {
	top = -1;
	n = N;
	arr = new Triangle[N];
}
Stack::~Stack() {
	delete[] arr;
}

void Stack::Push(Triangle d) {
	if (isFull()) throw ERR_FULL;
	top++;
	arr[top] = d;
}

Triangle Stack::Pop() {
	if (isEmpty()) throw ERR_EMPTY;
	top--;
	return arr[top + 1];
}

void Stack::Print(HWND hwnd) {
	if (isEmpty()) throw ERR_EMPTY;

	Triangle *temp_arr = arr;
	int temp_top = top;

	while (temp_top != -1) {
		temp_arr[temp_top].mainDraw(hwnd);
		temp_top--;
	}

}

Triangle Stack::find(int *key) {
	if (isEmpty()) throw ERR_EMPTY;

	Triangle *temp_arr = arr;
	int temp_top = top;

	COLORREF color, t_color;
	color = RGB(key[0], key[1], key[2]);
	temp_arr[temp_top].getColor(t_color);
	while (t_color != color) {
		if (temp_top == -1) throw ERR_NOT_FOUND;
		temp_top--;
		temp_arr[temp_top].getColor(t_color);
	}
	return temp_arr[temp_top];
}

void Stack::Save(const char name[]) {
	Triangle *temp_arr = arr;
	int temp_top = top;

	while (temp_top != -1) {
		temp_arr[temp_top].saveInf(name);
		temp_top--;
	}
}

bool Stack::isEmpty() {
	if (top == -1) return true;
	return false;
}
bool Stack::isFull() {
	if (top == n - 1) return true;
	return false;
}