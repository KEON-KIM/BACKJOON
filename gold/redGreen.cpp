// #10026
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int N, normal = 0, redgreen = 0;
char board[100][100], board2[100][100];

void print()
{
	for(int i = 0; i<N; i++){
		for(int j = 0; j < N ; j++)
			cout << board2[i][j] << " ";
		cout << endl;
	}

}
void bfs(int x, int y)
{
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	char check = board[x][y];
	queue<pair<int, int>> Que;
	Que.push(make_pair(x,y));
	
	while(!Que.empty())
	{
		x = Que.front().first;
		y = Que.front().second;
		Que.pop();
		if(x > N || x < 0 || y > N || y < 0) continue;
		if(board[x][y] == check){
			board[x][y] = '0';
			for(int i = 0; i < 4; i++)
				Que.push(make_pair(x + dxdy[i][0], y + dxdy[i][1]));
		}
	}
}

void non_bfs(int x, int y)
{
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	char check = board2[x][y];
	queue<pair<int, int>> Que;
	Que.push(make_pair(x,y));
	
	while(!Que.empty())
	{
		x = Que.front().first;
		y = Que.front().second;
		Que.pop();
		if(x > N || x < 0 || y > N || y < 0) continue;
		if(board2[x][y] == check || (board2[x][y] == 'G' && check =='R') || (board2[x][y] == 'R' && check =='G')){
			board2[x][y] = '0';
			for(int i = 0; i < 4; i++)
				Que.push(make_pair(x + dxdy[i][0], y + dxdy[i][1]));
		}
	}
}

int main()
{
	cin >> N;
	string str;
	for(int i = 0; i < N ; i++)
	{
		cin >> str;
		for(int j = 0; j < N; j++)
			board[i][j] = str[j];
	}
	memcpy(board2, board, sizeof(board));

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(board[i][j] != '0'){
				normal++;
				bfs(i,j);
			}
			if(board2[i][j] != '0')
			{
				redgreen++;
				non_bfs(i,j);
			}
		}
	}

	cout << normal << " " << redgreen << endl;
	return 0;
}