//#1613
#include <iostream>
#include <cstring>
#include <vector>

#define endl '\n'
#define MAX 402
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, M, K;
int board[MAX][MAX];
int main()
{
	fastio;
	int a, b;
	cin >> N >> K;
	FOR(i, K)
	{
		cin >> a >> b;
		board[a][b] = -1;
		board[b][a] = 1;
	}

	FOR(dia, N)
		FOR(i, N)
			FOR(j, N)
			{
				if(i == j || i == k || j == k) continue;
				if(!board[i][j])
				{
					if(board[i][dia] == 1 && board[dia][j] == 1)
						board[i][j] = 1;
					else if(board[i][dia] == -1 && board[dia][j] == -1)
						board[i][j] = -1;
				}
			}

	cin >> M;
	FOR(i, M)
	{
		cin >> a >> b;
		cout << board[a][b] << endl;
	}
	return 0;
}