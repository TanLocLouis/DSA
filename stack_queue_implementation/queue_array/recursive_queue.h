#ifndef RECURSIVE_QUEUE_H
#define RECURSIVE_QUEUE_H

namespace recursive_queue {
	template <typename T>
	struct Queue {
		T* items;
		int front;
		int rear;
		unsigned int count;
		unsigned int maxSize;

		void init(unsigned int queueSize);
		void copyQueue(const Queue<T>& q);
		void copyQueue_recursive_helper(const Queue<T>& q, int i);
		void copyQueue_recursive(const Queue<T>& q);
		void release();

		bool isEmpty();
		void enqueue( T item);
		T dequeue();
		T frontValue();

		void print();
		void print_recursive_helper(int i = 0);
		void print_recursive();
	};
}


#endif RECURSIVE_QUEUE_H
