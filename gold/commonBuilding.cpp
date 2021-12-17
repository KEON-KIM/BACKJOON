// #6593
#include<iostream>
#include<queue>
#include<cstring>
#define MAX 31

using namespace std;
char board[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];

int L, R, C;
void INIT()
{	
	for(int i = 0; i < MAX; i ++)
		for(int j = 0; j < MAX; j++)
			for(int k = 0; k < MAX; k++)
				board[i][j][k] = '#';
}

void print()
{
	for(int i = 0; i < C; i++)
	{
		for(int j = 0; j < L; j++)
		{
			for(int k = 0; k < R; k++)
			{
				cout << board[i][j][k] << " ";
			}
			cout << endl;
		}
		for(int j = 0; j < L; j++)
			cout << "-";
		cout << endl;
	}
	cout << "THE END" << endl;
}

struct Common
{
	int first_idx;
	int second_x;
	int second_y;
	int value;
	Common(int idx, int x, int y, int v)
	{
		first_idx = idx;
		second_x = x;
		second_y = y;
		value = v;
	}
};

int bfs(int idx, int x, int y)
{
	queue<Common> Que; // 
	Que.push( Common(idx,x,y,0));

	int first_idx, second_x, second_y, value; 
	while(!Que.empty())
	{
		first_idx = Que.front().first_idx;
		second_x = Que.front().second_x;
		second_y = Que.front().second_y;
		value = Que.front().value;
		Que.pop();

		if(board[first_idx][second_x][second_y] == 'E') return value;

		if(second_x >= L || second_y >= R || first_idx >= C || first_idx < 0 || second_y < 0 || second_x < 0 
			|| board[first_idx][second_x][second_y] == '#' || visited[first_idx][second_x][second_y]) continue;
		Que.push(Common(first_idx+1, second_x, second_y, value+1));
		Que.push(Common(first_idx-1, second_x, second_y, value+1));
		Que.push(Common(first_idx, second_x+1, second_y, value+1));
		Que.push(Common(first_idx, second_x-1, second_y, value+1));
		Que.push(Common(first_idx, second_x, second_y+1, value+1));
		Que.push(Common(first_idx, second_x, second_y-1, value+1));
		visited[first_idx][second_x][second_y] = 1;
	}

	return 0;
}

int main()
{	
	L = 1, R = 1, C = 1;
	int idx, x, y;
	while(true)
	{
		int cnt;
		cin >> C >> L >> R;
		if(!(L*C*R)) break;
		for(int i = 0; i < C; i++)
			for(int j = 0; j < L; j++)
				for(int k = 0; k < R; k++){
					cin >> board[i][j][k];
					if(board[i][j][k] == 'S') {
						idx = i;
						x = j;
						y = k;
					}
				}
		cnt = bfs(idx, x, y);
		if(cnt)
			cout << "Escaped in "<<cnt<< " minute(s)." << endl;
		else 
			cout << "Trapped!" << endl;
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}