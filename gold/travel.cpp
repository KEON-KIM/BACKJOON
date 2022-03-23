#include <iostream>

#define MAX 201
#define INF 987654321
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, M;
int board[MAX][MAX];
int schedule[1001];
void Init()
{
	FOR(i, N)
		FOR(j, N)
		{
			if(i == j) board[i][j] = 0;
			else board[i][j] = INF;
		}
}
void Folyd()
{
	FOR(dia, N)
		FOR(i, N)
			FOR(j, N)
				if(i != j)
					board[i][j] = min(board[i][j], board[i][dia] + board[dia][j]);
}
void print()
{
	FOR(i, N){
		FOR(j, N)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	cin >> N >> M;
	Init();

	FOR(i, N)
		FOR(j, N){
			int x; cin >> x;
			if(x) board[i][j] = x;
		}

	FOR(i, M)
		cin >> schedule[i];
	Folyd();

	bool flag = false;
	FOR(i, M-1)
	{
		int cur = schedule[i];
		int next = schedule[i+1];

		if(board[cur][next] == INF)
		{
			flag = true;
			break;
		}
	}
	// print();
	if(flag) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}

// 5 5
// 0 1 0 1 1
// 1 0 1 1 0
// 0 1 0 0 0
// 1 1 0 0 0
// 1 0 0 0 0
// 5 3 2 3 4