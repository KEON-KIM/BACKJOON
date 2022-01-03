// #13398
#include<iostream>
#define MAX 100001
#define INF 1000

using namespace std;

int N, result = -INF;
int board[MAX], DP[MAX][2]; // 0 : Non_continue / 1 : Continue
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> board[i];

	DP[0][0] = board[0];
	DP[0][1] = board[0];

	result = max(DP[0][0], DP[0][1]);
	for(int i = 1; i < N; i++)
	{
		DP[i][0] = max(0, DP[i-1][0]) + board[i];
		DP[i][1] = max(DP[i-1][0], DP[i-1][1] + board[i]);
		result = max(max(DP[i][0], DP[i][1]), result);
	}

	cout << result << endl;
	return 0;
}