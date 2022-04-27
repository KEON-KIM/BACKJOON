#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX 1000001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int X, N;
int board[MAX];

void Binary()
{
	bool flag = false;
	for (int i = 0; i < N && board[i] <= X / 2; i++) 
	{
		int l = i+1, r = N-1;
		while(l <= r)
		{
			int mid = (l+r)/2;

			if(board[mid] + board[i] == X) 
			{	
				cout << "yes "<< board[i] << " " <<  board[mid] << endl;
				return;
			}

			else if(board[mid] + board[i] < X)
				l = mid+1;

			else
				r = mid-1;
		}
	}
		
	cout << "danger" << endl;
}

int main()
{
	fastio;
	while(cin >> X)
	{
		cin >> N;
		FOR(i, N)	
			cin >> board[i];

		X *= pow(10, 7);
		sort(board, board+N);
		Binary();
	}

	return 0;
}