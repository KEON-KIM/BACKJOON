// #16958
#include<iostream>

#define MAX 1002
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

bool special[MAX];
int board[MAX][MAX];
pair<int, int> info[MAX];
int N, T, C;

void Floyd()
{
	FOR(dia, N)
	{
		FOR(i, N)
		{
			FOR(j, N)
			{
				if(i!=j)
					board[i][j] = min(board[i][j], board[i][dia] + board[dia][j]);
			}
		}
	}
}
void print()
{
	FOR(i, N)
	{
		FOR(j, N)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	fastio;
	cin >> N >> T;

	FOR(i, N)
	{
		int s, x, y;
		cin >> s >> x >> y;
		info[i] = make_pair(x, y);
		special[i] = s;
	}

	FOR(i, N)
	{
		for(int j = i + 1; j <= N; j++)
		{
			int dist = abs(info[i].first - info[j].first) + abs(info[i].second - info[j].second);
			if(special[i] && special[j]){
				board[i][j] = min(dist, T);
				board[j][i] = min(dist, T);
			}
			else
			{
				board[i][j] = dist;
				board[j][i] = dist;
			}
		}
	}
	print();

	Floyd();
	print();

	cin >> C;
	FOR(i, C)
	{
		int x, y;
		cin >> x >> y;
		cout << board[x][y] << endl;
	}
	
	return 0;
}