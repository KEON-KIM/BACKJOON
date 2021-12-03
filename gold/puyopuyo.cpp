#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<string> board;

int arr[6], visited[12][6], judge[12][6], result = 0;
void print()
{
	for(string str : board){
		for(char tmp : str )
			cout << tmp << " ";
	cout << endl;
	}
}
void printArr()
{
	for(int i = 0; i < 6; i++)
		cout << arr[i] << ' ';
	cout << endl;
}


void Update(int x, int y)
{
	printArr();
	int start;
	for(int i = 0; i < 6; i++){
		if(arr[i] != 0)
		{
			for(int j = x; j > 0; j--)
			{
				start = j+arr[i];
				if(start > 0){
					board[j][i] = board[start][i];
					judge[j][i] = board[j][i] != '.' ? 1 : 0;
				}
				else {
					board[j][i] = '.';
					judge[j][i] = 0;
				}
			}
		}
	}

}
int bfs(int x, int y)
{
	char ch = board[x][y];
	queue<pair<int, int>> Que;
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
		arr[dy] = dx > x? arr[dy] + 1 : arr[dy] - 1;
		cnt++;
		
		Que.push(make_pair(dx+1, dy));
		Que.push(make_pair(dx, dy+1));
		Que.push(make_pair(dx-1, dy));
		Que.push(make_pair(dx, dy-1));
	}
	
	memset(visited, 0, sizeof(visited));
	return cnt;
}

int Play()
{
	int cnt;

	for(int i = 11; i > 0; i--)
	{
		for(int j = 0; j < 6; j++)
		{
			if(judge[i][j])
			{
				if(bfs(i, j) >= 4)
				{
					Update(i, j);
					cnt++;
					result++;
				}
				memset(arr, 0, sizeof(arr));
			}
		}
	}


	return cnt;
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

	while(!cnt)
		cnt = Play();
	

	print();

	cout << result << endl;

	return 0;
}