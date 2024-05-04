#include <iostream>

using namespace std;

int binSearch(int a[], const int& n, const int& key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == key) {
            return mid;
        } else if (a[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

void selectionSort(int a[], const int& n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        
        if (min != i) {
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}

void insertionSort(int a[], const int& n) {
    for (int i = 1; i < n; i++) {
        int pos = i;
        int x = a[i];

        while (pos > 0 && a[pos - 1] > x) {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = x;
    }
}

int main() {
    int n = 8;
    int a[8] = {5,3,4,5,8,2,1,2};

    // selectionSort(a, n);
    // insertionSort(a, n);
    // interchange sort;
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}