#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

namespace stack_linked_list {
	template <class T>
	struct Stack {
		struct Node {
			T data;
			Node* next;
		};

		Node* top;

		void init();
		void copyStack(const Stack<T>& s);
		void release();

		bool isEmpty() const;
		void push(T newItem);
		T pop();
		T topValue();

		void print();
	};
}

#endif STACK_LINKED_LIST_H
