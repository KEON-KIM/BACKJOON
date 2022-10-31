//#3109
#include <algorithm>
#include <iostream>
#include <vector>

#define RMAX 10001
#define CMAX 501
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, M;
bool board[RMAX][CMAX] = {false, };
bool visited[RMAX][CMAX] = {false, };
int dxdy[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
void print()
{
	FOR(i, N)
	{
		FOR(j, M) cout << board[i][j] << ' ';
		cout << endl;
	}
	cout << "==========" << endl;
}
bool dfs(int x, int y)
{
	// print();
	if(y == M-1) return true;
	FOR(i, 3)
	{
		int dx = x + dxdy[i][0];
		int dy = y + dxdy[i][1];
		if(dx < 0 || dy < 0 || dx >= N || dy >= M ) continue;
		if(!board[dx][dy] && !visited[dx][dy])
		{
			visited[dx][dy] = true;
			if(dfs(dx, dy)) return true;
		}
	}
	return false;
}
int main()
{
	cin >> N >> M;
	char input;
	FOR(i, N)
		FOR(j, M)
		{
			cin >> input;
			if(input == 'x') board[i][j] = 1;
		}
	
	int result = 0;
	FOR(i, N) 
	{
		visited[i][0] = true;
		if(dfs(i, 0)) result++;
	}
	

	cout << result;
	return 0;
}
