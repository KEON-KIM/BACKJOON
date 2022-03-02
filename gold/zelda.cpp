//#4485
#include <iostream>
#include <cstring>
#include <queue>

#define MAX 126
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int board[MAX][MAX];
int cache[MAX][MAX];

void print()
{
	FOR(i, N)
	{
		FOR(j, N)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
void Dijikstra(int x, int y)
{
	priority_queue<pair<int, int>> pQue;// <cost, <x, y>> 
	pQue.push({0, 0});
	cache[0][0] = board[0][0];

	while(!pQue.empty())
	{
		int x = pQue.top().first;
		int y = pQue.top().second;
		pQue.pop();

		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];
			if(dx < 0 || dy < 0 || dx >= N || dy >= N) continue;

			if(cache[dx][dy] > cache[x][y] + board[dx][dy]){
				cache[dx][dy] = cache[x][y] + board[dx][dy];
				pQue.push({dx, dy});
			}
		}
	}
}
int main()
{
	int idx = 1;
	while(true)
	{
		memset(cache, 0x3f, sizeof(cache));
		cin >> N;
		if(!N) break;
		FOR(i, N)
			FOR(j, N)
				cin >> board[i][j];

		Dijikstra(0, 0);
		cout << "Problem "<< idx << ": "<< cache[N-1][N-1] << endl;
		idx ++;

	}
	return 0;
}