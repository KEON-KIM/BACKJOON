// #2636
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 101

using namespace std;


int board[MAX][MAX];
int air_board[MAX][MAX]; // visited map;

int n, m, count = 0, timer = 0, result;
queue<pair<int, int>> cheese;

void print()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}


void Air_print()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << air_board[i][j] << " ";
		cout << endl;
	}
}

void delete_cheese()
{
	int x,y;

	while(!cheese.empty())
	{	
		x = cheese.front().first;
		y = cheese.front().second;
		cheese.pop();

		board[x][y] = 0;
	}
}

void bfs()
{
	int x, y, dx, dy;
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	queue<pair<int, int>> Que;
	Que.push(make_pair(0,0));

	while(!Que.empty())
	{
		x = Que.front().first;
		y = Que.front().second;
		Que.pop();

		for(int i = 0; i < 4; i++)
		{
			dx = x + dxdy[i][0];
			dy = y + dxdy[i][1];
			if(dx < 0|| dy < 0 || dx >= n || dy >= m || air_board[dx][dy]) continue;

			if(board[dx][dy] == 1)
			{
				cheese.push(make_pair(dx,dy));
				board[dx][dy] = 2;
			}

			else if(!board[dx][dy]){
				Que.push(make_pair(dx, dy));	
				air_board[dx][dy] = 1;
			} 
		}
	
	}
	if((count - cheese.size())){
		count -= cheese.size();		
		result = count;
	}
	else
		count -= cheese.size();

	timer++;

	delete_cheese();
	memset(air_board, 0, sizeof(air_board));
}
int main()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if(board[i][j]) count++;
		}
	}
	result = count;
	while(count>0)
		bfs();
	
	
	cout << timer << endl;
	cout << result << endl;

	return 0;
}