//#6497
#include <iostream>
#include <vector>
#include <queue>

#define MAX 200001
#define INF 987654321	 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

int N, M, total;
bool visited[MAX];
vector<pii> graph[MAX];
void Init()
{
	FOR(i, N){
		total = 0;
		visited[i] = false;
		graph[i].clear();
	}
}
// Prim Algorithm
int bfs()
{
	int result = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pQue;
	for(pii p : graph[0])
		pQue.push({p.first, p.second});

	visited[0] = true;
	while(!pQue.empty())
	{
		int cur = pQue.top().second;
		int curCost = pQue.top().first;
		pQue.pop();

		if(!visited[cur])
		{
			visited[cur] = true;
			result += curCost;

			for(pii p : graph[cur])
			{
				int next = p.second;
				int nextCost = p.first;

				if(!visited[next])
					pQue.push({nextCost, next});
			}
		}
	}
	return total - result;
}

int main()
{
	fastio;
	int a, b, cost;
	while(true)
	{
		cin >> N >> M;
		if(!N && !M) break;

		Init();
		FOR(i, M)
		{
			cin >> a >> b >> cost;
			total += cost;
			graph[a].push_back({cost, b});
			graph[b].push_back({cost, a});
		}

		cout << bfs() << endl;
	}
	
	return 0;
}