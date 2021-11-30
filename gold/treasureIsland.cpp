// #2589
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>

#define MAX 50

using namespace std;

int n, m, result = -1;
int board[MAX][MAX]; // bfs
int visit[MAX][MAX]; // bfs - visit
int land[MAX][MAX]; //dfs

queue<pair<int, int>> finalPoints;
queue<pair<int, int>> startPoints;
queue<pair<int, int>> checkPoints;

struct Node
{
	int x, y, z;
	Node(int x_point, int y_point, int move)
	{
		x = x_point;
		y = y_point;
		z = move;
	}
};

void dfs(int x, int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m || !land[x][y]) return;
	land[x][y] = 0;
	dfs(x+1, y);dfs(x-1,y);dfs(x,y+1);dfs(x,y-1);
}

void bfs(int x, int y, bool isfinal)
{
	queue<Node> Que;
	Que.push(Node(x, y, 0));

	int dx, dy, move;
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

	while(!Que.empty())
	{
		x = Que.front().x;
		y = Que.front().y;
		move = Que.front().z;

		visit[x][y] = 1;
		Que.pop();
		result = max(move, result);

		for(int i = 0; i < 4; i++)
		{
			dx = x + dxdy[i][0];
			dy = y + dxdy[i][1];

			if(dx < 0 || dy < 0 || dx >= n || dy >= m || !board[dx][dy] || visit[dx][dy]) continue;
			else
				Que.push(Node(dx, dy, move+1));	
		}

	}
	if(!isfinal)finalPoints.push(make_pair(x,y));
}

int main()
{
	cin >> n >> m;
	string input;
	for(int i = 0; i < n; i++)
	{
		cin >> input;
		for(int j = 0 ; j < m ; j++)
		{
			if(input[j] == 'W'){
				land[i][j] = 0;
				board[i][j] = 0;
			}
			else{
				land[i][j] = 1;
				board[i][j] = 1;
				startPoints.push(make_pair(i, j));
			} 
		}
	}

	int x, y;

	while(!startPoints.empty())
	{
		x = startPoints.front().first;
		y = startPoints.front().second;
		startPoints.pop();
		if(land[x][y] == 1){
			dfs(x,y);
			checkPoints.push(make_pair(x,y));
		}
	}

	while(!checkPoints.empty())
	{
		x = checkPoints.front().first;
		y = checkPoints.front().second;
		checkPoints.pop();

		bfs(x, y, false);
		memset(visit, 0, sizeof(visit));
	}

	while(!finalPoints.empty())
	{
		x = finalPoints.front().first;
		y = finalPoints.front().second;
		finalPoints.pop();

		bfs(x, y, true);
		memset(visit, 0, sizeof(visit));
	}

	cout << result << endl;
	return 0;
}