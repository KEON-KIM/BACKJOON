#include<iostream>
#include<vector>

#define MAX 100002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

int N, Q;
vector<int> board[MAX];
// vector<pair<int, int>> question;
int main()
{
	fastio;
	cin >> N;
	FOR(i, N-1)
	{
		int x, y;
		cin >> x >> y;
		board[x].push_back(y);
		board[y].push_back(x);
	}
	cin >> Q;
	FOR(i, Q)
	{
		int t, k;
		cin >> t >> k;
		if(t == 1) // Point
		{
			if(board[k].size() == 1)
				cout << "no" << endl;
			else
				cout << "yes" << endl;
		}
		else // Line
			cout << "yes" << endl;
		
	}
	return 0;
}