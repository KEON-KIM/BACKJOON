// #2146
#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define MAX 101
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;

int N, board[MAX][MAX] = {0, }, cnt = 1, min_dst = 1e9;
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool outskirt[MAX][MAX] = {false, };
void bfs(int a, int b, bool flag)
{
	int start = board[a][b];
	if(flag) // 외곽지역 찾기
	{
		queue<pii> Que;
		Que.push({a, b});
		board[a][b] = ++cnt;
		while(!Que.empty())
		{

			int x = Que.front().first;
			int y = Que.front().second;
			Que.pop();
			
			FOR(i, 4)
			{
				int dx = x + dxdy[i][0];
				int dy = y + dxdy[i][1];
				if(dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
				if(board[dx][dy] && start != board[dx][dy]) continue;
				if(!board[dx][dy])
				{
					outskirt[x][y] = true;
					continue;
				}
				Que.push({dx, dy});
				board[dx][dy] = cnt;
			}
		}
	}
	else // 가장 짧은 길 업데이트하기
	{
		queue<pair<int, pii>> Que;
		bool visited[MAX][MAX] = {false, };
		visited[a][b] = true;
		Que.push({0, {a, b}});
		while(!Que.empty())
		{
			int move = Que.front().first;
			int x = Que.front().second.first;
			int y = Que.front().second.second;
			Que.pop();

			if(move > min_dst) break;
			if(board[x][y] && start != board[x][y]) 
			{
				min_dst = min(min_dst, move); 
				outskirt[x][y] = false;
				break;
			}

			FOR(i, 4)
			{
				int dx = x + dxdy[i][0];
				int dy = y + dxdy[i][1];
				if(visited[dx][dy]) continue;
				if(dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
				if(start == board[dx][dy]) continue;
				Que.push({move+1, {dx, dy}});
				visited[dx][dy] = true;
			}
		}
	}
}

int main()
{
	cin >> N;
	FOR(i, N)
		FOR(j, N)
			cin >> board[i][j];

	FOR(i, N)
		FOR(j, N)
			if(board[i][j] == 1)
				bfs(i, j, true);

	FOR(i, N)
		FOR(j, N)
			if(outskirt[i][j])
				bfs(i, j, false);

	cout << min_dst-1;
	return 0;
}