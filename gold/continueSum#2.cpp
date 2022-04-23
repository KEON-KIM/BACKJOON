#include <iostream>
#include <vector>

#define MAX 100001
#define FOR(i,n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, result;
int board[MAX], dp[MAX];
int main()
{
	fastio;
	int input;
	cin >> N;
	FOR(i, N)
		cin >> board[i];
	dp[N-1] = board[N-1];
	result = board[N-1];
	for(int i = N - 2; i >= 0; i--){
		dp[i] = max(board[i], board[i]+dp[i+1]);
		result = max(result, dp[i]);
	}

	cout << result << endl;
	return 0;
}