#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

#include <iostream>
using namespace std;

namespace queue_linked_list {
	template <typename T>
	struct Queue {
		struct Node {
			int data;
			Node* next;
		};

		Node* front;
		Node* rear;

		void init();
		void copyQueue(const Queue<T>& q);
		void release();

		bool isEmpty();
		void enqueue(T newItem);
		T dequeue();
		T frontValue();

		void print();
	};
}

#endif QUEUE_LINKEDLIST_H
