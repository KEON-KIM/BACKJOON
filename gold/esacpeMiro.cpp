#include <iostream>
#include <cstring>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;

int board[8][8];
bool visited[8][8];
int dxdy[9][2] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, 
					{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
queue<pii> playerQue;
queue<pii> wallQue;
void print()
{
	FOR(i, 8)
	{
		FOR(j, 8)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	string input;
	playerQue.push({7, 0}); // left bottom
	FOR(i, 8)
	{
		cin >> input;
		FOR(j, 8){
			board[i][j] = input[j];
			if(input[j] == '#')
				wallQue.push({i, j});
		}
	}
	while(!playerQue.empty())
	{
		int pSize = playerQue.size();
		FOR(i, pSize)
		{
			int x = playerQue.front().first;
			int y = playerQue.front().second;
			playerQue.pop();
			// cout << x << " / " << y << endl;
			if(board[x][y] == '#') continue;
			FOR(j, 9)
			{
				int dx = x + dxdy[j][0];
				int dy = y + dxdy[j][1];

				if(wallQue.empty() || dx == 0 && dy == 7)
				{
					cout << "1" << endl;
					return 0;
				}
				if(dx < 0 || dy < 0 || dx >= 8 || dy >= 8) continue;
				if(board[dx][dy] == '#') continue;
				playerQue.push({dx, dy});
			}
		}
		int wSize = wallQue.size();
		memset(board, 0, sizeof(board));
		FOR(i, wSize)
		{
			int dx = wallQue.front().first + 1;
			int y = wallQue.front().second;
			wallQue.pop();

			if(dx >= 8) continue;
			wallQue.push({dx, y});
			board[dx][y] = '#';
		}

		// print();
		// cout << "================" << endl;
	}
	cout << "0" << endl;
	return 0;
}