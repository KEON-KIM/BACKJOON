#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int board[8][8];
vector<pair<int, int>> virus;


int bfs(int x, int y)
{
	int tmp[8][8];
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	int dx, dy, result = 0;
	queue<pair<int, int>> Que;

	Que.push(make_pair(x,y));
	//copy
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			tmp[i][j] = board[i][j];

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
			Que.push(make_pair(dx,dy));
		}
	}
	// safe_check
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(tmp[i][j] == 0) result++;

	return result;
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> board[i][j] ;
			if(board[i][j] == 2) virus.push_back(make_pair(i,j));
		}
	}
	
	bfs(virus[0].first, virus[0].second) << endl;// virus 
	return 0;
}
