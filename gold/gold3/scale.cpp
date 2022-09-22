//#2629
// @Reference cocoon1787 <https://cocoon1787.tistory.com/360>
#include<iostream>
#include<algorithm>
#include<cmath>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n, weights[31];
bool dp[31][15001];

void dfs(int idx, int w)
{
	if (idx > n || dp[idx][w]) return;
	dp[idx][w] = true;
	dfs(idx + 1, w + weights[idx]);
	dfs(idx + 1, abs(w - weights[idx]));
	dfs(idx + 1, w);
}

int main()
{
	fastio;
	cin >> n;
	FOR(i, n)
		cin >> weights[i];
	
	dfs(0, 0);

	int b, x;
	cin >> b;
	FOR(i, b)
	{
		cin >> x;
		if(x > 15000) cout << "N ";
		else if (dp[n][x]) cout << "Y ";
		else cout << "N ";
	}	
}