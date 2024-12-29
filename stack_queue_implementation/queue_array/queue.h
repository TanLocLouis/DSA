#ifndef QUEUE_H
#define QUEUE_H

namespace queue {
	template <typename T>
	struct Queue {
		T* items;
		int front;
		int rear;
		unsigned int count;
		unsigned int maxSize;

		void init(unsigned int queueSize);
		void copyQueue(const Queue<T>& q);
		void release();

		bool isEmpty();
		void enqueue( T item);
		T dequeue();
		T frontValue();

		void print();
	};
}


#endif QUEUE_H
