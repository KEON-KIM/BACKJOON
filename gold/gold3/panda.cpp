#include <iostream>
#include <queue>

#define MAX 501
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N;
int result = 0;
int board[MAX][MAX];
int dist[MAX][MAX];
int dxdy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void print()
{
	cout << "=================" << endl;
	FOR(i, N){
		FOR(j, N)
			cout << dist[i][j] << " ";
		cout << endl;
	}
}

int dfs(int x, int y)
{
	print();    
	if(dist[x][y]) return dist[x][y];
	dist[x][y] = 1;
	FOR(i, 4)
	{
		int dx = x + dxdy[i][0];
		int dy = y + dxdy[i][1];
		if(dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
		if(board[x][y] < board[dx][dy])
		{
			dist[x][y] = max(dist[x][y], dfs(dx, dy) + 1);
		}
	}

	return dist[x][y];
}

int main()
{
	cin >> N;

	FOR(i, N)
		FOR(j, N)
			cin >> board[i][j];

	FOR(i, N)
		FOR(j, N)
			if(!dist[i][j])
				result = max(result, dfs(i, j));
	

	cout << result  << endl;

	
	return 0;
}