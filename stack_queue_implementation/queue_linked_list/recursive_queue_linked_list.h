#ifndef RECURSIVE_QUEUE_LINKED_LIST_H
#define RECURSIVE_QUEUE_LINKED_LIST_H

#include <iostream>
using namespace std;

namespace recursive_queue_linked_list {
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
		void copyQueue_recursive_helper(Node* cur);
		void copyQueue_recursive(const Queue<T>& q);
		void release();
		void release_recursive_helper(Node* cur);
		void release_recursive();

		bool isEmpty();
		void enqueue(T newItem);
		T dequeue();
		T frontValue();

		void print();
		void print_recursive_helper(Node* cur);
		void print_recursive();
	};
}

#endif RECURSIVE_QUEUE_LINKED_LIST_H