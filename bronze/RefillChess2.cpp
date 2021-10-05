#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
void printint(vector<vector<int>> v)
{
	for(vector<int> temp : v)
	{
		cout << "|";
		for(int k : temp)			
			cout << k << "|";
		cout << endl;
	}
	cout << endl;
}
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
		string row(m, ' ');
		for(int j = 0; j < m; j++)
			cin >> row[j];	
		board.push_back(row);
	}
	return board;
}

int solution(vector<vector<int>> score, int width, int height)
{
	int answer = 0;

	for(int i = height; i < height + 8; i++)
	{
		for(int j = width; j < width + 8; j++)
			answer += score[i][j];
		
	}
	
	return answer;
}
int Scoreboard(vector<string> board)
{
	string black = "B";
	string white = "W";
	vector<int> Rank;
	vector<string> Wvector;
	vector<string> Bvector;
	vector<vector<int>> WScore(board.size());
	vector<vector<int>> BScore(board.size());

	for(int i = 0 ; i < board[0].size()-1; i++)
	{
		if(black[black.size()-1] == 'B')
			black.push_back('W');
		else
			black.push_back('B');

		if(white[white.size()-1] == 'W')
			white.push_back('B');
		else
			white.push_back('W');
	}

	for(int i = 0 ; i < board.size(); i++)
	{
		if(i%2 == 0)
		{
			Wvector.push_back(white);
			Bvector.push_back(black);
		}

		else
		{
			Wvector.push_back(black);
			Bvector.push_back(white);
		}
	}

	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j] == Wvector[i][j])
				WScore[i].push_back(0);
			else
				WScore[i].push_back(1);
			if(board[i][j] == Bvector[i][j])
				BScore[i].push_back(0);
			else
				BScore[i].push_back(1);
		}
	}


	for(int i = 0; i < board.size() - 7; i++)
	{
		for(int j = 0; j < board[i].size() - 7; j++)
		{
			Rank.push_back(solution(WScore, j, i));
			Rank.push_back(solution(BScore, j, i));
		}
	}

	sort(Rank.begin(), Rank.end(), greater<int>());

	return Rank[Rank.size()-1];
}



int main()
{
	int a, b;
	vector<string> board;
	vector<int> answer;
	cin >> a >> b;

	board = init(a,b);

	cout << Scoreboard(board) << endl;
	// cout << answer[answer.size()-1];
	
	return 0;
}