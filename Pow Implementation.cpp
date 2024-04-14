#include <iostream>

using namespace std;

/*double pow(double a, int b) {
	if (b < 0) {
		a = 1/a;
		b = -b;
	}
	
	double ans = 1.0;
	while (b) {
		if (b % 2 == 1) {
			ans *= a;
			b--;
		}
		
		a *= a;
		b /= 2;
	}
	
	return ans;
}*/

double pow(double a, int b) {
	if (b < 0) {
		a = 1/a;
		b = -b;
	}
	
	if (b == 0) return 1;
	
	if (b % 2 == 1) return a * pow(a, b - 1);
	else return pow(a * a, b / 2);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << pow(a, b) << endl;
	
	
	return 0;
}

