
#include "stack_linked_list.h"

#include <iostream>
using namespace std;

using namespace stack_linked_list;

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;
template class Stack<bool>;

template <typename T>
void Stack<T>::init() {
	top = NULL;
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return top == NULL;
}

template <typename T>
void Stack<T>::release() {
	if (isEmpty()) {
		return;
	}
	
	Node* cur = top;
	while (cur != NULL) {
		Node* temp = cur;
		cur = cur->next;
		delete temp;
	}
}


template <typename T>
void Stack<T>::copyStack(const Stack<T>& s) {
	if (s.isEmpty()) {
		return;
	}

	Node* cur = s.top;
	while (cur != NULL) {
		push(cur->data);
		cur = cur->next;
	}
}


template <typename T>
void Stack<T>::push(T newItem) {
	Node* newNode = new Node;
	newNode->data = newItem;
	newNode->next = top;

	top = newNode;
}

template <typename T>
T Stack<T>::pop() {
	if (isEmpty()) {
		cout << "Stack rong" << endl;
		return T();
	}

	Node* temp = top;
	T data = top->data;
	top = top->next;
	delete temp;

	return data;
}

template <typename T>
T Stack<T>::topValue() {
	if (isEmpty()) {
		cout << "Stack rong" << endl;
		return T();
	}

	return top->data;
}

template <typename T>
void Stack<T>::print() {
	if (isEmpty()) {
		cout << "Stack rong" << endl;
		return;
	}

	Node* cur = top;
	while (cur != NULL) {
		cout << cur->data << char(32);
		cur = cur->next;
	}
	cout << endl;
}

