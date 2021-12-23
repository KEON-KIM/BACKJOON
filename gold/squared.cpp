// #1025 
// @Reference encrypted-def <https://github.com/encrypted-def/BOJ/blob/master/1025.cpp>
#include <cmath>
#include <iostream>

#define MAX 10
#define FOR(i, N) for(int i = 0; i < N; i++)

using namespace std;

int N, M, ans = -1;
char board[MAX][MAX];

bool isOutOfBounds(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}
bool isSquare(int x)
{
	int cmp = (int)sqrt(x);
	for(int i = cmp -2; i <= cmp +2; i++)
		if(i*i == x) return true;

	return false;
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> board[i];

	FOR(x, N) FOR(y, M)
		for(int dx = -N; dx < N; dx ++)
			for(int dy = -M; dy < M; dy++)
			{
				int value = 0;
				if(!dx && !dy) continue;
				int cur_X = x;
				int cur_Y = y;
				while(!isOutOfBounds(cur_X, cur_Y))
				{
					value = (10 * value) + (board[cur_X][cur_Y] - '0');

					if(isSquare(value))
						ans = max(ans, value);
					
					cur_X += dx;
					cur_Y += dy;
				} 
			}

	cout << ans << endl;

	return 0;
}