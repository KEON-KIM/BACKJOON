// #1563
// @Reference kibbomi <https://kibbomi.tistory.com/98>
#include <iostream>

#define MAX 1002
#define MOD 1000000
#define FOR(i, n) for(int i = 2; i <= n; i++)
using namespace std;

int N;
int board[MAX][2][3];
int main()
{
	cin >> N;
	board[1][0][0] = board[1][1][0] = board[1][0][1] = 1;

	FOR(i, N)
	{
		board[i][0][0] = (board[i-1][0][0] + board[i-1][0][1] + board[i-1][0][2]) % MOD; // 0 LATE 0 ABS
		board[i][0][1] = board[i-1][0][0] % MOD; // 0 LATE 1 ABS
		board[i][0][2] = board[i-1][0][1] % MOD; // 0 LATE 2 ABS
		board[i][1][0] = (board[i-1][0][0] + board[i-1][0][1] + board[i-1][0][2] + board[i-1][1][0] + board[i-1][1][1] + board[i-1][1][2]) % MOD; // 1 LATE 0 ABS
		board[i][1][1] = board[i-1][1][0] % MOD;// 1 LATE 1 ABS
		board[i][1][2] = board[i-1][1][1] % MOD; // 1 LATE 2 ABS
	}

	int result = (board[N][0][0] + board[N][0][1] + board[N][0][2] + board[N][1][0] + board[N][1][1] + board[N][1][2]) % MOD; // SUM OF ALL CASES
	cout << result;
	return 0;
}