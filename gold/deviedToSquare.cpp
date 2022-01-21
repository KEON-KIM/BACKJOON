// #1451 
// @Reference Nimgnoej <https://nim-code.tistory.com/89>
#include<iostream>
#include<string>

#define MAX 51
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, M;
int board[MAX][MAX];
typedef long long ll;
ll result = 0;

int getSum(int start_X, int start_Y, int end_X, int end_Y)
{
	int sum = 0;
	for(int i = start_X; i <= end_X; i++)
		for(int j = start_Y; j <= end_Y; j++)
			sum+=board[i][j];
	return sum;
}

void FindSquare()
{	
	// ---
	// ---
	// ---
	FOR(i, N-2)
		for(int j = i + 1; j < N - 1; j++)
		{
			ll square1 = getSum(0, 0, i, M-1);
			ll square2 = getSum(i + 1, 0, j, M-1);
			ll square3 = getSum(j + 1, 0, N-1, M-1);
			result = max(result, square1 * square2 * square3);
		}
	// III
	FOR(i, M-2)
		for(int j = i + 1; j < M - 1; j++)
		{
			ll square1 = getSum(0, 0, N -1, i);
			ll square2 = getSum(0, i + 1, N - 1, j);
			ll square3 = getSum(0, j + 1, N - 1, M -1);
			result = max(result, square1 * square2 * square3);
		}
	//---I
	//---I
	for(int i = M - 1; i > 0; i--)
		for(int j = 0; j < N - 1; j++)
		{
			ll square1 = getSum(0, i, N - 1, M - 1);
			ll square2 = getSum(0, 0, j, i - 1);
			ll square3 = getSum(j + 1, 0, N - 1, i - 1);
			result = max(result, square1 * square2 * square3);
		}
	//I---
	//I---
	FOR(i, M-1)
		FOR(j, N-1)
		{
			ll square1 = getSum(0, 0, N -1, i);
			ll square2 = getSum(0, i + 1, j, M - 1);
			ll square3 = getSum(j + 1, i + 1, N - 1, M - 1);
			result = max(result, square1 * square2 * square3);
 		}
	// --
 	// II
 	// II
	FOR(i, N - 1)
		FOR(j, M - 1)
		{
			ll square1 = getSum(0, 0, i, M -1);
			ll square2 = getSum(i + 1, 0, N - 1, j);
			ll square3 = getSum(i + 1, j + 1, N - 1, M - 1);
			result = max(result, square1 * square2 * square3);
		}
 	// II
	// II
	// --
	for(int i = N - 1; i > 0; i--)
		FOR(j, M -1)
		{
			ll square1 = getSum(i, 0, N - 1, M - 1);
			ll square2 = getSum(0, 0, i - 1, j);
			ll square3 = getSum(0, j + 1, i - 1, M - 1);
			result = max(result, square1 * square2 * square3);
		}
}

int main()
{
	string input;
	cin >> N >> M;
	FOR(i, N){
		cin >> input;
		FOR(j, M)
			board[i][j] = input[j] - '0';
	}
	FindSquare();

	cout << result << endl;

	return 0;
}