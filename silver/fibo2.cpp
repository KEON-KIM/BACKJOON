#include<iostream>
#include<cmath>

#define MAX 1000010
#define MOD 1000000000

using namespace std;


int N;
long long DP[MAX];

int main()
{
	int result, sign;
	cin >> N;

	if (N < 0){
		if(N%2==0)
			sign = -1;
		else sign = 1;
	}
	else if (N == 0) sign = 0; 
	else sign = 1;

	DP[0] = 0;
	DP[1] = 1;
	for(int i = 2; i <= abs(N); i++)
		DP[i] = DP[i-1]%MOD + DP[i-2]%MOD;
	

	
	cout << sign << endl;
	cout << DP[abs(N)]%MOD << endl;

	return 0;
}