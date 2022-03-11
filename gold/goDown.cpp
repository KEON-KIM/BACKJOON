//#1520
#include <iostream>

using namespace std;

#define MAX 501
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int N, M;
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int board[MAX][MAX], dp[MAX][MAX];
int dfs(int x, int y)
{
	int &ret = dp[x][y];
	if(x == N - 1 && y == M - 1) return 1;
	if(ret != -1) return ret;

	ret = 0;
	for(int i = 0; i < 4; i++){
		int dx = x + dxdy[i][0];
		int dy = y + dxdy[i][1];

		if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
		if(board[x][y] <= board[dx][dy]) continue;
		
		ret += dfs(dx, dy);
	}

	dp[x][y] = ret;
	return ret;
}

int main()
{
	cin >> N >> M;
	FOR(i, N)
		FOR(j, M){
			cin >> board[i][j];
			dp[i][j] = -1;
		}

	cout << dfs(0, 0) << endl;

	return 0;
}