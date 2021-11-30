//#17070
#include<iostream>
#include<queue>

#define MAX 17
using namespace std;

int n, result;
int board[MAX][MAX];

struct Node
{
	int x, y, dir;
	Node(int x_pos, int y_pos, int direction)
	{
		x = x_pos;
		y = y_pos;
		dir = direction;
	}
};

void bfs()
{
	queue<Node> Que;
	Que.push(Node(0,1,0));

	int cur_x, cur_y, cur_dir;
	while(!Que.empty())
	{
		cur_x = Que.front().x;
		cur_y = Que.front().y;
		cur_dir = Que.front().dir;
		Que.pop();

		if(cur_x < 0 || cur_y < 0|| cur_x >= n || cur_y >= n || board[cur_x][cur_y]) continue;
		if(cur_x == n-1 && cur_y == n-1) result++;
		else
		{
			if(cur_dir == 0)
			{
				Que.push(Node(cur_x, cur_y+1, 0));
				if((cur_x+1 < n && cur_y+1 < n) && !board[cur_x+1][cur_y] && !board[cur_x][cur_y+1])
					Que.push(Node(cur_x+1, cur_y+1, 2));
			}
			else if(cur_dir == 1)
			{
				Que.push(Node(cur_x+1, cur_y, 1));
				if((cur_x+1 < n && cur_y+1 < n) && !board[cur_x+1][cur_y] && !board[cur_x][cur_y+1])
					Que.push(Node(cur_x+1, cur_y+1, 2));
			}
			else
			{
				Que.push(Node(cur_x+1, cur_y, 1));
				Que.push(Node(cur_x, cur_y+1, 0));
				if((cur_x+1 < n && cur_y+1 < n) && !board[cur_x+1][cur_y] && !board[cur_x][cur_y+1])
					Que.push(Node(cur_x+1, cur_y+1, 2));
			}
		}
	}

}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> board[i][j];

	bfs();
	cout << result << endl;
	return 0;
}