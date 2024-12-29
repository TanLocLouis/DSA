#include <iostream>
#include <queue>

using namespace std;

struct Heap {
	int* arr;
	int capacity;
	int size;
	
	Heap(int capacity) {
		arr = new int[capacity];
		capacity = capacity;
		size = 0;
	}
};

// Get parent
int getParent(int i) {
	return (i - 1) / 2;
}

// Get left child
int getLeftChild(int i) {
	return i * 2 + 1;
}

// Get right child
int getRightChild(int i) {
	return i * 2 + 2;
}

// Heapify up when add a new node
void heapifyUp(Heap* h, int i) {
	while (i >= 0 && h->arr[getParent(i)] > h->arr[i]) {
		swap(h->arr[getParent(i)], h->arr[i]);
		i = getParent(i);
	}
}

void heapifyDown(Heap* h, int i) {
	int smallest = i;
	
	int leftChild = getLeftChild(i);
	int rightChild = getRightChild(i);

	if (leftChild < h->size)
		if (h->arr[leftChild] < h->arr[smallest]) smallest = leftChild;
	if (rightChild < h->size)
		if (h->arr[rightChild] < h->arr[smallest]) smallest = rightChild;

	if (smallest != i) {
		swap(h->arr[i], h->arr[smallest]);
		heapifyDown(h, smallest);
	}
}

void levelOrder(Heap* h, int i) {
	queue<int> q;
	q.push(i);

	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int cur = q.front(); q.pop();

			int leftChild = getLeftChild(cur);
			int rightChild = getRightChild(cur);
			if (leftChild < h->size) q.push(leftChild);
			if (rightChild < h->size) q.push(rightChild);

			cout << h->arr[cur] << char(32);
		}
		cout << endl;
	}
}

void insert(Heap* heap, int value) {
	if (heap->size == heap->capacity) {
		cout << "Heap da day!" << endl;
		return;
	}
	
	// Insert new value to the most left leaf
	heap->size++;
	int index = heap->size - 1;
	heap->arr[index] = value;

	// Heapify up the tree from the inserted node
	heapifyUp(heap, index);
}


int extractMin(Heap* heap) {
	if (heap->size == 0) {
		cout << "Heap rong!" << endl;
		return -1;
	}

	// etract root value and move right most left to root
	int ans = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size - 1];
	heap->size--;

	// heapify down to maintain heap property
	heapifyDown(heap, 0);

	return ans;
}

int getMin(Heap* heap) {
	if (heap->size == 0) {
		cout << "Heap rong!" << endl;
		return -1;
	}

	return heap->arr[0];
}

void deleteKey(Heap* heap, int index) {
	if (heap->size == 0) {
		cout << "Heap rong!" << endl;
		return;
	}
	
	// Insert right most leaf to current node
	heap->arr[index] = heap->arr[heap->size - 1];
	heap->size--;

	// heapifyDown to maintain heap property
	heapifyDown(heap, index);
}

int countNode(Heap* heap) {
	return heap->size;
}

int height(Heap* heap) {
	return log2(heap->size + 1);
}

void heapSort(Heap* heap) {
	for (int i = heap->size / 2 - 1; i >= 0; i--) {
		heapifyDown(heap, i);
	}

	for (int i = heap->size - 1; i > 0; i--) {
		swap(heap->arr[0], heap->arr[i]);
		heapifyDown(heap, 0);
	}
}

int main() {
	Heap *h = new Heap(10);
	insert(h, 20);
	insert(h, 15);
	insert(h, 30);
	insert(h, 10);
	insert(h, 8);
	insert(h, 25);
	cout << "Sau khi chen: " << endl;
	levelOrder(h, 0); cout << endl;

	cout << "Extract Min: ";
	cout << extractMin(h) << endl;
	levelOrder(h, 0); cout << endl;
	
	cout << "Get Min: ";
	cout << getMin(h) << endl; cout << endl;
	
	cout << "Delete key 1: " << endl;
	deleteKey(h, 1);
	levelOrder(h, 0); cout << endl;

	heapSort(h);
	levelOrder(h, 0);

	return 0;
}
