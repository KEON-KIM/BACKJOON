#include <iostream>
#include <vector>
#include <cstring>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef pair<int, int> pii;

int zeroCnt = 0;
int board[9][9];
vector<pii> zeroBase;
void Print()
{
	FOR(i, 9) 
	{
		FOR(j, 9) cout << board[i][j];
		cout << endl;
	}
}

bool dia(int x, int y, int val)
{
	int regular_x = 3 * (x / 3);
	int regular_y = 3 * (y / 3);
	for(int i = regular_x; i < regular_x + 3; i++)
	{
		for(int j = regular_y; j < regular_y + 3; j++)
		{
			// if(i == x && i == y) continue;
			if(board[i][j] == val) return false;
		}
	}

	FOR(i, 9) if((i != y && board[x][i] == val) ||
				 (i != x && board[i][y] == val)) return false;

	return true;
}

bool dfs(int cur)
{
	if(cur == zeroCnt) return true;
	int x = zeroBase[cur].first;
	int y = zeroBase[cur].second;

	if(!board[x][y]){
		for(int k = 1; k <= 9; k++)
		{
			if(dia(x, y, k))
			{
				board[x][y] = k;
				if(dfs(cur+1)) return true;
				
			}
		}
		board[x][y] = 0;
	}
		
	return false;
}

int main()
{
	string input;
	FOR(i, 9)
	{
		cin >> input;
		FOR(j, 9)
		{
			if(!(input[j] - '0')){
				zeroBase.push_back({i, j});
				zeroCnt++;
			}
			board[i][j] = input[j] - '0';
		}
	}

	if(dfs(0))
		Print();
			
	return 0;
}