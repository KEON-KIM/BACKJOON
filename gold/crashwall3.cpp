#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define MAX 1000

using namespace std;


int N, M;
int board[MAX][MAX];
int visit[MAX][MAX][2]; //  when do not crash the wall or when crash to wall

int main()
{
	string line;
	int x, y, wal, val;
	int dxdy[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int min = -1;

	cin >> N >> M;

	queue<pair<pair<int, int>, pair<int, int>>> cache; // pair<x,y>, pair<wal, val>

	for(int i = 0; i < N; i++)
	{
		cin >> line;
		for(int j = 0; j < M; j++){
			board[i][j] = (int)line[j] - '0';
		}
	}
	cache.push(make_pair(make_pair(0,0), make_pair(0,1))); // 0 : NOT CRASH / 1 : CRASH

	visit[0][0][0] = 1;

	while(!cache.empty())
	{
		pair<int, int> cur = cache.front().first;
		wal = cache.front().second.first;
		val = cache.front().second.second;

		cache.pop();
		if(cur.first == N - 1 && cur.second == M - 1 ){min = val;break;}
		for(int i = 0; i < 4; i++)
		{
			x = cur.first + dxdy[i][0];
			y = cur.second + dxdy[i][1];

			if(x >= 0 && x < N && y >= 0 && y < M) // In board 
			{
				if(board[x][y] == 0 && visit[x][y][wal] == 0) // Can move to x,y in board AND Not visited
				{
					visit[x][y][wal] = val+1;
					cache.push(make_pair(make_pair(x, y), make_pair(wal, val+1)));
					// cout << x << "|" << y << " VAL : " << val << " WAL : " << wal << endl;
				}
				if(board[x][y] == 1 && visit[x][y][wal] == 0 && !wal)
				{					
					visit[x][y][wal+1] = val+1;
					cache.push(make_pair(make_pair(x, y), make_pair(wal+1, val+1)));
					// cout << x << "|" << y << " VAL : " << val << " WAL : " << wal << endl;
				} 
			}
		}
	}
	
	cout << min << endl;

	return 0;
}