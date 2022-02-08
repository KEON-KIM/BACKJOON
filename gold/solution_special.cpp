//#14921
#include<iostream>
#include<cmath>

using namespace std;
#define MAX 100001
#define INF 200000010
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int N, board[MAX], result;
int main()
{
	cin >> N;
	FOR(i, N)
		cin >> board[i];

	int l = 0, r = N - 1;
	result = INF;

	while(l < r)
	{
		int cmp = board[r] + board[l];
		if(abs(board[l]) > abs(board[r]))
			l++;
		else
			r--;
		if(abs(result) > abs(cmp))
			result = cmp;
	}

	cout << result << endl;
	return 0;
}