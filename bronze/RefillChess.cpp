#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


void printmat(vector<string> v)
{
	for(string str : v)
		cout << str << endl;
}

vector<string> init(int n, int m)
{
	vector<string> board;
	for(int i = 0; i < n; i++)
	{
		string row(m,' ');
		for(int j = 0; j < m; j++)
		{
			cin >> row[j];	
		}
		board.push_back(row);
	}
	return board;
}

int solution(vector<string> board, int width, int height, bool flag)
{
	int answer = 0;

	
	if(flag)
	{
		char rowCache = ' ';
		for(int i = height; i < height + 8; i++)
		{
			if(rowCache == board[i][0]){
				answer++;
				if(board[i][0] == 'W') board[i][0] = 'B';
				else board[i][0] = 'W';
				rowCache = board[i][0];
			}
			char cache = ' ';
			for(int j = width; j < width + 8; j++)
			{
				if(cache == board[i][j]){
					answer++;
					if(board[i][j] == 'W') board[i][j] = 'B';
					else board[i][j] = 'W';
					// rowCache = board[i][j];
				}
				cache = board[i][j];
			}
		}
	}
	else
	{
		char rowCache = ' ';
		for(int i = height; i < height + 8; i++)
		{
			reverse(board[i].begin(), board[i].end());
			if(rowCache == board[i][0]){
				answer++;
				if(board[i][0] == 'W') board[i][0] = 'B';
				else board[i][0] = 'W';
				rowCache = board[i][0];
			}
			char cache = ' ';
			for(int j = width; j < width + 8; j++)
			{
				if(cache == board[i][j]){
					answer++;
					if(board[i][j] == 'W') board[i][j] = 'B';
					else board[i][j] = 'W';
					// rowCache = board[i][j];
				}
				cache = board[i][j];
			}
		}
	}
	
	
	
	return answer;
}

int main()
{
	int a, b;
	vector<string> board;
	vector<int> answer;
	cin >> a >> b;

	board = init(a,b);
	for(int i = 0; i < board.size() - 7; i++)
	{
		for(int j = 0; j < board[i].size() - 7; j++){
			answer.push_back(solution(board, j, i, true));
			answer.push_back(solution(board, j, i, false));
		}
	}
	sort(answer.begin(), answer.end(), greater<int>());
	for(int temp : answer)
		cout <<temp << endl;
	// cout << answer[answer.size()-1];
	
	return 0;
}