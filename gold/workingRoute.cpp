//#5569
//@Reference justicehui <https://justicehui.github.io/joi/2019/02/10/BOJ5569/>
#include <iostream>
#define MAX 102
#define INF 100000
#define FOR(i, n) for(int i = 2; i <= n; i++)
using namespace std;

int board[MAX][MAX][2][2]; //dir, 1 or over2
int W, H, result = 0;
void INIT()
{
	FOR(i, W) board[i][1][0][0] = 1;
	FOR(i, H) board[1][i][1][0] = 1;
}
int main(){
	cin >> W >> H;

	INIT();

	FOR(i, W){
		FOR(j, H){
			board[i][j][0][0] = (board[i-1][j][0][0] + board[i-1][j][0][1]) % INF;
			board[i][j][0][1] = board[i-1][j][1][0];
			board[i][j][1][0] = (board[i][j-1][1][0] + board[i][j-1][1][1]) % INF;
			board[i][j][1][1] = board[i][j-1][0][0];
		}
	}

	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++) 
			result += board[W][H][i][j];
	
	cout << result%INF;
}