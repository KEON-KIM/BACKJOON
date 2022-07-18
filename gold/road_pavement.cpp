#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 10001
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> plpii;
int N, M, K;
ll dist[MAX][21];
vector<pii> graph[MAX];
const ll INF = INT64_MAX;
ll Dijikstra(int s, int d)
{
	// Init();
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<plpii, vector<plpii>, greater<plpii>> pQue;
	pQue.push({0, {s, 0}}); // {cost, cur};

	dist[s][0] = 0;
	while(!pQue.empty())
	{
		ll cost = pQue.top().first;
		int cur = pQue.top().second.first;
		int pave = pQue.top().second.second;
		pQue.pop();

		if(cost > dist[cur][pave]) continue;
		for(pii p : graph[cur])
		{
			ll nextCost = cost + p.first;
			int next = p.second;

			if(dist[next][pave] > nextCost)
			{
				pQue.push({nextCost, {next, pave}});
				dist[next][pave] = nextCost;
			}

			if(pave < K && dist[next][pave+1] > cost)
			{
				dist[next][pave+1] = cost;
				pQue.push({cost, {next, pave+1}});
			}
		}
	}

	ll result = INF;
	FOR(i, 21) result = min(result, dist[N][i]);
	

	return result;
}

int main()
{
	cin >> N >> M >> K;
	int u, v, cost;

	FOR(i, M)
	{
		cin >> u >> v >> cost;
		graph[u].push_back({cost, v});
		graph[v].push_back({cost, u});
	}

	cout << Dijikstra(1, N) << endl;
	return 0;
}