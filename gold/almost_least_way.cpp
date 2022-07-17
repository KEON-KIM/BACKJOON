#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 501
#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef pair<int, int> pii;

int N, M;
int dist[MAX];
vector<pii> board[MAX];
vector<int> trace[MAX];
bool visited[MAX][MAX];
void Init()
{
	memset(visited, false, sizeof(visited));
	FOR(i, N)
	{
		board[i].clear();
		trace[i].clear();
		dist[i] = INF;
	}
}
void Dijikstra(int s, int e)
{
	priority_queue<pii, vector<pii>, greater<pii>> pQue;
	pQue.push({0, s});

	dist[s] = 0;
	while(!pQue.empty())
	{
		int cost = pQue.top().first;
		int cur = pQue.top().second;
		pQue.pop();

		if(dist[cur] < cost) continue;
		for(pii p : board[cur])
		{
			int nextcost = cost + p.first;
			int next = p.second;

			if(p.first == -1) continue;
			if(dist[next] > nextcost)
			{
				dist[next] = nextcost;
				pQue.push({nextcost, next});

				trace[next].clear();
				trace[next].push_back(cur);
			}
			else if(dist[next] == nextcost)
				trace[next].push_back(cur);
		}
	}
}
void bfs(int e)
{
	queue<int> Que;

	Que.push(e);
	while(!Que.empty())
	{
		int cur = Que.front();
		Que.pop();

		for(int node : trace[cur])
		{
			if(visited[cur][node]) continue;
			FOR(i, board[node].size())
				if(board[node][i].second == cur)
					board[node][i].first = -1;

			visited[cur][node] = true;
			Que.push(node);
		}
	}
}
void print()
{
	FOR(i, N)
		FOR(j, board[i].size())
			cout << "CUR : " << i << " NEXT : " <<board[i][j].second << " COST : "<< board[i][j].first << endl;
}
int main()
{
	while(true)
	{
		int s, e;
		cin >> N >> M;
		if(!N && !M) break;

		Init();
		cin >> s >> e;
		FOR(i, M)
		{
			int u, v, cost;
			cin >> u >> v >> cost;
			board[u].push_back({cost, v});
		}

		Dijikstra(s, e);
		bfs(e);

		FOR(i, N) dist[i] = INF;
		Dijikstra(s, e);

		if(dist[e] == INF)
			cout << -1 << endl;
		else
			cout << dist[e] << endl; 
	}
	return 0;
}