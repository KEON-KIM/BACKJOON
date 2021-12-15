// #1188
#include <iostream>

using namespace std;

int N, M;

int GCD(int a, int b)
{
	if(!(a%b)) return b;
	else return GCD(b, a%b);
}
int main()
{
	int n, gcd;
	cin >> N >> M;
	gcd = GCD(N, M);

	if(N%M == 0) cout << 0 << endl;
	else cout << ((M/gcd)-1) * gcd << endl;
	
	return 0;
}