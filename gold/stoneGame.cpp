//#9660
#include<iostream>

using namespace std;
typedef long long ll;

int N;
int main()
{
	cin >> N;
	if(N%7 == 0 || N%7 == 2)
		cout << "CY" << endl;

	else
		cout << "SK" << endl;

	return 0;
}