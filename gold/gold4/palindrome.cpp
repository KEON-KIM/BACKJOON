#include <iostream>
#include <vector>

#define endl '\n'
#define MAX 2002
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int N, M, board[MAX];
bool dp[MAX][MAX] = {false, };
int main()
{
	fastio;
	cin >> N;
	FOR(i, N) cin >> board[i];
	FOR(i, N)
	{
		dp[i][i] = true; // size 1
		if(board[i] == board[i+1]) dp[i][i+1] = true; // size 2
	}
		

	for(int i = N; i >= 1; i--)
		for(int j = i + 2; j <= N; j++)
			if(board[i] == board[j] && dp[i+1][j-1]) dp[i][j] = true;
	
	cin >> M;
	FOR(i, N){
		FOR(j, N)
			cout << dp[i][j] << ' ';
		cout << endl;
	}
	FOR(i, M)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << endl;
	}
	return 0;
}