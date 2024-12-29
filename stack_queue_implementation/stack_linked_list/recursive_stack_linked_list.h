#ifndef RECURSIVE_STACK_LINKED_LIST_H
#define RECURSIVE_STACK_LINKED_LIST_H

namespace recursive_stack_linked_list {
	template <class T>
	struct Stack {
		struct Node {
			T data;
			Node* next;
		};

		Node* top;

		void init();
		void copyStack(const Stack<T>& s);
		void copyStack_recursive_helper(Node* cur);
		void copyStack_recursive(const Stack<T>& s);
		void release();
		void release_recursive_helper(Node* cur);
		void release_recursive();

		bool isEmpty() const;
		void push(T newItem);
		T pop();
		T topValue();

		void print();
		void print_recursive_helper(Node* cur);
		void print_recursive();
	};
}


#endif RECURSIVE_STACK_LINKED_LIST_H
