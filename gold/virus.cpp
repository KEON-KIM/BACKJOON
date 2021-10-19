#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int N, M, maxZero = 0;
int board[8][8];
int tmp[8][8];
vector<pair<int, int>> virus;


void bfs(int x, int y, int &z)
{
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	int dx, dy, result = 0;
	queue<pair<int, int>> Que;

	Que.push(make_pair(x,y));

	while(!Que.empty())
	{
		x = Que.front().first;
		y = Que.front().second;
		Que.pop();

		for(int i = 0; i < 4; i++)
		{
			dx = dxdy[i][0] + x;
			dy = dxdy[i][1] + y;

			if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			if(tmp[dx][dy] != 0) continue;
			tmp[dx][dy] = 2;
			--z;
			Que.push(make_pair(dx,dy));
		}
	}
}

void make_wall(int cnt, int &result) //  Memory Over...flow..
{
	if(cnt == 0)
	{
		int zeroCnt = maxZero - 3;
		memcpy(tmp, board, sizeof(board));

		for(int k = 0; k < virus.size(); k++)
			bfs(virus[k].first, virus[k].second, zeroCnt);
		if(result < zeroCnt) result = zeroCnt; 
	}
	else
	{
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
			{
				if(!board[i][j]){
					board[i][j] = 1;
					make_wall(cnt-1, result);
					board[i][j] = 0;
				}
			}
	}
}
int main()
{
	int answer = 0;

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> board[i][j] ;
			if(board[i][j] == 2) virus.push_back(make_pair(i,j));
			if(board[i][j] == 0) maxZero++;
		}
	}

	make_wall(3, answer);

	cout << answer << endl;
	return 0;
}
