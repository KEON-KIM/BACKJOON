#include<iostream>
#include<queue>
#define MAX 501

using namespace std;

int N, answer = 0;
int board[MAX][MAX];
int DP[MAX][MAX];


queue<pair<int, int>> Que;

void bfs()
{
	int x, y, cnt;
	while(!Que.empty())
	{
		x = Que.front().first;
		y = Que.front().second;

		Que.pop();
		if(x == N ) 
			answer = max(answer, board[x][y]);
		
		else
		{
			Que.push(make_pair(x+1,y));
			Que.push(make_pair(x+1,y+1));
		}
	}
}

int main()
{
	cin >> N;
	for(int i = 0 ; i < N; i++)
		for(int j = 0; j <= i; j++)
			cin >> board[i][j];

	// Que.push(make_pair(0,0));
	DP[0][0] = board[0][0];
	for(int i = 1; i < N; i++)
	{
		for(int j = 0; j <= i; j++)
		{
		// 	if(!j)
		// 		DP[i][j] = board[i][j] + DP[i-1][j];
		// 	else if (j == i)
		// 		DP[i][j] = board[i][j] + DP[i-1][j-1];
		// 	else
			DP[i][j] = board[i][j] + max(DP[i-1][j-1], DP[i-1][j]);
			// if(i == N - 1) answer = max(answer, DP[i][j]);
		}
	}
	// bfs();
	for(int i = 0; i < N; i++)
		answer = max(answer, DP[N-1][i]);
	// print	
	// for(int i = 0; i < N; i++)
	// {
	// 	for(int j = 0; j < N; j++)
	// 		cout << board[i][j] << " ";
	// 	cout << endl;
	// }

	// for(int i = 0; i < N; i++)
	// {
	// 	for(int j = 0; j < N; j++)
	// 		cout << DP[i][j] << " ";
	// 	cout << endl;
	// }

	cout << "RESULT : " << answer << endl;
	return 0;
}