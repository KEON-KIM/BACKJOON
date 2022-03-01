#include <iostream>
#include <cstring>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T = 0;
char board[1001][3][3];
pair<int, int> Info[1001];

//'X', 'O'

void print()
{
	FOR(t, T)
	{
		cout << "======== INDEX : " << t << " ========" << endl;
		FOR(i, 3)
		{
			FOR(j, 3)
				cout << board[t][i][j] << " ";
			cout << endl;
		}
	}
}
bool dia(int idx, char chk)
{
	int cnt;
	// 'X'
	FOR(t, 3)
	{
		cnt = 0;
		FOR(i, 3)
		{
			if(board[idx][t][i] == chk)
				cnt++;
		}
		if(cnt == 3)
			return true;
		
		cnt = 0;
		FOR(i, 3)
		{
			if(board[idx][i][t] == chk)
				cnt++;
		}
		if(cnt == 3)
			return true;
		cnt = 0;
		FOR(i, 3)
		{
			if(board[idx][i][i] == chk)
				cnt++;
		}
		if(cnt == 3)
			return true;

		cnt = 0;
		FOR(i, 3)
		{
			if(board[idx][i][2-i] == chk)
				cnt++;
		}
		if(cnt == 3)
			return true;
	}

	return false;
	
}
void Solution()
{
	FOR(i, T)
	{
		int x = Info[i].first;
		int o = Info[i].second;
		if(x + o == 9)
		{
			if(dia(i, 'X') && !dia(i, 'O') && x-1 == o){
				cout << "valid" << endl;
				continue;
			}
			else if(dia(i, 'O') && x == o)
			{
				cout << "valid" << endl;
				continue;
			}
			else if(x - 1 == o && !dia(i, 'O') && !dia(i, 'X'))
			{
				cout << "valid" << endl;
				continue;
			}
		}
		
		else
		{ //  9 - (x + o)
			// int tmp = 9 - (Info[i].first + Info[i].second);
			// if(Info[i].first == Info[i].second || Info[i].first - 1 == Info[i].second)
			// {
			if(dia(i, 'X') && !dia(i, 'O') && x-1 == o){
				cout << "valid" << endl;
				continue;
			}
			else if(dia(i, 'O') && x == o)
			{
				cout << "valid" << endl;
				continue;
			}
		}

		cout << "invalid" << endl;
	}
}
int main()
{
	string input;
	while(true)
	{
		int x = 0;
		int o = 0;
		int idx = 0;
		cin >> input;

		if(input == "end") break;
		FOR(i, 3)
		{
			FOR(j, 3)
			{
				board[T][i][j] = input[idx];
				if(board[T][i][j] == 'X') x++;
				else if(board[T][i][j] == 'O') o++;
				idx++;
			}
		}Info[T] = make_pair(x, o);
		T++;
	}
	// print();
	Solution();
	return 0;
}
