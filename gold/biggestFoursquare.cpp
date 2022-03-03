// #4095
#include <iostream>
#include <cstring>
#define MAX 1002
#define endl '\n'
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define TFOR(i, n) for(int i = 2; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M;
bool board[MAX][MAX];
int dp[MAX][MAX];
int main()
{

	while(true)
	{
		int result = 0;
		cin >> N >> M;
		if(!N && !M) break;
		FOR(i, N)
			FOR(j, M){
				cin >> board[i][j];
				dp[i][j] = board[i][j];
				result = max(result, dp[i][j]);
			}

		TFOR(i, N)
			TFOR(j, M)
				if(board[i][j]){
					dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
					result = max(result, dp[i][j]);
					/*if((dp[i-1][j-1] == dp[i-1][j]) && (dp[i-1][j]  == dp[i][j-1]))
						dp[i][j] = dp[i-1][j-1] + 1;
					
					else
						dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));*/
				}

				// result = max(result, dp[i][j]);
		memset(dp, 0, sizeof(dp));
		cout <<result << endl;	
	}


	return 0;
		
}

// BRUTE FORCE
/*void Solution(int x, int y)
{
	for(int dia = maxSize; dia > squareSize; dia--)
	{
		// cout << dia << endl;
		bool flag = false;
		FOR(i, dia)
		{
			FOR(j, dia)
			{
				if(!board[x+i][y+j]){
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) squareSize = dia;
	}
}


int main()
{
	while(true)
	{
		squareSize = 0;
		cin >> N >> M;
		if(!N && !M) break;
		maxSize = min(N, M);
		FOR(i, N)
			FOR(j, M)
				cin >> board[i][j];

		FOR(i, N){
			if(maxSize == squareSize || N - i < squareSize) break;
			FOR(j, M){
				if(M - j < squareSize) break;
				else if(board[i][j]) 
					Solution(i, j);	
			}
		}

		cout << squareSize << endl;
	}
	return 0;
}*/