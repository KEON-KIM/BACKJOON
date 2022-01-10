//#14728
#include<iostream>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define TMAX 10001
#define MAX 101
using namespace std;

int N, T, board[TMAX];
int score[MAX][2];
int main()
{
	int t = 0;

	cin >> N >> T;
	FOR(i, N)
		cin >> score[i][0] >> score[i][1];

	FOR(i, N){
		cout << "=============================" << endl;
		for(int j = T; j > score[i][0]-1; j--){
			board[j] = max(board[j], board[j - score[i][0]] + score[i][1]);
			cout << "TIME [" << j << "] : " << board[j] << endl;
		}
		// for(int j = score[i][0]; j < score[i][0]*2; j++){
		// 	board[j] = max(board[j], board[j - score[i][0]] + score[i][1]); 
		// }
	}

	cout << board[T] << endl;

	return 0;
}