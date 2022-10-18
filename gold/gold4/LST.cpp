#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 10001
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, M;
vector<pii> board[MAX];
int main()
{
	fastio;
	cin >> N >> M;
	FOR(i, M)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		board[a].push_back({cost, b});
		board[b].push_back({cost, a});
	}
	bool visited[MAX] = {false, };
	priority_queue<pii, vector<pii>, greater<pii>> pQue;
	pQue.push({0, 1});

	ll result = 0;
	while(!pQue.empty())
	{
		int cost = pQue.top().first;
		int cur = pQue.top().second;
		pQue.pop();

		if(visited[cur]) continue;
		result += cost;
		visited[cur] = true;
		for(int i = 0; i < board[cur].size(); i++)
		{
			int next = board[cur][i].second;
			int nextCost = board[cur][i].first;
			pQue.push({nextCost, next});
		}
	}

	cout << result;

	return 0;
}