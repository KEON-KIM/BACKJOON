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
int dp[MAX][2];
bool visited[MAX];
vector<int> graph[MAX];
vector<int> Tree[MAX];
int dfs(int cur, bool state)
{
	int &ref = dp[cur][state];
	if(ref != -1) return ref;
	if(state)
	{
		ref = 1;
		FOR(i, Tree[cur].size())
		{
			int next = Tree[cur][i];
			ref += min(dfs(next, 0), dfs(next, 1));
		}
	}
	else
	{
		ref = 0;
		FOR(i, Tree[cur].size())
		{
			int next = Tree[cur][i];
			ref += dfs(next, 1);
		}
	}

	return ref;
}

void make_tree(int cur)
{
	visited[cur] = true;
	FOR(i, graph[cur].size())
	{
		int next = graph[cur][i];
		if(!visited[next])
		{
			Tree[cur].push_back(next);
			make_tree(next);
		}
	}
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
		graph[e].push_back(s);
	}
	memset(dp, -1, sizeof(dp));
	make_tree(1); 
	cout << min(dfs(1, 0), dfs(1, 1));
	return 0;
}
