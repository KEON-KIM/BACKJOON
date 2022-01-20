//#1245
#include<iostream>
#include<queue>

#define HMAX 101
#define VMAX 71

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

bool visited[HMAX][VMAX], isPeak;
int N, M, board[HMAX][VMAX];
int result = 0;
int dxdy[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
					{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// 문제 잘못 읽어서 .. bfs ㅋ
/*void bfs(int a, int b)
{
	visited[a][b] = 1;
	board[a][b]  = 0;
	queue<pair<int , int>> Que;
	Que.push(make_pair(a, b));

	while(!Que.empty())
	{
		int x = Que.front().first;
		int y = Que.front().second;
		Que.pop();

		for(int i = 0; i < 8; i++)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(dx < 0 || dx >= N || dy < 0 || dy >= M || visited[dx][dy] || !board[dx][dy]) continue;

			Que.push(make_pair(dx, dy));
			// count--;
			board[dx][dy] = 0;
			visited[dx][dy] = true;
		}
	}
}
*/
void dfs(int x, int y)
{
	FOR(i, 8)
	{
		int dx = x + dxdy[i][0];
		int dy = y + dxdy[i][1];

		if(dx < 0 || dx >= N || dy < 0 || dy >= M ) continue;
		if(board[x][y] < board[dx][dy]) isPeak = false;
		if(visited[dx][dy] || board[x][y] != board[dx][dy]) continue;

		visited[dx][dy] = true;
		dfs(dx, dy);
	}

}
int main()
{
	cin >> N >> M;
	FOR(i, N)
		FOR(j, M)
			cin >> board[i][j];
			// if(board[i][j]) count++;
		
	FOR(i, N){
		FOR(j, M){
			if(!visited[i][j])
			{
				isPeak = true;
				visited[i][j] = true;
				dfs(i, j);
				if(isPeak) result++;
			}
		}
	}

	cout << result << endl;
	return 0;
}