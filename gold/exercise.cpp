#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 401
#define INF 987654321
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef pair<int, int> pii;

int V, E;
int dis[MAX];
bool visited[MAX];
vector<pii> board[MAX];
int Dijikstra(int start)
{
	priority_queue<pii, vector<pii>, greater<pii>> pQue;
	int res = INF;
	dis[start] = 0;
	pQue.push({0, start}); //{cost, index}

	while(!pQue.empty())
	{
		int cur = pQue.top().second;
		int cost = pQue.top().first;
		pQue.pop();

		if(!visited[cur]){
			visited[cur] = true;
			for(pii p : board[cur])
			{
				int next = p.second;
				int nextCost = p.first;

				if(next == start)
				{
					res = min(res, dis[cur] + nextCost);
					continue;
				}
				if(dis[next] > nextCost + dis[cur])
				{
					dis[next] = nextCost + dis[cur];
					pQue.push({dis[next], next});
				}
			}
		}
	}

	return res;
}
void Init()
{
	FOR(i, V)
		dis[i] = INF;
}
int main()
{
	fastio;
	int result= INF;
	cin >> V >> E;
	FOR(i, E)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		board[a].push_back({cost, b});
	}

	FOR(i, V)
	{
		Init();
		memset(visited, false, sizeof(visited));
		result = min(result, Dijikstra(i));
	}
	
	if(result == INF) result = -1;
	cout << result << endl;
	return 0;
}