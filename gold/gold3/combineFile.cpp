#include <iostream>

#define MAX 501
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, M;
int board[MAX/2][MAX];
void print(int idx, int sum)
{
	for(int i = 0; i < M; i++)
		cout << board[idx][i] << " ";
	cout << " SUM : " << sum << endl;
}
int main()
{
	cin >> N;
	FOR(i, N)
	{
		int sum = 0;
		int idx = 0;
		cin >> M;
		FOR(j, M)
			cin >> board[0][j];
		while(M >= 2)
		{
			if(M%2) 
			{	
				for(int i = 0; i < M/2; i++)
				{
					board[idx+1][i] = board[idx][i * 2] + board[idx][(i * 2) + 1];
					sum += board[idx+1][i];
				}
				board[idx + 1][M/2] = board[idx][M-1];
				M = M/2 + 1;
			}
			else
			{
				for(int i = 0; i < M/2; i++)
				{
					board[idx + 1][i] = board[idx][i * 2] + board[idx][(i * 2) + 1];
					sum += board[idx + 1][i];
				}
				M = M/2;
			}
			idx++;
			print(idx, sum);
		}
	}
	return 0;
}