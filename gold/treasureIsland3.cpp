// #2589
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 50

using namespace std;

int n, m, result = -1;
int board[MAX][MAX]; // bfs
int cost[MAX][MAX];

vector<pair<int, int>> startPoints;

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
	queue<pair<int, int>> Que;
	Que.push(make_pair(x, y));

	int dx, dy, move;
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	cost[x][y] = 1;
	while(!Que.empty())
	{
		x = Que.front().first;
		y = Que.front().second;

		Que.pop();

		for(int i = 0; i < 4; i++)
		{
			dx = x + dxdy[i][0];
			dy = y + dxdy[i][1];

			if(dx < 0 || dy < 0 || dx >= n || dy >= m || !board[dx][dy]) continue;
			else if(cost[dx][dy] == 0){
					Que.push(make_pair(dx, dy));	
					cost[dx][dy] = cost[x][y] + 1;
					result = max(cost[dx][dy], result);
			}
				
		}
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
		memset(cost, 0,sizeof(cost));
	}
	cout << result - 1 << endl;

	return 0;
}