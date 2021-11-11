//FUCKING MEMORY!

#include<iostream>
#include<vector>
#define endl '\n'

using namespace std;

int N;

vector<int> hap(vector<int> a, vector<int> b)
{
	for(int tmp : b)
		a.push_back(tmp);

	return a;
}

vector<int> merge(vector<int> board)
{
	vector<int> left;
	vector<int> right;

	int pivot = board.size()/2;
	if(board.size() > 2)
	{
		for(int i = 0; i < board.size(); i++)
		{
			if(board[pivot] < board[i])
				right.push_back(board[i]); 
			else if (board[pivot] > board[i])
				left.push_back(board[i]); 
		}
		left.push_back(board[pivot]); 

		return hap(merge(left), merge(right));
	}

	else
	{
		if(board.size() == 2)
		{
			if(board[0] > board[1])
			{
				char tmp = board[0];
				board[0] = board[1];
				board[1] = tmp;
			}
		}
		
		return board;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	vector<int> board;
	vector<int> answer;
	cin >> N;
	int input;
	for(int i = 0; i < N; i++){
		cin >> input;
		board.push_back(input);
	}
	
	answer = merge(board);

	for(int tmp : answer)
		cout << tmp << endl;

	return 0;
}