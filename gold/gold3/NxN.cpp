//#11049
//@Reference <cocoon> https://cocoon1787.tistory.com/318
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 501
#define INF 987654321

int sum[MAX], board[MAX][2], dp[MAX][MAX];
int main()
{
	int N, r, c;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> r >> c;
		board[i][0] = r;
		board[i][1] = c;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; i + j <= N; j++)
		{
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++)
			{
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + board[j][0] * board[k][1] * board[i+j][1]);
			}
		}

	}

	cout << dp[1][N];
}