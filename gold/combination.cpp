#include <iostream>
#include <queue>

#define MAX 51
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, M, K;
int result = 0;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void print()
{
	FOR(i, N){
		FOR(j, M)
			cout << visited[i][j] << " ";
		cout << endl;
	}

}
bool bfs(int a, int b)
{
	bool visited_bfs[MAX][MAX] = {false, }; // 재방문 방지
	queue<pair<int, int>> Que;
	Que.push({a, b});

	int cnt = 1;
	visited_bfs[a][b] = true;
	while(!Que.empty())
	{
		int x = Que.front().first;
		int y = Que.front().second;
		Que.pop();

		// if(visited[x][y]) cnt++;
		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			if(visited[dx][dy] && !visited_bfs[dx][dy])
			{
				cnt++;
				Que.push({dx, dy});
				visited_bfs[dx][dy] = true;
			}
		}
	}

	return cnt == K;
}

void dfs(int x, int y, int idx, int res)
{
	if(idx >= K-1)
	{
		if(res > result && bfs(x, y))
			result = res;
		cout << "!" << endl;
		return;
	}
	for(int i = x; i < N; i++)
		for(int j = 0; j < M; j++)
			if(!visited[i][j])
			{
				visited[i][j] = true;
				dfs(i, j, idx+1, res + board[i][j]);
				visited[i][j] = false;
			}
}

int solution()
{
	FOR(i, N)
		FOR(j, M)
			cin >> board[i][j];

	FOR(i, N)
		FOR(j, M)
		{
			cout << "-" << endl;
			if(!visited[i][j])
			{
				visited[i][j] = true;
				dfs(i, j, 0, board[i][j]);
				visited[i][j] = false;
			}
		}

	return result;
}

int main()
{
	cin >> N >> M >> K;
	cout << solution() << endl;

	return 0;
}

/*
2 2 3
1 2
4 5
*/
/*
4 5 4
0 3 5 4 2
1 2 2 1 1
4 1 3 6 3
1 0 9 1 7
*/

/*
4 5 4
0 3 2 1 0
2 4 5 0 1
1 1 2 8 1
9 1 1 2 1
*/
/*
20 20 5
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3 
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
0 3 2 1 0 2 9 2 8 4 3 1 3 4 5 6 7 8 2 3
*/