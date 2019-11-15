#ifndef STACK_H
#define STACK_H

#define ERR_FULL 10
#define ERR_EMPTY 20
#define ERR_NOT_FOUND 30

#include "Triangle.h"

class Stack {
private:
	Triangle *arr;
	int top;
	int n;
public:
	Stack(int N);
	~Stack();

	void Push(Triangle d);
	void Print(HWND hwnd);

	Triangle Pop();
	Triangle find(int *key);

	void Save(const char name[]);

	bool isEmpty();
	bool isFull();
};

#endif