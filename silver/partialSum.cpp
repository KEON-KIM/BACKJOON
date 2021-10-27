//#1806
//@Reference rightbellboy <https://rightbellboy.tistory.com/82>

#include<iostream>

#define MAX 100000

using namespace std;

int N, M;
int board[MAX];//, dp[MAX];
int main()
{
	cin >> N >> M;
	// for(int i = 1; i <= N; i++) // O(nlogn) : Failed
	// {
	// 	cin >> board[i];
	// 	dp[i] = dp[i-1] + board[i];
	// 	if (dp[i] >= M)
	// 		for(int j = 0; j < answer; j++)
	// 			if(dp[i] - dp[i-j] >= M && answer > j){
	// 				answer = j;
	// 				break;
	// 			}
		
	// }

	//print
	// for(int i = 1; i <= N; i++){
	// 	cout << dp[i] << " ";
	// }cout << endl;

	for(int i = 0; i < N; i++) // O(n) : Sucess
		cin >> board[i];
	int low = 0, high = 0, sum = 0, len = N + 1;

	while(high <= N && low <= high)
	{
		if(sum < M)
			sum += board[high++];
		
		else
		{
			len = min(len, (high - low));
			sum -= board[low++];
		}
	}
	if(len == N + 1) len = 0;
	cout << len << endl;

	// if(answer == 987654321) answer = 0;
	// cout << answer << endl;
	return 0; 
}