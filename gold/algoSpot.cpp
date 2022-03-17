// #1261
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#define MAX 101
#define INF 987654321
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, M, result = INF;
int board[MAX][MAX];
int cost[MAX][MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[MAX][MAX];

void Init()
{
	FOR(i, N)
		FOR(j, M)
			cost[i][j] = INF;
}
void bfs()
{
	deque<pair<int, int>> dq;
	dq.push_front({1, 1});
	cost[1][1] = 0;
	visited[1][1] = true;
	while(!dq.empty())
	{
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();
		// if(x == N && y == M) cout << '!' << endl;
		for(int i = 0; i < 4; i++)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(dx < 1 || dy < 1 || dx > N || dy > M || visited[dx][dy]) continue;
			if(board[dx][dy]){ // wall
				cost[dx][dy] = min(cost[dx][dy], cost[x][y] + 1); 
				dq.push_back({dx, dy});
			}
			else{ // not wall
				cost[dx][dy] = min(cost[dx][dy], cost[x][y]);
				dq.push_front({dx, dy});
			}
			visited[dx][dy] = true;
		}
	}
}
void dfs(int x, int y, int val)
{
	// cout << x << "/" << y << endl;
	if(x == N && y == M) 
	{
		result = min(result, val);
		return ;
	}
	for(int i = 0; i < 4; i++)
	{
		int dx = x + dxdy[i][0];
		int dy = y + dxdy[i][1];
		if(dx < 1 || dx > N || dy < 1 || dy > M || visited[dx][dy]) continue;
		if(board[dx][dy])
		{
			visited[dx][dy] = true;
			board[dx][dy] = 0;
			dfs(dx, dy, val + 1);
			board[dx][dy] = 1;
		}
		else
		{
			visited[dx][dy] = true;
			dfs(dx, dy, val);
		}
		visited[dx][dy] = false;
	}
}

void print()
{
	FOR(i, N)
	{
		FOR(j, M)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	cin >> M >> N;

	string input;
	FOR(i, N)
	{
		cin >> input;
		FOR(j, M){
			board[i][j] = input[j-1]-'0';
		}
	}
	
	// dfs(1, 1, 0);
	Init();
	bfs();
	cout << cost[N][M] << endl;
	return 0;
}