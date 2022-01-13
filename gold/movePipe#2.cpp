#include<iostream>
#include<queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define MAX 33

using namespace std;

typedef long long ll;
int N, board[MAX][MAX];
ll DP[MAX][MAX][3];

ll solution()
{
	ll result = 0;
	DP[0][1][0] = 1;
	FOR(i, N)
		FOR(j, N){
			if((!j && !i) || board[i][j]) continue;

			if(!board[i][j+1])
				DP[i][j+1][0] = DP[i][j][2] + DP[i][j][0];

			if(!board[i+1][j])
				DP[i+1][j][1] = DP[i][j][2] + DP[i][j][1];

			if(i+1 < N && j+1 < N)
				if(!board[i][j+1] && !board[i+1][j] && !board[i+1][j+1])
					DP[i+1][j+1][2] = DP[i][j][0] + DP[i][j][1] + DP[i][j][2];
		}

	FOR(i, 3)
		result += DP[N-1][N-1][i];

	return result;
}	

int main()
{
	ll result = 0;
	cin >> N;
	FOR(i, N)
		FOR(j, N)
			cin >> board[i][j];

	// 

	result = solution();

	cout << result << endl;
	return 0;
}

/*
int dxdy[3][2] = {{0, 1}, {1, 1}, {1, 0}};


struct Data
{
	int x, y, idx;

	Data(int a, int b, int c){
		x = a;
		y = b;
		idx = c;
	}
};
void bfs()
{
	queue<Data> Que;
	Que.push(Data(0, 1, 0));
	DP[0][1][0] = 1;

	while(!Que.empty())
	{
		int dx, dy;

		int x = Que.front().x;
		int y = Que.front().y;
		int idx = Que.front().idx;
		Que.pop();

		// idx 0
		if(!idx){
			for(int i = 0; i < 2; i++)
			{
				dx = x + dxdy[i][0];
				dy = y + dxdy[i][1];
				if(dx < 0 || dy < 0 || dx > N || dy > N || board[dx][dy]) continue;
				if(i == 1) if(board[x][y+1] || board[x+1][y]) continue;
				DP[dx][dy][idx]++;
				Que.push(Data(dx,dy, i));
			}
		}
		// // idx 1
		else if(idx == 1){
			for(int i = 0; i < 3; i++)
			{
				dx = x + dxdy[i][0];
				dy = y + dxdy[i][1];
				if(dx < 0 || dy < 0 || dx > N || dy > N|| board[dx][dy]) continue;
				if(i == 1) if(board[x][y+1] || board[x+1][y]) continue;
				DP[dx][dy][idx]++;
				Que.push(Data(dx,dy, i));
			}
		}
		// // idx 2
		else {
			for(int i = 1; i < 3; i++)
			{
				dx = x + dxdy[i][0];
				dy = y + dxdy[i][1];
				if(dx < 0 || dy < 0 || dx > N || dy > N|| board[dx][dy]) continue;
				if(i == 1) if(board[x][y+1] || board[x+1][y]) continue;
				DP[dx][dy][idx]++;
				Que.push(Data(dx,dy, i));
			}
		}
	}
}*/
