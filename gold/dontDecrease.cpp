// #2668
#include<iostream>
#include<cstring>
#define MAX 65
using namespace std;

long long DP[MAX], board[MAX][9], K = 1;
// long long dp[MAX][10];
// void print()
// {
// 	for(int i = 0; i < MAX; i++){
// 		for(int j = 0; j < 9; j++)
// 			cout << board[i][j] << " ";
// 		cout << endl;
// 	}
// }
void solution()
{
	for(int i = 2; i < MAX; i++)
	{
		long long sumation = 0;
		for(int j = 1; j < 9; j++)
		{
			board[i][j] = board[i-1][j] + board[i][j-1];
			sumation += board[i][j];
		}
		DP[i] = sumation + DP[i-1] + 1;
	}
}
// void solution()
// {
// 	for(int i=2;i<65;i++) {
// 	    long long sum = 0;
// 	    for(int j=0;j<10;j++) {
// 	        dp[i][j] = dp[i-1][j] + sum;
//       		sum += dp[i-1][j];
//     }   
// }

int main()
{
	int T, N;
	cin >> T;
	DP[0] = 1;
	DP[1] = 10;
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++)
			board[i][j] = 1;
	}

	solution();
	for(int i = 0; i < T; i++){
		cin >> N;
		cout << DP[N] << endl;
	}
	return 0;
}