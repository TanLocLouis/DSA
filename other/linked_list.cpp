#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* pNext;
};

struct LinkedList {
	Node* pHead;
	Node* pTail;
};

void Init(LinkedList& list) {
	list.pHead = NULL;
	list.pTail = NULL;
}

bool isEmpty(LinkedList list) {
	return list.pHead == NULL;
}

Node* createNode(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->pNext = NULL;
	return newNode;
}

void outputList(LinkedList& list) {
	Node* head = new Node;
	head = list.pHead;
	
	while (head) {
		cout << head->data << char(32);
		head = head->pNext;
	}
}

void insertNode(LinkedList& list, Node* p) {
	if (list.pHead == NULL) {
		list.pHead = list.pTail = p;
	} else {
		p->pNext = list.pHead;
		list.pHead = p;
	}
}

void insertTail(LinkedList& list, Node* p) {
	if (list.pHead == NULL && list.pTail == NULL) {
		list.pHead = list.pTail = p;
	} else {
		list.pTail->pNext = p;
		list.pTail = p;
	}
}

Node* getNode(LinkedList list, int index) {
	if (list.pHead != NULL && index >= 0) {
		Node* head = new Node;
		head = list.pHead;
		
		int i = 0;
		while (head) {
			if (i == index) return head;
			i++;
			head = head->pNext;
		}	
	}
	
	return NULL;
}

int main() {
	LinkedList list;
	Init(list);
	
	insertNode(list, createNode(1));
	insertNode(list, createNode(2));
	insertTail(list, createNode(10));
	insertNode(list, createNode(3));
	outputList(list);
	
	return 0;
}

