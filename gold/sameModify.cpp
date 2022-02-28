//#1684
#include <iostream>
#include <algorithm>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define MAX 1001

int N, board[MAX-1], input[MAX];
int GCD(int a, int b)
{
	if(!(a%b)) return b;
	else return GCD(b, a%b);
}
int main()
{
	cin >> N;
	FOR(i, N)
		cin >> input[i];
	sort(input, input+N);
	FOR(i, N-1)
		board[i] = input[i+1] - input[i];

	int result = board[0];
	for(int i = 1; i < N - 1; i++)
		if(board[i])
			result = GCD(result, board[i]);
	
	
	cout << result << endl;

	return 0;
}