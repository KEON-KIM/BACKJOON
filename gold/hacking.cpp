#include <iostream>
#include <cstring>
#include <queue>

#define MAX 10001
#define INF 1000000002
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

int T, N, D, C;
int timeCost[MAX];
bool visited[MAX];
vector<pii> computer[MAX];
void Init()
{
	FOR(i, N)
	{
		computer[i].clear();
		timeCost[i] = INF;
	}
}
void print()
{
	FOR(i, N)
		cout << timeCost[i] << " ";
}
void Dijikstra(int start)
{
	timeCost[start] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pQue;
	pQue.push({0, start}); // cost, cur;
	while(!pQue.empty())
	{
		int cur = pQue.top().second;
		int cost = pQue.top().first;
		pQue.pop();

		for(pii p : computer[cur])
		{
			int nextCost = p.first;
			int next = p.second;

			int cmp = cost + nextCost;
			if(timeCost[next] > cmp)
			{
				timeCost[next] = cmp;
				pQue.push({cmp, next});
			}
		}
	}

	int result = 0, maxTime = -1;
	FOR(i, N)
		if(timeCost[i] != INF){
			result++;
			maxTime = max(maxTime, timeCost[i]);
		}
	
	cout << result << " " << maxTime << endl; 
}

int main()
{
	fastio;
	cin >> T;
	int a, b, s;
	bool flag = false;
	FOR(t, T){ 
		cin >> N >> D >> C;

		Init();
		FOR(d, D)
		{
			cin >> a >> b >> s;
			computer[b].push_back({s, a});
		}

		Dijikstra(C);
		if(!flag)flag = true;
	}
	return 0;
}