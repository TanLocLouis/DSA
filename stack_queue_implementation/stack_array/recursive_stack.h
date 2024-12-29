#ifndef RECURSIVE_STACK_H
#define RECURSIVE_STACK_H

#include <iostream>
using namespace std;

namespace recursive_stack {
	template <typename T>
	struct Stack {
		T* item;
		int top;
		unsigned int maxSize;

		void init(unsigned int stackSize);
		void copyStack(const Stack<T>& s);
		void copyStack_recursive_helper(const Stack<T>& s, int i);
		void copyStack_recursive(const Stack<T>& s);
		void release();

		bool isEmpty();
		void push(T newItem);
		T pop();
		T topValue();
		
		void print_recursive_helper(int i);
		void print_recursive();
	};
}

#endif RECURSIVE_STACK_H
