// #2589
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 50

using namespace std;

int n, m, result = -1;
int board[MAX][MAX]; // bfs
int visited[MAX][MAX];

vector<pair<int, int>> startPoints;

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

int** MAKE_VISIT()
{
	int** rows = new int*[n];
	for(int i = 0; i < n; i++)
		rows[i] = new int[m];

	return rows;
}

void print(int** tmp)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << tmp[i][j] << " ";
		cout << endl;
	}
}

void bfs(int x, int y)
{
	queue<Node> Que;
	Que.push(Node(x, y, 0));

	// int** visited = MAKE_VISIT();
	// int visited[MAX][MAX];
	int dx, dy, move;
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

	while(!Que.empty())
	{
		x = Que.front().x;
		y = Que.front().y;
		move = Que.front().z;

		visited[x][y] = 1;
		Que.pop();

		for(int i = 0; i < 4; i++)
		{
			dx = x + dxdy[i][0];
			dy = y + dxdy[i][1];

			if(dx < 0 || dy < 0 || dx >= n || dy >= m || !board[dx][dy] || visited[dx][dy]) continue;
			else
				Que.push(Node(dx, dy, move+1));	
		}

		result = max(move, result);
	}
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
			if(input[j] == 'W')
				board[i][j] = 0;
			
			else{
				board[i][j] = 1;
				startPoints.push_back(make_pair(i, j));
			} 
		}
	}

	for(int i = 0; i < startPoints.size(); i++){
		bfs(startPoints[i].first, startPoints[i].second);
		memset(visited, 0,sizeof(visited));
	}
	cout << result << endl;

	return 0;
}