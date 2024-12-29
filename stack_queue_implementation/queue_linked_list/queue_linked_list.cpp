#include "queue_linked_list.h"

using namespace queue_linked_list;

template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<char>;
template class Queue<bool>;

template <typename T>
void Queue<T>::init() {
	front = rear = nullptr;
}

template <typename T>
bool Queue<T>::isEmpty() {
	return front == nullptr;
}

template <typename T>
void Queue<T>::enqueue(T newItem) {
	Node* newNode = new Node;
	newNode->data = newItem;
	newNode->next = nullptr;

	if (isEmpty()) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
}

template <typename T>
T Queue<T>::dequeue() {
	if (isEmpty()) {
		cout << "Hang doi rong" << endl;
		return T();
	}
	
	T item = front->data;
	Node* tmp = front;
	front = front->next;
	delete tmp;

	return item;
}

template <typename T>
T Queue<T>::frontValue() {
	if (isEmpty()) {
		cout << "Hang doi rong" << endl;
		return T();
	}

	return front->data;
}

template <typename T>
void Queue<T>::release() {
	Node* cur = front;
	while (cur != NULL) {
		Node* tmp = cur;
		cur = cur->next;
		delete tmp;
	}
}

template <typename T>
void Queue<T>::print() {
	Node* cur = front;
	while (cur != NULL) {
		cout << cur->data << char(32);
		cur = cur->next;
	}
	cout << endl;
}

template <typename T>
void Queue<T>::copyQueue(const Queue<T>& q) {
	Node* cur = q.front;
	while (cur != NULL) {
		enqueue(cur->data);
		cur = cur->next;
	}
}
