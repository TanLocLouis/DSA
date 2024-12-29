#include <iostream>
#include <ctime>

using namespace std;

void genRandomArray(int *a, int& n, int start, int end) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % (end - start + 1) + start;
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int binarySearch(int *a, int n, int m) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == m) {
            return mid;
        } else if (a[mid] < m) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    srand(time(0));

    int n = 100;
    int *a = new int[n];
    genRandomArray(a, n, 1, 100);
    output(a, n);

    int key = 10;
    int index = binarySearch(a, n, key);

    cout << "Value " << key << " at index: " << index << endl;
}