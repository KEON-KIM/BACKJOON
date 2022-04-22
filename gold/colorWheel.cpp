//#2482
#include <iostream>

#define MAX 1002
#define MOD 1000000003
#define FOR(i, n) for(int i = 2; i <= n; i++)
using namespace std;

int N, K;
int dp[MAX][MAX]; // color(n), select(k)
int main()
{
	cin >> N >> K;
	for(int i = 0; i <= N; i++) dp[i][0] = 1; // init()

	dp[1][1] = 1;
	FOR(i, N)
		FOR(j, K)
			dp[i][j] = (dp[i-2][j-1] + dp[i-1][j])%MOD;

	cout << (dp[N-3][K-1] + dp[N-1][K]) % MOD << endl;

	return 0;
}