//#2178

#include<iostream>
#include<string>
#include<queue>

using namespace std;

int N, M, board[101][101], answer = 200;

void dfs(int x, int y, int result) // maybe.. bfs more fast than dfs.. 
// .. Memory overflow..
{
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	int dx, dy;

	if(x == N && y == M) { // if bfs, do not compare results
		if(result < answer) answer = result;
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		dx = dxdy[i][0] + x;
		dy = dxdy[i][1] + y;

		if(dx < 1 || dy < 1 || dx > N || dy > M) continue;
		if(board[dx][dy] == 0) continue;

		board[dx][dy] = 0;
		dfs(dx, dy, result+1);
		board[dx][dy] = 1;
	}
}


int main()
{

	string str = "";
	cin >> N >> M;
	queue<pair<int,int>> Que;
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	int dx, dy, x, y, result;
	// INPUT
	for(int i = 1; i <= N; i++)
	{
		cin >> str;
		for(int j = 1; j <= M; j++)
		{
			board[i][j] = str[j-1] - '0';
		}
	}

	Que.push(make_pair(1,1));
	while(!Que.empty())
	{
		x = Que.front().first;
		y = Que.front().second;
		result = board[x][y];

		Que.pop();
		cout << x <<"|" << y << " result : " << result << endl;
		
		if(x == N && y == M) {cout << board[x][y] << endl; break;}
		for(int i = 0; i < 4; i++)
		{
			dx = dxdy[i][0] + x;
			dy = dxdy[i][1] + y;

			if(dx < 1 || dy < 1 || dx > N || dy > M) continue;
			if(!board[dx][dy] || board[dx][dy] > result) continue;
			Que.push(make_pair(dx,dy));
			board[dx][dy] = result + 1;
		}
	}
	// dfs(1, 1, 1);
	// cout << answer << endl;
	return 0;
}