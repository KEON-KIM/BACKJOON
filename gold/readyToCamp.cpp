//#16938
#include <iostream>
#include <algorithm>

#define MAX 16
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

typedef long long ll;

ll L, R;
bool visited[MAX];
int board[MAX];
int N, X, result = 0;
bool dia(int index, ll s, int m)
{
	for(int i = index; i < N; i++)
	{
		if(!visited[i])
		{
			if(s + board[i] <= R)
				return true;
		}
	}
	return false;
}

void dfs(int index, ll S, int M)
{
	for(int i = index; i < N; i++)
	{
		if(!visited[i] && dia(i, S, M)){
			visited[i] = true;
			dfs(i, S + board[i], M);
			visited[i] = false;
		}
	}
	if(board[index] - M >= X && S >= L)
		result++;
}

int main()
{
	cin >> N >> L >> R >> X;
	FOR(i, N)
		cin >> board[i];

	sort(board, board+N);
	FOR(i,N){
		visited[i] = true;
		dfs(i, board[i], board[i]);
	}

	cout << result << endl;
	return 0;
}