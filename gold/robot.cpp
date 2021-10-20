//#14503
#include<iostream>
#define MAX 50

using namespace std;

int N, M;
int board[MAX][MAX];
// 0 : North / 1 : East / 2 : South / 3 : West
int dxdy[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
// int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int clear = 1;

void dfs(int x, int y, int dir)
{
	int dx, dy, cur_dir;
	int condition = 0;

	for(int i = dir-1; i > dir-5; i--)
	{
		cur_dir = i < 0 ? i + 4 : i;

		dx = x + dxdy[cur_dir][0];
		dy = y + dxdy[cur_dir][1];
		if(dx < 0 || dx >= N || dy < 0 || dy >= M) condition++;
		else if (board[dx][dy] == 1 || board[dx][dy] == 2) condition++;
		else
		{
			clear++;
			board[dx][dy] = 2;
			cout << dx<<" | " << dy << endl;
			dfs(dx, dy, cur_dir);
			break;
		}
	}
	if(condition > 3)
	{
		int back_dir = dir + 2 > 3?  (dir+2) % 4 : dir + 2;
		dx = x + dxdy[back_dir][0];
		dy = y + dxdy[back_dir][1];

		if(dx < 0 || dx >= N || dy < 0 || dy >= M) return;
		if(board[dx][dy] == 1) return;

		dfs(dx, dy, dir);
	}
}

int main()
{
	int r, c ,dir;
	cin >> N >> M;
	cin >> r >> c >> dir;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			// if (board[i][j] == 0) dirty++;
		}
	}

	board[r][c] = 2;
	dfs(r,c,dir);

	cout << clear << endl;
	return 0;
}