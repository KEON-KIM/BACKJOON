#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int a, b, A, B;
	cin >> a >> b;
	if (a < b){
		cout << -1 << endl;
		return 0;
	} 
	else
	{
		A = (a+b)/2;
		B = a - A;

		if ( abs(A - B) != b) {
			cout << -1 << endl;
			return 0;
		}

		if ( A > B) cout << A << " " << B << endl; 
		else cout << B << " " << A << endl; 
		return 0;
	}
	
}