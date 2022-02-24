#include <iostream>

using namespace std;
int gcd(int a, int b) {
	if (!b) return a;
	if (a > b) return gcd(b, a % b);
	return gcd(a, b % a);
}

int N, M;
int main() 
{
	int a, b;

	cin >> N >> M;
	M /= N;

	for(int i = 1; i * i <= M; i++)
		if (M % i == 0) {
			if (gcd(i, M / i) == 1) {
				a = i, b = M / i;
				cout << a << " " << b << endl;
			}
		}

	cout << N * a << " "<< N * b << endl;

	return 0;
}