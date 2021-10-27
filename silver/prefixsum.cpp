//#11660

#include<iostream>
#include<queue>

#define MAX 1025
#define endl '\n'

using namespace std;


int board[MAX][MAX],dp[MAX][MAX];
int N, M;
queue<int> answer;
int main()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
			dp[i][j] = dp[i][j-1] + board[i][j];
		}
	}
	//print
	// for(int i = 1; i <= N; i++)
	// {
	// 	for(int j = 1; j <= N; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	int x1,y1,x2,y2;
	for(int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		// 2:2 / 3:4
		int tmp = 0;
		for(int j = 0; j <= x2 - x1; j++)
			tmp += dp[x1 + j][y2] - dp[x1 + j][y1-1];
		answer.push(tmp);
	}

	while(!answer.empty())
	{
		cout << answer.front() << endl;
		answer.pop();
	}
}