#include <iostream>
#include <cstring>

#define MAX 301
#define ZFOR(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i < n-1; i++)
using namespace std;

int N, M, years = 0;
int board[MAX][MAX], cache[MAX][MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[MAX][MAX];

void print()
{
	ZFOR(i, N)
	{
		ZFOR(j, M)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
void dfs(int x, int y)
{
	int melt = 0;
	ZFOR(i, 4)
	{
		int dx = x + dxdy[i][0];
		int dy = y + dxdy[i][1];
		if(!board[dx][dy] && !visited[dx][dy]) 
			melt++;
	}
	board[x][y] = board[x][y] - melt > 0 ? board[x][y] - melt : 0;

	ZFOR(i, 4)
	{
		int dx = x + dxdy[i][0];
		int dy = y + dxdy[i][1];
		if(dx < 1 || dx >= N-1 || dy < 1 || dy >= M-1 ||
			 visited[dx][dy] || !board[dx][dy]) continue;

		visited[dx][dy] = true;
		dfs(dx, dy);
	}

}
int main()
{
	cin >> N >> M;
	ZFOR(i, N)
		ZFOR(j, M)
			cin >> board[i][j];
	
	int iceburg = 0;
	while(iceburg < 2)
	{
		iceburg = 0;
		memset(visited, false, sizeof(visited));
		FOR(i, N)
		{
			FOR(j, M)
			{
				if(board[i][j] && !visited[i][j])
				{
					visited[i][j] = true;
					dfs(i, j);
					iceburg++;
				}
			}
		}
		years ++;
		if(iceburg == 0) 
		{
			cout << 0 << endl;
			return 0;
		}
	}	

	cout << years - 1<< endl;
	return 0;
}