#ifndef STACK_H
#define STACK_H

#define ERR_FULL 10
#define ERR_EMPTY 20
#define ERR_NOT_FOUND 30

#include <windows.h>  
#include <windowsx.h>
#include <stdio.h>

template <class T>
class Stack {
private:
	T *arr;
	int top;
	int n;
public:
	Stack(int N);
	~Stack();

	void Push(T d);
	void Print(HDC hdc);

	T Pop();
	T find(int *key);

	void Save(const char name[]);

	bool isEmpty();
	bool isFull();
};

#endif