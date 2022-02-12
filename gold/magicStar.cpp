#include<iostream>
#include<cstring>
#include<vector>

#define MAX 12
#define ALPHA 77
#define endl '\n'
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

bool visited[ALPHA];
bool flag = false;
vector<int> board;
vector<int> origin;
string draw[6] = { "....x....",
					".x.x.x.x.",
					"..x...x..",
					".x.x.x.x.",
					"....x...."}; 

bool isTrue()
{
	int cmp  = (board[1] + board[2] + board[3] + board[4]);
	if (cmp != board[0] + board[2] + board[5] + board[7] || 
		cmp != board[0] + board[3] + board[6] + board[10] ||
		cmp != board[7] + board[8] + board[9] + board[10] ||
		cmp != board[1] + board[5] + board[8] + board[11] ||
		cmp != board[4] + board[6] + board[9] + board[11]) return false;
	
	return true;
}

void print()
{
	int idx = 0;
	FOR(i, 5)
	{
		FOR(j, 9)
		{
			if(draw[i][j] == 'x')
			{
				cout << char(board[idx]);
				idx++;
				continue;
			}
			cout << draw[i][j];
		}
		cout << endl;
	}
}

void dfs(int index)
{
	if(index >= MAX)
	{
		if(isTrue())
			flag = true;
		return;
	}

	if(board[index] != 120){
		dfs(index+1);
	}
	for(int i = 65; i < 77; i++)
	{
		if(!visited[i])
		{
			board[index] = i;
			visited[i] = true;
			dfs(index+1);
			if(flag) return;
			visited[i] = false;
			board[index] = origin[index];
		}
	}
}	

int main()
{
	int a = 0, b = 0;
	string input;

	FOR(i, 5)
	{
		cin >> input;
		FOR(j, 9)
			if(input[j] != '.'){
				if(input[j] < 120) 
					visited[input[j]] = true;
				board.push_back(input[j]);
				origin.push_back(input[j]);
			}
	}

	FOR(i, MAX)
	{
		if(board[i] == 120){
			for(int j = ALPHA-12; j < ALPHA; j++)
			{
				if(!visited[j]){
					visited[j] = true;
					board[i] = j;
					dfs(i+1);
					if(flag) {
						print();
						return 0;
					}
					visited[j] = false;
					board[i] = origin[i];
				}
			}
		}
	}

	return 0;
}