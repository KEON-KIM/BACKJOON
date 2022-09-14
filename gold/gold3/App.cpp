#include<iostream>
#include<algorithm>

#define MAX 101
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, M, ans, sum;
int bite[MAX], cost[MAX];
int DP[MAX][10001];
int main()
{
	cin >> N >> M;

	FOR(i, N) cin >> bite[i];
	FOR(i, N)
	{
		cin >> cost[i];
		sum += cost[i];
	}

	FOR(i, N)
		for(int j = 0; j <= sum; j++)
		{
			if (j - cost[i] >= 0)
				DP[i][j] = max(DP[i][j], DP[i - 1][j - cost[i]] + bite[i]);
			
			DP[i][j] = max(DP[i][j], DP[i - 1][j]);
		}
	

	for(int i = 0; i <= sum; i++)
		if (DP[N][i] >= M)
		{
			cout << i << endl;
			break;
		}
}