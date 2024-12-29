#include "recursive_queue.h"

#include <iostream>
using namespace std;

using namespace recursive_queue;

template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<char>;
template class Queue<bool>;

template <typename T>
void Queue<T>::init(unsigned int queueSize) {
	items = new T[queueSize];
	front = 0;
	rear = -1;
	count = 0;
	maxSize = queueSize;
}

template <typename T>
bool Queue<T>::isEmpty() {
	return count == 0;
}

template <typename T>
void Queue<T>::enqueue(T item) {
	if (count == maxSize) {
		// realloc array if queue is full
		maxSize = maxSize * 2;
		T* newItems = new T[maxSize];
		if (newItems != NULL) {
			for (int i = front; i <= rear; i++) {
				newItems[i] = items[i];
			}
			delete[] items;
			items = newItems;
		}
		else {
			cout << "Khong the cap phat bo nho de mo rong Queue" << endl;
			return;
		}



		cout << "Hang doi da day" << endl;
		return;
	}

	rear++;
	items[rear] = item;
	count++;
}

template <typename T>
T Queue<T>::dequeue() {
	if (count == 0) {
		cout << "Hang doi rong" << endl;
		return T();
	}

	T item = items[front];
	front++;
	count--;

	return item;
}

template <typename T>
T Queue<T>::frontValue() {
	if (count == 0) {
		cout << "Hang doi rong" << endl;
		return T();
	}

	return items[front];
}

template <typename T>
void Queue<T>::copyQueue(const Queue<T>& q) {
	items = new T[q.maxSize];
	front = q.front;
	rear = q.rear;
	count = q.count;
	maxSize = q.maxSize;

	for (int i = front; i <= rear; i++) {
		items[i] = q.items[i];
	}
}


template <typename T>
void Queue<T>::release()
{
	delete[] items;
	items = nullptr;
	front = 0;
	rear = -1;
	count = 0;
	maxSize = 0;
}

template <typename T>
void Queue<T>::print() {
	for (int i = front; i <= rear; i++) {
		cout << items[i] << char(32);
	}
	cout << endl;
}

template <typename T>
void Queue<T>::copyQueue_recursive_helper(const Queue<T>& q, int i) {
	if (i > rear) {
		return;
	}
	
	items[i] = q.items[i];
	copyQueue_recursive_helper(q, i + 1);
}

template <typename T>
void Queue<T>::copyQueue_recursive(const Queue<T>& q) {
	items = new T[q.maxSize];
	front = q.front;
	rear = q.rear;
	count = q.count;
	maxSize = q.maxSize;

	copyQueue_recursive_helper(q, 0);
}

template <typename T>
void Queue<T>::print_recursive_helper(int i) {
	if (i == rear) {
		return;
	}

	cout << items[i] << char(32);
	print_recursive_helper(i + 1);
}

template <typename T>
void Queue<T>::print_recursive() {
	print_recursive_helper(0);
}
