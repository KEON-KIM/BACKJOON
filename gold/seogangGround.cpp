#include <iostream>
#include <algorithm>

#define MAX 102
#define INF 1000000000
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, M, R, result;
int board[MAX][MAX];
int item[MAX];
void Init()
{
	FOR(i, N)
		FOR(j, M)
			if(i != j)
				board[i][j] = INF;
}

void Floyd()
{
	FOR(dia, N)
		FOR(i, N)
			FOR(j, N)
			if(board[i][j] > board[i][dia]+board[dia][j])
				board[i][j] = board[i][dia] + board[dia][j];
			

	FOR(i, N)
	{
		int tmp = item[i];
		FOR(j, N)
			if(i != j && board[i][j] <= M)
				tmp += item[j];
		
		result = max(result, tmp);
	}
}


int main()
{
	cin >> N >> M >> R;
	Init();

	FOR(i, N)
		cin >> item[i];

	FOR(i, R)
	{
		int a, b, l;
		cin >> a >> b >> l;
		board[a][b] = l;
		board[b][a] = l;
	}
	Floyd();

	cout << result;
	return 0;
}