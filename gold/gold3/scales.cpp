//#2437
#include <iostream>
#include <algorithm>

#define MAX 1001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef long long ll;

int N, board[MAX];
int main()
{
	fastio;
	cin >> N;
	FOR(i, N)
		cin >> board[i];
	
	sort(board, board+N);

	ll sum = 1;
	FOR(i, N)
	{
		if(board[i] > sum)
		{
			cout << sum;
			return 0;
		}
		sum += board[i];
	}

	cout << sum;
	return 0;
}