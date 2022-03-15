// #3055
#include <iostream>
#include <queue>

#define MAX 51
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int N, M, result;
int cost[MAX][MAX];
char board[MAX][MAX];

pair<int, int> dest;
queue<pair<int, int>> waterFront;
queue<pair<int, int>> Que;


void print()
{
	FOR(i, N)
	{
		FOR(j, M)
			cout << cost[i][j] << " ";
		cout << endl;
	}
}
const int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int bfs()
{
	cost[Que.front().first][Que.front().second] = 1;
	while(!Que.empty())
	{
		int size = waterFront.size();
		FOR(t, size)
		{
			int x = waterFront.front().first;
			int y = waterFront.front().second;
			waterFront.pop();
			FOR(i, 4)
			{
				int dx = x + dxdy[i][0];
				int dy = y + dxdy[i][1];

				if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
				if(board[dx][dy] == '.')
				{
					board[dx][dy] = '*';
					waterFront.push({dx, dy});
				}
				
			}
		}
		size = Que.size();
		FOR(t, size)
		{
			int x = Que.front().first;
			int y = Que.front().second;
			Que.pop();

			if(x == dest.first && y == dest.second)
				return (cost[x][y] - 1);
			
			FOR(i, 4)
			{
				int dx = x + dxdy[i][0];
				int dy = y + dxdy[i][1];

				if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
				if(board[dx][dy] == 'X') continue;
				if(cost[dx][dy] || board[dx][dy] == '*') continue;
				cost[dx][dy] = cost[x][y] + 1;
				Que.push({dx, dy});
			}
		}
	}
		
	return -1;
}
int main()
{
	cin >> N >> M;
	FOR(i, N)
	{
		FOR(j, M)
		{
			cin >> board[i][j];
			if(board[i][j] == '*')
				waterFront.push({i, j});
			
			else if(board[i][j] == 'D')
				dest = {i, j};
			
			else if(board[i][j] == 'S')
				Que.push({i, j});
		}
	}
	result = bfs();

	if(result > 0) cout << result << endl;
	else cout << "KAKTUS" << endl;

	return 0;
}
