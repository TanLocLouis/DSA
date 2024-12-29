#include "stack.h"

#include <iostream>
using namespace std;

using namespace stack;

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;
template class Stack<bool>;

template <typename T>
void Stack<T>::init(unsigned int stackSize) {
	item = new T[maxSize];
	top = -1;
	maxSize = stackSize;
}

template <typename T>
void Stack<T>::release() {
	delete[] item;
}

template <typename T>
void Stack<T>::push(T newItem) {
	if (item == NULL) {
		cout << "Stack chua duoc khoi tao" << endl;
		return;
	}

	if (top == maxSize - 1) {
		cout << "Stack da day" << endl;
		return;
	}
	item[++top] = newItem;
}

template <typename T>
T Stack<T>::pop() {
	if (isEmpty()) {
		cout << "Stack rong" << endl;
		return T();
	}
	return item[top--];
}

template <typename T>
T Stack<T>::topValue() {
	if (isEmpty()) {
		cout << "Stack rong" << endl;
		return T();
	}
	return item[top];
}

template <typename T>
bool Stack<T>::isEmpty() {
	return top == -1;
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& s) {
	item = new T[maxSize];
	top = s.top;
	maxSize = s.maxSize;
	for (int i = 0; i <= top; i++) {
		item[i] = s.item[i];
	}
}

template <typename T>
void Stack<T>::print() {
	for (int i = 0; i <= top; i++) {
		cout << item[i] << char(32);
	}
	cout << endl;
}
