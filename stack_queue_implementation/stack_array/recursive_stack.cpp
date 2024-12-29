#include "recursive_stack.h"

#include <iostream>
using namespace std;

using namespace recursive_stack;

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
void Stack<T>::copyStack_recursive_helper(const Stack<T>& s, int i) {
	if (i > s.top) {
		return;
	}

	item[i] = s.item[i];
	copyStack_recursive_helper(s, i + 1);
}

template <typename T>
void Stack<T>::copyStack_recursive(const Stack<T>& s) {
	item = new T[maxSize];
	top = s.top;
	maxSize = s.maxSize;
	copyStack_recursive_helper(s, 0);
}

template <typename T>
void Stack<T>::print_recursive_helper(int i) {
	if (i > top) {
		cout << endl;
		return;
	}

	cout << item[i] << char(32);
	print_recursive_helper(i + 1);
}

template <typename T>
void Stack<T>::print_recursive() {
	print_recursive_helper(0);
}