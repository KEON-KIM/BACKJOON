// #14852
#include<iostream>

#define MAX 1000001
#define MOD 1000000007

using namespace std;
typedef long long ll;
ll N, DP[MAX][2];
int main()
{
	cin >> N;
	DP[0][0] = 0;
	DP[1][0] = 2;
	DP[2][0] = 7;
	DP[2][1] = 1;

	for(int i = 3; i <= N; i++)
	{
		DP[i][1] = (DP[i-1][1]+DP[i-3][0])%MOD;
		DP[i][0] = (DP[i][1]*2 + DP[i-1][0]*2 + DP[i-2][0] * 3)%MOD;
	}

	cout << DP[N][0]  << endl;
	return 0;
}