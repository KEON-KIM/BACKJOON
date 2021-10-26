//#10844
//@Reference sihyungyou <https://sihyungyou.github.io/baekjoon-10844/>

#include<iostream>
#define MOD 1000000000

using namespace std;

int N, dp[101][11], answer = 0;
int main()
{
	cin >> N;
	for(int i = 1; i < 10; i++) dp[0][i] = 1;
	for(int i = 1; i < N; i++)
	{
		dp[i][0] = dp[i-1][1];
		dp[i][10] = 0;
		for(int j = 1; j < 10; j++)
		{
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD; 
		}
	}
	//print
	// for(int i = 0; i < N; i++)
	// {
	// 	for(int j = 0; j < 10; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }

	for(int value : dp[N-1]){ answer = (answer + value)%MOD;}

	cout << answer % MOD << endl;

  	return 0;
}