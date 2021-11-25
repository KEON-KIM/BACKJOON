//# 16234
#include<iostream>

// int board[51][51];
int board[51][51][2];
int n, a, b;

void dfs(int x, int y, int before)
{
	int cnt = 0, total = 0;
	if(x >= n || y >= n || x < 0 || y < 0) return ;
	if(board[x][y][1]) return ;

	if(before < 0) board[x][y][1] = 1;
	else if(abs(before - board[x][y][0]) >= a && abs(before - board[x][y][0]) <= b) {board[x][y][1] = 1; cnt++;}
	dfs(x+1, y, board[x][y][0]); dfs(x-1, y, board[x][y][0]); dfs(x, y+1, board[x][y][0]); dfs(x, y-1, board[x][y]);
}

int main()
{
	cin >> n >> a >> b;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> board[i][j][0];
	
	int value;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			dfs(i, j, -1);
			if(value > board[i][j][0])
		}
	return 0;
}