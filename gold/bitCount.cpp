//#2698
#include <iostream>

#define MAX 102
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
using namespace std;

int T;
int board[MAX][MAX-1][2];
int main()
{
	fastio;
	int N, K;
	cin >> T;
	board[1][0][0] = 1;
	board[1][0][1] = 1;

    for (int i = 2; i < MAX; i++) {
		for (int j = 0; j < i; j++) {
			board[i][j][0] = board[i - 1][j][0] + board[i - 1][j][1];
			board[i][j][1] = board[i - 1][j][0] + board[i - 1][j - 1][1];
		}
	}

	while (T--) {
		cin >> N >> K;
		cout << board[N][K][0] + board[N][K][1] << "\n";

	}
	return 0;
}