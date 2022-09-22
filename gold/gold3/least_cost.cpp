//#11779
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 1002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RFOR(i, n) for(int i = n-1; i >= 0; i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N, M, S, E;
int back_tracking[MAX];

ll dist[MAX];
vector<pii> board[MAX];
vector<int> result;

void Dijikstra(int start, int dest)
{
	vector<int> route;
	priority_queue<pli, vector<pli>, greater<pli>> pQue;

	pQue.push({0, start});

	dist[start] = 0;
	while(!pQue.empty())
	{
		int cur = pQue.top().second;
		ll cost = pQue.top().first;
		pQue.pop();

		if(cur == dest) break;
		if(dist[cur] < cost) continue;
		FOR(i, board[cur].size())
		{
			int next = board[cur][i].first;
			ll nextCost = board[cur][i].second;

			if(cost + nextCost < dist[next])
			{
				dist[next] = cost + nextCost;
				back_tracking[next] = cur;
				pQue.push({cost + nextCost, next});
			}
		}
	}

	cout << dist[dest] << endl;
	int before = dest;
	while(before)
	{
		result.push_back(before);
		before = back_tracking[before];
	}
	cout << result.size() << endl;
	RFOR(i, result.size()) cout << result[i] << ' ';
}
int main()
{
	cin >> N >> M;
	int s, e, cost;
	FOR(i, M)
	{
		cin >> s >> e >> cost;
		board[s].push_back({e, cost});
	}
	cin >> S >> E;
	memset(dist, 0x7f, sizeof(dist));
	Dijikstra(S, E);

	return 0;
}