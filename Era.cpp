#include <bits/stdc++.h>

using namespace std;

vector<bool> era(int n) {
	vector<bool> res(n, true);
	res[0] = res[1] = false;
	res[2] = true;
	for (int i = 2; i * i <= n; i++) { 
		if (res[i]) // if prime number then multiple of it is not prime
			for (int j = i * i; j <= n; j += i) res[j] = false;
	}
	
	return res;
}

int main() {
	vector<bool> res = era(100);
	for (int i = 0; i < 100; i++) {
		if (res[i]) cout << i << " ";
	}
	return 0;
}

