// #3190
#include<iostream>
#include<queue>

#define MAX 102

using namespace std;

int MAP[MAX][MAX], N, M, C;
int curTime = 0;
int char_dir = 0, eatItem = 1;
queue<pair<int, char>> command;
queue<pair<int, int>> body;

void dfs(int x, int y)
{
	if(MAP[x][y] == 2) eatItem++;
	if(body.size() > eatItem){
		MAP[body.front().first][body.front().second] = 0;
		body.pop();
	}
	if(x > N || y > N || y < 1 || x < 1) return;
	if(MAP[x][y] == 1) return;
	if(curTime == command.front().first)
	{
		if(command.front().second == 'L')
			char_dir = char_dir < 1 ? 3 : char_dir-1;
		
		else
			char_dir = char_dir > 2 ? 0 : char_dir+1;
		command.pop();
	}
	curTime++;
	MAP[x][y] = 1;
	body.push(make_pair(x,y));
	if(!char_dir) dfs(x,y+1);
	else if (char_dir == 1) dfs(x+1, y);
	else if (char_dir == 2) dfs(x,y-1);
	else if (char_dir == 3) dfs(x-1, y);
	
}
int main()
{
	cin >> N;
	cin >> M;
	int x,y;
	for(int i = 0; i < M; i++){
		cin >> x >> y;
		MAP[x][y] = 2;
	}
	cin >> C;
	char rotate;
	for(int i = 0; i < C; i++)
	{
		cin >> x >> rotate;
		command.push(make_pair(x, rotate));
	}

	body.push(make_pair(1,1));
	dfs(1, 1);

	cout<< curTime << endl;
	return 0;
}