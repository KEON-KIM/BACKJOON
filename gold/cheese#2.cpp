#include <iostream>
#include <cstring>
#include <queue>

#define MAX 101
#define FOR(i, n) for(int i = 1; i < n; i++)
using namespace std;

int N, M;
int ch_cnt = 0;
int tmp[MAX][MAX];
int board[MAX][MAX]; // 0 : outside / 1 : cheese / 2 : inside
int dxdy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool visited[MAX][MAX];
void Print()
{
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
void Equals()
{
	FOR(i, N)
		FOR(j, M)
			board[i][j] = tmp[i][j];
}

void bfs()
{
	queue<pair<int ,int>> Que;
	Que.push({0, 0});
	memset(visited, false, sizeof(visited));
	while(!Que.empty())
	{
		int x = Que.front().first;
		int y = Que.front().second;
		Que.pop();
		for(int i = 0; i < 4; i++)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(board[dx][dy] == 1 || visited[dx][dy]) continue;
			if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			Que.push({dx, dy});
			board[dx][dy] = 0;
			visited[dx][dy] = true;
		}
	}
}

int dfs(int day)
{
	// cout << "====================================" << endl;
	if(!ch_cnt) return day;
	memset(tmp, 0, sizeof(tmp));
	bfs(); // check for outside air or inside air
	// Print();
	FOR(i, N)
	{
		FOR(j, M)
		{
			if(board[i][j])
			{
				int cnt = 0;
				for(int k = 0; k < 4; k++)
				{
					int x = i + dxdy[k][0];
					int y = j + dxdy[k][1];

					if(x >= N || x < 0 || y >= M || y < 0) continue;
					if(!board[x][y]) cnt++;
				}

				if(cnt > 1){
					tmp[i][j] = 0;
					ch_cnt--;
				} 
				else tmp[i][j] = board[i][j];
			}
		}
	}

	Equals();

	return dfs(day + 1);
}

int main()
{
	int input;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if(board[i][j]) ch_cnt++;
			if(!board[i][j])board[i][j] = 2;
		}
	}

	cout << dfs(0);
	return 0;
}

// 8 9
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 1 1 0 0 0 1 1 0
// 0 1 0 1 1 1 0 1 0
// 0 1 0 0 1 0 0 1 0
// 0 1 0 1 1 1 0 1 0
// 0 1 1 0 0 0 1 1 0
// 0 0 0 0 0 0 0 0 0 