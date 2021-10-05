#include <iostream>


using namespace std;

int f(int x) {
	if (x <2) { return 0; }
	int v1 = f(x/3) + x % 3 + 1;
	int v2 = f(x/2)+ x % 2 + 1;
	return v1<v2?v1:v2;
}

int main() {
	int x;
	cin >> x;
	cout << f(x) << endl;
}
