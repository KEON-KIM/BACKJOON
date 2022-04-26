#include <iostream>
#define MAX 50002
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, K, result = 0;
int board[MAX], DP[3][MAX], sum[MAX];
void print()
{
	FOR(i, N)
		cout << DP[0][i] << " ";
	cout << endl;
}
int main()
{
	fastio;
	cin >> N;
	FOR(i, N)
	{
		cin >> board[i];
		sum[i] = sum[i-1] + board[i];
	}
	
	FOR(i, N) cout << sum[i] << " ";
	cin >> K;

	for(int i = 1; i < 4; i++)
		for(int j = K*i; j <= N; j++)
			DP[i][j] = max(DP[i][j-1], DP[i-1][j-K] + (sum[j] - sum[j - K]));
		
	
	cout << DP[3][N] << endl;

	return 0;
}