#include <iostream>
#include <vector>

#define MAX 32
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;

ll board[MAX][MAX];

void solution(int n, int m, vector<vector<int>> fires, vector<vector<int>> ices)
{
	for(vector<int> fire : fires)
	{
		FOR(cur_x, n)
		{
			FOR(cur_y, n)
			{
				int val = m - max(abs(fire[0] - cur_x), abs(fire[1] - cur_y)) + 1;
				// cout << cur_x << "/" << cur_y << " : " << val << endl;
				if(val > 0) board[cur_x][cur_y] += val;
			}
		}
		board[fire[0]][fire[1]]--;
	}

	for(vector<int> ice : ices)
	{
		FOR(cur_x, n)
		{
			FOR(cur_y, n)
			{
				int val = m - (abs(ice[0] - cur_x) + abs(ice[1] - cur_y) - 1);
				if(val > 0) board[cur_x][cur_y] -= val;
			}
		}
		board[ice[0]][ice[1]]++;
	}

	FOR(i, n)
	{
		FOR(j, n)
		{
			cout << board[i][j] << ' ';
		}cout << endl;
	}
}
int main()
{
	vector<vector<int>> fires 
							// = {{1, 1}};
							= {{5, 5}, {1, 3}, {5, 2}};
	vector<vector<int>> ices 
							// = {{3, 3}};
							= {{1, 5}, {3, 2}};

	solution(5, 3, fires, ices);	
	return 0;
}