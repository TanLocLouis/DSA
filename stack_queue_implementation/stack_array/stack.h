#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

namespace stack {
	template <typename T>
	struct Stack {
		T* item;
		int top;
		unsigned int maxSize;

		void init(unsigned int stackSize);
		void copyStack(const Stack<T>& s);
		void release();

		bool isEmpty();
		void push(T newItem);
		T pop();
		T topValue();
		
		void print();
	};
}


#endif STACK_H
