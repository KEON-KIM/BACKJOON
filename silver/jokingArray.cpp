#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> board;
vector<vector<int>> INIT(int r, int c)
{
	vector<vector<int>> res;
	vector<int> tmp(c, 0);
	for(int i = 0; i < r; i++)
		res.push_back(tmp);

	return res;
}

void print(vector<vector<int>> mat)
{
	for(vector<int> v : mat){
		for(int i : v)
			cout << i << " ";
		cout << endl;
	}
}

int solution(int r, int c)
{
	int answer = 1;
	int top = 0, bottom = r-1;
	int left = 0, right = c-1;

	board = INIT(r, c);
	while(answer <= r*c)
	{
		for(int i = top; i <= bottom; i++)
		{
			if(i == top)
			{
				for(int j = right; j >= left; j--)
					board[i][j] = answer++;
			}
			else if(i == bottom)
			{
				for(int j = left; j <= right; j++)
					board[i][j] = answer++;
			}
			else
				board[i][left] = answer++;
		}
		top++;bottom--;left++;
		for(int i = bottom; i >= top; i--)
		{
			if(i == bottom)
			{
				for(int j = right; j >= left; j--)
					board[i][j] = answer++;
			}
			else if(i == top)
			{
				for(int j = left; j <= right; j++)
					board[i][j] = answer++;
			}
			else
				board[i][left] = answer++;
		}
		top++;bottom--;left++;;

		// cout << top << " " << bottom << " " << left << " " << right << " "<< answer <<  endl;
	}

	print(board);

	return answer;
}
int main()
{
	solution(8,8);
	return 0;
}
