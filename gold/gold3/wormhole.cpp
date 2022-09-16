// #1865 / Bellman-Ford
// @Reference jaimemin <https://4z7l.github.io/2021/03/04/algorithms-boj-1865.html>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 502
#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

typedef pair<int, int> pii;

struct edge {
	int s, e, t;
};
int TC, N, M, W;
bool time_travel(int n, vector<edge> &edges) {
	vector<int> dist(n + 1, INF);

	int s, e, t;
	dist[1] = 0;
	FOR(k, n-1)
	{
		FOR(i, edges.size())
		{
			s = edges[i].s;
			e = edges[i].e;
			t = edges[i].t;
			if (dist[e] > dist[s] + t) 
				dist[e] = dist[s] + t;
			
		}
	}

	FOR(i, edges.size())
	{
		s = edges[i].s;
		e = edges[i].e;
		t = edges[i].t;
		if (dist[e] > dist[s] + t) 
			return true;
	}
	return false;
}
int main()
{
	fastio;
	cin >> TC;
	FOR(tc, TC)
	{
		int S, E, T;
		vector<edge> edges;
		cin >> N >> M >> W;
		FOR(m, M)
		{
			cin >> S >> E >> T;
			edges.push_back({S, E, T});
			edges.push_back({E, S, T});
		}
		FOR(w, W)
		{
			cin >> S >> E >> T;
			edges.push_back({S, E, -T});
		}
		
		if(time_travel(N, edges)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
// dijikstra
/*bool bfs(int s, vector<pii> graph[MAX])
{
	priority_queue<pii, vector<pii>, greater<pii>> pQue;
	pQue.push({0, s});

	time_board[s] = 0;
	while(!pQue.empty())
	{
		int cost = pQue.top().first;
		int cur = pQue.top().second;
		pQue.pop();

		cout << cur << "/" << cost << endl;
		FOR(i, graph[cur].size())
		{
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;

			cout << "next : " << next << endl;
			if(time_board[next] == INF)
			{
				cout << "WHAT" << endl;
				time_board[next] = cost + nextCost;
				pQue.push({cost + nextCost, next});
			}
			else if( s == next && cost + nextCost < 0){
				return true;
			}
		}
	}
	return false;
}*/