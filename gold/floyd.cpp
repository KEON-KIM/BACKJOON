// #11404 Floyd Warshall
#include<iostream>

#define MAX 101
#define INF 987654321
#define endl '\n'
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M;
int board[MAX][MAX];
void Init()
{
	FOR(i, N)
		FOR(j, N)
			if(i != j)
				board[i][j] = INF;
}
void Print()
{
	FOR(i, N){
		FOR(j, N){
			if(board[i][j] == INF)
				cout << 0 << " ";
 			else
 				cout << board[i][j] << " ";
 		}
		cout << endl;
	}
}

void Floyd()
{
	FOR(dia, N)
		FOR(i, N)
			FOR(j, N)
				board[i][j] = min(board[i][j], board[i][dia] + board[dia][j]);
}
int main()
{
	cin >> N >> M;
	Init();
	FOR(i, M){
		int x, y, cost;
		cin >> x >> y >> cost;
		board[x][y] = min(board[x][y], cost);
	}

	Print();
	Floyd();

	Print();
	return 0;
}