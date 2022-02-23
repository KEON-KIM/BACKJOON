#include<iostream>

#define MAX 11
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int T, N, M, result = 0;
int board[MAX][MAX];
bool visited[MAX] = {false, };


void dfs(int idx, int cmp)
{
	if(idx == MAX) 
	{
		result = max(result, cmp);
		return;
	}
	FOR(i, MAX)
	{
		if(!visited[i] && board[idx][i])
		{
			visited[i] = true;
			dfs(idx+1, cmp + board[idx][i]);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> T;
	FOR(t, T)
	{
		result = 0;
		FOR(i, MAX)
			FOR(j, MAX)
				cin >> board[i][j];
		
		dfs(0, 0);
		cout << result << endl;
	}
	
	return 0;
}