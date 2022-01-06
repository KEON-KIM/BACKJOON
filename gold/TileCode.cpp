//#1720
#include<iostream>
#define MAX 32

using namespace std;

int N, board[MAX];
int main()
{
	cin >> N;
	board[0] = 1;
	board[1] = 1;

	for(int i = 2; i <= 30; i++)
		board[i] = board[i-1] + board[i-2] * 2;
	// board[N] = 1.condition + 2.condition
	// 1. Condition : Symmetry-Self / 2. Condition : Non-Symmetery-Self
	// Answer = (2.condition/ 2) + 1. condition
	// => Answer = (board[N] + 1.condition)/2

	if(!(N%2))
		board[N] = (board[N] + (board[N/2] + board[N/2 - 1] * 2))/2;
	else
		board[N] = (board[N] + board[(N-1)/2])/2;

	cout << board[N] << endl;
	return 0;
}