#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

vector<string> board;
int N;

void rotate(int index, int rotation)
{
	char origin_right = board[index-1][2];
	char origin_left = board[index-1][6];
	cout << "ROTATE : " << index << "/ L : " << origin_left  << " / R : " << origin_right << endl;

	if(rotation == -1)
	{
		char start = board[index-1][0];
		// char start = tmp[0];
		
		board[index-1] += start;
		board[index-1].erase(board[index-1].begin());

		cout << board[index-1] << endl;
	}
	else
	{
		char end = board[index-1][board[index-1].size()-1];
		// char end = tmp[tmp.size()-1];
		cout << "CHAR : " << end << endl;
		board[index-1].erase(board[index-1].end()-1);
		board[index-1].insert(board[index-1].begin(), end);

		cout << board[index-1] << endl;
	}

	if(index - 2 >= 0)
		if(origin_left != board[index-2][2]) {
			cout << "INDEX : " << index << "/ " << index-1 << endl;
			cout << origin_left << " / " << board[index-2][2] <<endl;
			rotate(index-1, rotation * -1);
		}

	if(index < 4)
		if( origin_right != board[index][6]) {
			cout << "INDEX : " << index << "/ "<< index+1 << endl;
			cout << origin_right << " / " << board[index][6] <<endl;
			rotate(index+1, rotation * -1);
		}
	
	
	
}

int main()
{
	string input;
	int result = 0;
	for(int i = 0; i < 4; i++)
	{
		cin >> input;
		board.push_back(input);
	}

	cin >> N;
	int a, b;
	for(int i = 0; i < N; i++)
	{
		cin >> a >> b;
		rotate(a,b);
	}
	cout << "=====result ==========" << endl;

	for(int i = 0; i < 4; i++)
	{
		cout << board[i] << endl;
		if(board[i][0] == '1')
			result += pow(2,i);
		
	}

	cout << result << endl;
	return 0;
}