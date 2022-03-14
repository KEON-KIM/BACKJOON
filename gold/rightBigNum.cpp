//#17298
#include <iostream>
#include <queue>
#include <cstring>

#define MAX 1000001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N;
int board[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQue; // val, idx;
int main()
{
	fastio;
	cin >> N;
	memset(board, -1, sizeof(board));
	FOR(i, N)
	{
		int x; cin >> x;
		while(!pQue.empty() && pQue.top().first < x)
		{
			int f = pQue.top().first;
			int s = pQue.top().second;

			board[s] = x;
			pQue.pop();
		}

		pQue.push({x, i});
	}

	FOR(i, N)
		cout << board[i] << " ";
	return 0;
}