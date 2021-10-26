// # 2156
// @Reference yabmoons <https://yabmoons.tistory.com/512>
#include<iostream>

using namespace std;

int N, maximum = -1;
int board[10001], dp[10001];

// void dfs(int n, int cont, int result)
// {
// 	if(n >= N) 
// 	{
// 		if(result > maximum) maximum = result;
// 		return;
// 	}
// 	result += board[n];
// 	if(cont < 1){dfs(n+1, cont+1, result);dfs(n+2, 0, result);dfs(n+3, 0, result);}
// 	else {dfs(n+2, 0, result),dfs(n+3, 0, result);}
// }

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> board[i];

	dp[1] = board[1];
	dp[2] = dp[1] + board[2]; 

	for(int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 3] + board[i] + board[i - 1], dp[i - 2] + board[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << dp[N] << endl;
	return 0;
}