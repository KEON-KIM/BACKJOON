#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N;
int board[MAX], DP[MAX];
vector<int> result;
void print()
{
	FOR(i, N)
		cout << DP[i] << " ";
	cout << endl;
}
int main()
{
	fastio;
	cin >> N;
	FOR(i, N)
	{
		cin >> board[i];
	}

	int maxi = 0;
	FOR(i, N)
	{
		DP[i] = 1;	
		if(DP[i] >= DP[maxi]) maxi = i;
		for(int j = i-1; j >= 0; j--)
			if(board[i] > board[j] && DP[i] < DP[j] + 1)
			{
				DP[i] = DP[j] + 1;
				if(DP[maxi] <= DP[i])
					maxi = i;
			}
	}
	
	int cmp = board[maxi];
	result.push_back(board[maxi]);
	for(int i = maxi-1; i >= 0; i--)
	{
		if(board[i] < cmp && DP[i] == DP[maxi] - 1)
		{
			cmp = board[i];
			maxi = i;
			result.push_back(cmp);
		}
	}

	cout << result.size() << endl;
	reverse(result.begin(), result.end());
	FOR(i, result.size())
		cout << result[i] << " ";
	cout << endl;

	return 0;
}