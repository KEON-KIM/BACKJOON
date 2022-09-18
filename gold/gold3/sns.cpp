// #2533 / Dynamic Programming
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 1000001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int N, INF;
int dp[MAX];
bool isAdapter[MAX];
vector<int> graph[MAX];
int dfs(int n)
{
	int &ref = dp[n];
	bool flag = false;
	if(ref != INF) return ref;
	if(!graph[n].size()) return 0;

	int tmp = 0;
	FOR(i, graph[n].size())
	{
		int k = dfs(graph[n][i]);
		if(isAdapter[graph[n][i]]) flag = true;
		tmp += k;
	}

	ref = tmp;
	if(!flag) {isAdapter[n] = true; ref+=1;}
	return ref;
}
int main()
{
	fastio;
	int s, e;
	cin >> N;
	FOR(i, N-1)
	{
		cin >> s >> e;
		graph[s].push_back(e);
	}
	memset(dp, 0x3f, sizeof(dp));
	INF = dp[0];

	cout << dfs(1);
	return 0;
}
