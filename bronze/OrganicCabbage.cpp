#include<vector>
#include<string>
#include<iostream>
#include<stack>

using namespace std;


void FindField(vector<vector<int>> &board, int x, int y)
{
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};
	stack<pair<int, int>> cache;
	cache.push(make_pair(x,y));

	while(!cache.empty()){
		x = cache.top().first;
		y = cache.top().second;
		cache.pop();
		board[y][x] = 0;

		for(int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if(next_x >= 0 && next_y >= 0 && next_y < board.size() && next_x < board[0].size())
			{
				if(board[next_y][next_x] == 1)
				{
					cache.push(make_pair(next_x,next_y));
				}
			}
		}
	}
		
	

}

int solution(vector<vector<int>> board)
{
	int count = 0;
 	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[0].size(); j++)
		{
			if(board[i][j] == 1)
			{
				FindField(board, j, i);
				count++;
			}
		}
	}
	return count;
}

vector<vector<int>> Init(int width, int height, int num)
{
	int x, y;
	vector<vector<int>> board;
	for(int i = 0; i < height; i++)
	{
		vector<int> col(width,0);
		board.push_back(col);
	}

	for(int i = 0; i < num; i++)
	{
		cin >> x >> y;
		board[y][x] = 1;
	}

	return board;
}

int main()
{

	int N, width, height, num;
	cin >> N;
	vector<vector<vector<int>>> boardSet;

	

	for(int i = 0; i < N; i++){
		cin >> width >> height >> num;
		vector<vector<int>> board = Init(width, height, num);
		boardSet.push_back(board);
	}

	for(int i = 0; i < N; i++)
		cout << solution(boardSet[i]) << endl;

	

	return 0;
}