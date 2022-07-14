#include <iostream>
#include <vector>

#define MAX 51
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, M, K;
int board[MAX][MAX];
bool visited[MAX][MAX][11];
bool draw_map[MAX][MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void print()
{
	FOR(i, N)
	{
		FOR(j, M)
			cout << draw_map[i][j] << " ";
		cout << endl;
	}
}

void dfs(int x, int y, int cnt, vector<pair<int, int>> cache)
{
	cout << x << " / " << y  << " / " << cnt << endl;
	if(cnt >= K-1)
	{
		cout << "======" << endl;
		// print();
		return;
	}
	for(pair<int, int> p : cache) // return before pos
	{
		if(!visited[p.first][p.second][cnt])
		{
			visited[p.first][p.second][cnt] = true;
			dfs(p.first, p.second, cnt, cache);
			visited[p.first][p.second][cnt] = false;
		}
	}

	cache.push_back({x, y});
	FOR(i, 4)
	{
		int dx = x + dxdy[i][0];
		int dy = y + dxdy[i][1];
		if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
		if(!visited[dx][dy][cnt+1] && !visited[dx][dy][cnt])
		{
			draw_map[dx][dy] = true; 
			visited[dx][dy][cnt+1] = true;
			dfs(dx, dy, cnt+1, cache);
			visited[dx][dy][cnt+1] = false;
			draw_map[dx][dy] = false;
		}
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
			if(!visited[i][j][0])
			{
				vector<pair<int, int>> cache;
				draw_map[i][j] = true;
				visited[i][j][0] = true;
				dfs(0, 0, 0, cache);
				visited[i][j][0] = false;
				draw_map[i][j] = false;
			}
		}

	return 0;
}
int main()
{
	cin >> N >> M >> K;
	cout << solution() <<endl;
	return 0;
}

/*3 3 4
1 2 3
4 5 6
7 8 9*/

/*2 2 3
1 2
4 5
*/

