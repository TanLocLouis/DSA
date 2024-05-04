#include <iostream>

using namespace std;

int partition(int *a, int low, int high) {
	int pivot = a[high];
	int idx = low - 1;
	
	for (int i = low; i <= high; i++) {
		if (a[i] < pivot) {
			idx++;
			swap(a[idx], a[i]);
		}
	}
	
	swap(a[idx + 1], a[high]);
	return idx + 1;
}

void quicksort(int *a, int low, int high) {
	if (low < high) {
		int pivot = partition(a, low, high);
		
		quicksort(a, low, pivot - 1);
		quicksort(a, pivot + 1, high);
	}
}

void output(int *a, int n) {
	for (int i = 0; i < n; i++) cout << a[i] << char(32);
}

void gen(int *a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}

int main() {
	const int n = 1000000;
	int a[n];
	
	gen(a, n);
	quicksort(a, 0, n - 1);
	return 0;
}

