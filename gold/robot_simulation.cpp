//# 2174
#include<iostream>
#include<vector>
#define MAX 101

using namespace std;

struct robot_info
{
	int x;
	int y;
	int direction;
	int move_info;
	robot_info(int a, int b, int dir, int move)
	{
		x = a;
		y = b;
		direction = dir;
		move_info = move;
	}
};
bool isOK = false;
int A, B, N, M, board[MAX][MAX];
vector<robot_info> robot;
void print()
{
	for(int i = 1; i <= B; i++)
	{
		for(int j = 1; j <= A; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

void dfs(int index, char cmd, int n)
{
	int dxdy[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	// int dxdy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	// char dir[4] = {'S', 'E', 'N', 'W'};

	int x = robot[index].x;
	int y = robot[index].y;
	int dir = robot[index].direction;
	int cnt = robot[index].move_info;

	if(n <= 0) 
		return;
	
	if(cmd == 'L'){
		robot[index] = robot_info(x, y, (dir+1)%4, cnt+1);
		dfs(index, cmd, n-1);
	}	
	else if (cmd == 'R'){
		dir = dir-1 < 0 ? 3 : dir-1;
		robot[index] = robot_info(x, y, dir, cnt+1);
		dfs(index, cmd, n-1);
	}
	else
	{
		board[x][y] = 0;
		int dx = x + dxdy[dir][0];
		int dy = y + dxdy[dir][1];
		// cout << dx <<"/"<< dy << endl;
		
		if(board[dx][dy]) {
			isOK = true;
			cout << "Robot "<< index+1 <<" crashes into robot " << board[dx][dy] << endl;
			return;
		}
		if(dx < 1 || dy < 1 || dx > B || dy > A) {
			isOK = true;
			cout << "Robot " << index+1 << " crashes into the wall" << endl;
			return;
		}
		board[dx][dy] = index+1;
		robot[index] = robot_info(dx, dy, dir, cnt+1);
		dfs(index, cmd, n-1);
	}

}

int main()
{
	cin >> A >> B;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		int a, b; char dir;
		cin >> a >> b >> dir;
		switch(dir)
		{
			case 'S' : 
				robot.push_back(robot_info(b, a, 0, 0));
				break;
			case 'N' : 
				robot.push_back(robot_info(b, a, 2, 0));
				break;
			case 'E' : 
				robot.push_back(robot_info(b, a, 1, 0));
				break;
			case 'W' : 
				robot.push_back(robot_info(b, a, 3, 0));
				break;
		}
		board[b][a] = i+1;
	}
	for(int i = 0; i < M; i++)
	{
		int index, num; char dir;
		cin >> index >> dir >> num;
		if(!isOK)
			dfs(index-1, dir, num);
		else
			break;
	}
	if(!isOK) cout << "OK" << endl; 


	return 0;
}