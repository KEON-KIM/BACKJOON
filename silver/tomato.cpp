#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000

using namespace std;


int N, M, depth, zeroCnt = 0;
int board[MAX][MAX];
vector<pair<int, int>> xy;
queue<pair<int, pair<int, int>>> Que;

void bfs()
{
	int dxdy[4][2] ={ {1,0}, {-1, 0}, {0, 1}, {0, -1}};
	int x, y, dx, dy;

	while(!Que.empty())
	{
		bool flag = false;
		depth = Que.front().first;
		x = Que.front().second.first;
		y = Que.front().second.second;

		Que.pop();

		for(int i = 0; i < 4; i++)
		{
			dx = x + dxdy[i][0];
			dy = y + dxdy[i][1];

			if(dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
			else if (board[dx][dy] == 1 || board[dx][dy] == -1) continue;
 			else
			{
				board[dx][dy] = 1;
				zeroCnt--;
				Que.push(make_pair(depth + 1, make_pair(dx,dy)));
			} 
		}
	}
}
int main()
{
	cin >> M >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0 ; j < M; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 1)
				Que.push(make_pair(0,make_pair(i,j)));
			else if (!board[i][j])
				zeroCnt++;
		}
	bfs();

	// board print
	// for (int i = 0; i < N ; i++)
	// {
	// 	for(int j = 0; j < M ; j++)
	// 		cout << board[i][j] << " ";
	// 	cout << endl;
	// }

	if (!zeroCnt)
		cout << depth << endl;
	else 
		cout << "-1" << endl;
	return 0;
}