#include "stack.h"

template <class T>
Stack<T>::Stack(int N) {
	top = -1;
	n = N;
	arr = new T[N];
}

template <class T>
Stack<T>::~Stack() {
	delete[] arr;
}

template <class T>
void Stack<T>::Push(T d) {
	if (isFull()) throw ERR_FULL;
	top++;
	arr[top] = d;
}

template <class T>
T Stack<T>::Pop() {
	if (isEmpty()) throw ERR_EMPTY;
	top--;
	return arr[top + 1];
}

template <class T>
void Stack<T>::Print(HDC hdc) {
	if (isEmpty()) throw ERR_EMPTY;

	T *temp_arr = arr;
	int temp_top = top;

	while (temp_top != -1) {
		temp_arr[temp_top].Draw(hdc);
		temp_top--;
	}

}

template <class T>
T Stack<T>::find(int *key) {
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

template <class T>
void Stack<T>::Save(const char name[]) {
	T *temp_arr = arr;
	int temp_top = top;

	while (temp_top != -1) {
		temp_arr[temp_top].save(name);
		temp_top--;
	}
}

template <class T>
bool Stack<T>::isEmpty() {
	if (top == -1) return true;
	return false;
}

template <class T>
bool Stack<T>::isFull() {
	if (top == n - 1) return true;
	return false;
}