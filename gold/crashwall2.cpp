#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>

#define MAX 1001

using namespace std;

int N, M;
int board[MAX][MAX];
int visit[MAX][MAX][2];

void print()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j<M; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

int main()
{
	string line;
	queue<pair<pair<int,int>,int >> cache;
	int dxdy[4][2] = { {1, 0}, {-1, 0}, {0,1}, {0,-1}}, x, y, cmp, wal;
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		cin >> line;
		for(int j = 0; j < M; j++){
			visit[i][j][0] = 0; // count 
			visit[i][j][1] = 0; // not visited
			board[i][j] = (int)line[j] - '0';
		}
	}
	visit[0][0][0] = 0;
	visit[0][0][1] = 1;
	visit[N-1][M-1][0] = MAX * 2;

	cout << endl;

	print();
	cache.push(make_pair(make_pair(0,0),1));

	while(!cache.empty())
	{
		pair<int, int > cur = cache.front().first;
		wal = cache.front().second;
		cout << cur.first << "|" << cur.second <<  " WAL : " << wal << endl;
		cache.pop();
		for(int i = 0; i < 4; i++)
		{
			cmp = visit[cur.first][cur.second][0]; // before value
			x = cur.first + dxdy[i][0];
			y = cur.second + dxdy[i][1];

			if(x == N -1 && y == M -1)
			{
				if(visit[x][y][0] > ++cmp)
					visit[x][y][0] = cmp;
			}

			if(x >= 0 && x < N && y >= 0 && y < M)
			{
				if(board[x][y] == 0 && visit[x][y][1] == 0)
				{
					cache.push(make_pair(make_pair(x,y), wal));
					visit[x][y][1] = 1;
					visit[x][y][0] = cmp + 1;
				}
				else if(board[x][y] == 1 && wal > 0)
				{
					cache.push(make_pair(make_pair(x,y), 0));
					visit[x][y][1] = 1;
					visit[x][y][0] = cmp + 1;
				}
			}

		}
	}
	if(visit[N-1][M-1][0] == MAX * 2)
		cout << -1 << endl;
	else
		cout << visit[N-1][M-1][0];


	return 0;
}