//#2229
#include<iostream>
#include<cmath>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


#define MAX 1002
#define INF 10000

using namespace std;

int N;
int board[MAX], dp[MAX];
int main()
{
	fastio;
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> board[i];

	for(int i = 2; i <= N; i++)
	{
		int low = 10004;
		int high = -1;

		for(int j = i; j >= 1; j--)
		{
			low = min(low, board[j]);
			high = max(high, board[j]);
			dp[i] = max(dp[i], high - low + dp[j-1]);
			// cout << "INDEX ["<< i << "] : "<< dp[i] << endl;
		}
	}

	cout << dp[N] << endl;

}
