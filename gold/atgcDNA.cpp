#include <iostream>
#include <cstring>

#define MAX 501
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

string input;
int dp[MAX][MAX];
int dfs(int l, int r)
{
	if(l >= r) return 0;

	int &ref = dp[l][r];
	if(ref != -1) return ref;

	int res = -1;
	for(int i = l; i < r; i++) // XY
		res = max(res, dfs(l, i) + dfs(i+1, r));

	if((input[l] == 'a' && input[r] == 't') || 
			(input[l] == 'g' && input[r] == 'c')) // aXt or gXc
		res = max(res, dfs(l+1, r-1) + 2);

	return ref = res;
}

int main()
{
	cin >> input;
	memset(dp, -1, sizeof(dp));

	cout << dfs(0, input.length()-1);
	return 0;
}