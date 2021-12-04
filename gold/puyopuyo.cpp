// #11559
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<string> board;

int visited[12][6], judge[12][6], result = 0;
void print()
{
	for(string str : board){
		for(char tmp : str )
			cout << tmp << " ";
	cout << endl;
	}
}

int Update()
{
	bool isDel = false;
	for(int i = 0; i < 6; i++)
	{
		int cursor = 11;
		for(int j = 11; j >= 0; j--)
		{
			while(cursor > 0 && board[cursor][i] == 'X'){
				cursor= cursor - 1;
				isDel = true;
			}
			if(cursor >= 0){
				board[j][i] = board[cursor][i];
				judge[j][i] = judge[cursor][i];
			}
			else {
				board[j][i] = '.';
				judge[j][i] = 0;
			}
			cursor--;
		}
	}

	if(isDel) return 1;
	else return 0;
}

int bfs(int x, int y)
{
	char ch = board[x][y];
	queue<pair<int, int>> Que;
	queue<pair<int, int>> cache;

	Que.push(make_pair(x, y));

	int dx, dy;
	int cnt = 0;

	while(!Que.empty())
	{
		dx = Que.front().first;
		dy = Que.front().second;
		Que.pop();
		if(dx < 0 || dy < 0 || dx >= 12 || dy >= 6 || visited[dx][dy] || board[dx][dy] != ch || !judge[dx][dy]) continue;

		visited[dx][dy] = 1;
		cache.push(make_pair(dx,dy));

		Que.push(make_pair(dx+1, dy));
		Que.push(make_pair(dx, dy+1));
		Que.push(make_pair(dx-1, dy));
		Que.push(make_pair(dx, dy-1));
	}

	cnt = cache.size();
	if(cache.size() >= 4)
	{
		while(!cache.empty()){
			board[cache.front().first][cache.front().second] = 'X';
			cache.pop();
		}
	}

	return cnt;
}

int Play()
{

	for(int i = 11; i > 0; i--)
	{
		for(int j = 0; j < 6; j++)
		{
			if(judge[i][j])
			{
				bfs(i, j);
			}
		}
	}

	memset(visited, 0, sizeof(visited));
	if(Update()){
		result ++;
		return 1;
	} 
	else
		return 0;
}

int main()
{
	string input;

	for(int i = 0; i < 12; i++){
		cin >> input;
		for(int j = 0; j < input.size(); j++){
			if(input[j] != '.') judge[i][j] = 1;
			else judge[i][j] = 0;
		}
		board.push_back(input);
	}

	int cnt = 0;

	while(Play())
		continue;
	
	

	// print();

	cout << result << endl;

	return 0;
}