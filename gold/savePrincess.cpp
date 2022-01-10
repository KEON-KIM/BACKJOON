// #17836

#include<iostream>
#include<queue>
#define MAX 101
#define INF 10001
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int N, M, T, result = INF;
int dxdy[4][2] = {{0, 1}, {0,-1}, {1, 0}, {-1, 0}};
int board[MAX][MAX], cnt[MAX][MAX];
bool visited[MAX][MAX];

void bfs()
{
	queue<pair<int, int>> Que;
	Que.push(make_pair(0, 0));
	visited[0][0] = true;

	while(!Que.empty())
	{
		int x = Que.front().first;
		int y = Que.front().second;
		Que.pop();

		if(x == N-1 && y == M-1) 
		{
			result = min(result, cnt[x][y]);
			return;
		}

		if(board[x][y] == 2)
			result = cnt[x][y] + (N-1) - x + (M-1) - y;
		

		for(int i = 0; i < 4; i++){
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(dx < 0 || dx >= N || dy < 0 || dy >= M || visited[dx][dy]) continue;
			if(board[dx][dy] == 1) continue;

			Que.push(make_pair(dx, dy));
			visited[dx][dy] = true;
			cnt[dx][dy] = cnt[x][y] + 1;
		}
	}

}

int main()
{
	cin >> N >> M >> T;
	FOR(i, N)
		FOR(j, M)
			cin >> board[i][j];

	bfs();
	if(result == INF) cout << "Fail" << endl;
	else
		if(result <= T) cout << result << endl;
		else cout << "Fail" << endl;
		 
	return 0;
}