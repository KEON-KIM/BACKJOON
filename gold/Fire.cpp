#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 1002
#define INF  1000001
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int N, M, T;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dxdy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

typedef pair<int, int> pii;
pii start;
vector<pii> fire;
void Print()
{
	FOR(i, N)
	{
		FOR(j, M)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
int bfs(int startX, int startY)
{
	int result = 0;
	queue<pair<int, int>> Que; //{type, {x,y}}
	queue<pair<int, int>> fireQue;
	visited[startX][startY] = true;

	Que.push({startX, startY});
	for(pii p : fire)
		fireQue.push({p.first, p.second});
	
	while(!Que.empty())
	{
		int fireQueSize = fireQue.size();
		FOR(t, fireQueSize)
		{
			int x = fireQue.front().first;
			int y = fireQue.front().second;
			fireQue.pop();

			for(int i = 0; i < 4; i++)
			{
				int dx = x + dxdy[i][0];
				int dy = y + dxdy[i][1];

				if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
				if(board[dx][dy] == 2 || board[dx][dy] == 3) continue;
				board[dx][dy] = 3;
				fireQue.push({dx, dy});
			}
		}
		int QueSize = Que.size();
		FOR(t, QueSize)
		{
			int x = Que.front().first;
			int y = Que.front().second;
			Que.pop();

			if(x == 0 || y == 0 || x == N - 1 || y == M - 1) return result + 1;
			for(int i = 0; i < 4; i++)
			{
				int dx = x + dxdy[i][0];
				int dy = y + dxdy[i][1];

				if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
				if(board[dx][dy] == 2 || board[dx][dy] == 3 || visited[dx][dy]) continue;
				visited[dx][dy] = true;
				Que.push({dx, dy});

			}
		}
		result++;
	}

	return -1;
}

void Init()
{
	memset(visited, false, sizeof(visited));
	fire.clear();
}
int main()
{
	int result = -1;
	string input;
	cin >> T;
	FOR(t, T){
		cin >> M >> N;
		Init();
		FOR(i, N){
			cin >> input;
			FOR(j, M)
			{
				if(input[j] == '#')
				{
					board[i][j] = 2;
				}
				else if(input[j] == '*')
				{
					board[i][j] = 3;
					fire.push_back({i, j});
				}
				else if(input[j] == '@')
				{
					board[i][j] = 1;
					start.first = i;
					start.second = j;
				}
				else
					board[i][j] = 0;
			}
		}
		result = bfs(start.first, start.second);
		if(result == -1)
			cout << "IMPOSSIBLE" <<endl;
		else
			cout << result << endl;
		// Print();
	}

	return 0;
}
// Origin BFS
/*while(!Que.empty()){
	int type = Que.front().first;
		int curX = Que.front().second.first;
		int curY = Que.front().second.second;
		Que.pop();

		if(type == 1) cout << "X : " << curX << " Y : " << curY << endl;
		for(int i = 0; i < 4; i++)
		{
			int nextX = curX + dxdy[i][0];
			int nextY = curY + dxdy[i][1];
			if(type == 3)
			{
				if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)
					continue;
				if(board[nextX][nextY] == 2 || board[nextX][nextY] == 3) continue;
				board[nextX][nextY] = 3;
				Que.push({type, {nextX, nextY}});
			}
			else
			{
				if(board[nextX][nextY] == 2 || board[nextX][nextY] == 3) continue;
				if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)
					return visited[curX][curY];
				if(visited[nextX][nextY] > visited[curX][curY] + 1)
				{
					visited[nextX][nextY] = visited[curX][curY] + 1;
					Que.push({type, {nextX, nextY}});
				}
			}
			// if(visited[nextX][nextY] <= visited[curX][curY] + 1) continue;
		}
	}

	return -1;
}*/