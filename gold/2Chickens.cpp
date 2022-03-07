// #21278
#include <iostream>

#define MAX 101
#define INF 987654321
#define endl '\n'
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int N, M, result = INF;
pair<int, int> answer;
int board[MAX][MAX];

void Init()
{
	FOR(i, N)
		FOR(j, N)
			if(i != j)
				board[i][j] = INF;
}
void Input()
{
	FOR(i, M)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
		board[y][x] = 1;
	}
}

void Floyd()
{
	FOR(dia, N)
		FOR(i, N)
			FOR(j, N)
				board[i][j] = min(board[i][j], board[i][dia] + board[dia][j]);
}

void print()
{
	FOR(i, N){
		FOR(j, N)
			cout << board[i][j] << ' ';
	cout << endl;
	}
}

void Solve()
{
	Init();
	Input();
	Floyd();
}
int main()
{
	cin >> N >> M;

	Solve();

	int cnt = 0;
	FOR(i, N)
		for(int j = i; j <= N; j++){
			cnt = 0;
			FOR(k, N)
				cnt += min(board[i][k], board[j][k]) * 2;
			if(cnt < result){
				result = cnt;
				answer = {i, j};
			}
		}
	
	cout << answer.first << ' ' << answer.second << ' ' << result << endl;
	return 0;
}