#include <iostream>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define INF 987654321
using namespace std;

int result = INF;
int dxdy[8][3][2] = {{{0, -1}, {1, -2}, {2, -3}}, {{0, -1}, {-1, -2}, {-2, -3}},
						{{0, 1}, {1, 2}, {2, 3}}, {{0, 1}, {-1, 2}, {-2, 3}},
						{{-1, 0}, {-2, 1}, {-3, 2}}, {{-1, 0}, {-2, -1}, {-3, -2}}, 
						{{1, 0}, {2, 1}, {3, 2}}, {{1, 0}, {2, -1}, {3, -2}}}; 
	// {2, -3}, {-2, -3}, {-3, 2}, {-3, -2}, {2, 3}, {-2, 3}, {3, 2}, {3, -2}};
bool visited[10][9] = {false, };
int _x;
int _y; // king
int x2, y2; // sang


void bfs(int ox, int oy)
{
	queue<pair<pair<int, int>, int>> Que;
	Que.push(make_pair(make_pair(ox, oy), 0));
	visited[ox][oy] = true;

	while(!Que.empty())
	{
		int x = Que.front().first.first;
		int y = Que.front().first.second;
		int cnt = Que.front().second;
		Que.pop();
		if(x == _x && y == _y) 
			result = min(result, cnt);
			
		FOR(i, 8)
		{
			FOR(j, 3)
			{
				int dx = x + dxdy[i][j][0];
				int dy = y + dxdy[i][j][1];
				if(dx < 0 || dy < 0 || dx >= 10 || dy >= 9 ) break;
				if(j != 2 && dx == _x && dy == _y) break;
				if(j == 2 && !visited[dx][dy])
				{
					visited[dx][dy] = true;
					Que.push(make_pair(make_pair(dx, dy), cnt+1));
				}
			}
		}
	}
}

int main()
{
	cin >> x2 >> y2;
	cin >> _x >> _y;

	bfs(x2, y2);
	if(result != INF)
		cout << result << endl;
	else
		cout << -1 << endl;
	return 0;
}