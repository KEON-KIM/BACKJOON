// #1240
#include <iostream>
#include <vector>

#define MAX 1002
#define INF 987654321

using namespace std;

int N, M, board[MAX][MAX];

void print()
{
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++)
			cout << board[i][j] << " ";
		cout << endl; 
	}
}
void INIT()
{
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++){
			if(i==j) board[i][j] = 0;
			else board[i][j] = INF;
		}
	
}

void Floyd()
{

	for(int via = 1; via <= N; via++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				board[i][j] = min(board[i][j], board[i][via] + board[via][j]);			
}
int main()
{
	cin >> N >> M;
	int n, m, v;
	INIT();
	for(int i = 1; i < N; i++){
		cin >> n >> m >> v;
		board[n][m] = v;
		board[m][n] = v;
	}

	Floyd();
	for(int i = 0; i < M; i++){
		cin >> n >> m;
		cout << board[n][m] << endl;
	}
	print();
		
	return 0;
}