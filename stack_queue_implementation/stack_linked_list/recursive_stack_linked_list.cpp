#include "recursive_stack_linked_list.h"

#include <iostream>
using namespace std;

using namespace recursive_stack_linked_list;

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;
template class Stack<bool>;


template <typename T>
void Stack<T>::release_recursive_helper(Node* cur) {
	if (cur == NULL) {
		return;
	}

	release_recursive_helper(cur->next);
	delete cur;
}

template <typename T>
void Stack<T>::release_recursive() {
	release_recursive_helper(top);
}


template <typename T>
void Stack<T>::push(T newItem) {
	Node* newNode = new Node;
	newNode->data = newItem;
	newNode->next = top;

	top = newNode;
}

template <typename T>
void Stack<T>::copyStack_recursive_helper(Node* cur) {
	if (cur == NULL) {
		return;
	}

	copyStack_recursive_helper(cur->next);
	push(cur->data);
}

template <typename T>
void Stack<T>::copyStack_recursive(const Stack<T>& s) {
	copyStack_recursive_helper(s.top);
}


template <typename T>
void Stack<T>::print_recursive_helper(Node* cur) {
	if (cur == NULL) {
		return;
	}

	cout << cur->data << char(32);
	print_recursive_helper(cur->next);
}

template <typename T>
void Stack<T>::print_recursive() {
	print_recursive_helper(top);
	cout << endl;
}
