#ifndef STACK_H
#define STACK_H

#define ERR_FULL 10
#define ERR_EMPTY 20
#define ERR_NOT_FOUND 30

#include <windows.h>  
#include <windowsx.h>
#include <stdio.h>
#include "combined.h"

template <class T>
class Stack {
private:
	T *arr;
	int top;
	int n;
public:
	Stack(int N) {
		top = -1;
		n = N;
		arr = new T[N];
	}
	~Stack() {
		delete[] arr;
	}

	void Push(T d) {
		if (isFull()) throw ERR_FULL;
		top++;
		arr[top] = d;
	}
	T Pop() {
		if (isEmpty()) throw ERR_EMPTY;
		top--;
		return arr[top + 1];
	}

	void Print(HDC hdc) {
		if (isEmpty()) throw ERR_EMPTY;

		T *temp_arr = arr;
		int temp_top = top;

		while (temp_top != -1) {
			temp_arr[temp_top].Draw(hdc);
			temp_top--;
		}

	}
	T find(int *key) {
		if (isEmpty()) throw ERR_EMPTY;

		T *temp_arr = arr;
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

	void Save(const char name[]) {
		T *temp_arr = arr;
		int temp_top = top;

		while (temp_top != -1) {
			temp_arr[temp_top].save(name);
			temp_top--;
		}
	}

	bool isEmpty() {
		if (top == -1) return true;
		return false;
	}
	bool isFull() {
		if (top == n - 1) return true;
		return false;
	}
};

template<>
combined Stack<combined>::find(int *key) {
	if (isEmpty()) throw ERR_EMPTY;

	combined *temp_arr = arr;
	int temp_top = top;

	COLORREF color, t_color;
	color = RGB(key[0], key[1], key[2]);

	painted temp;
	temp_arr[temp_top].getIntern(temp);
	temp.getColor(t_color);
	while (t_color != color) {
		if (temp_top == -1) throw ERR_NOT_FOUND;
		temp_top--;
		temp_arr[temp_top].getIntern(temp);
		temp.getColor(t_color);
	}
	return temp_arr[temp_top];
}
#endif