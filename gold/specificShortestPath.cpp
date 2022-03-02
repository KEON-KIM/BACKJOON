//#1753
//@Reference chosh95 <https://chosh95.tistory.com/419>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 801
#define INF 987654321
#define endl '\n'
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int path[3][3];
int N, E, cache[MAX];
int sv1, sv2;
vector<pair<int, int>> board[MAX]; // index : cost, npos

void Dijikstra(int start)
{
	FOR(i, N+1) cache[i] = INF; // INIT
	cache[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // cost, npos
	q.push({ 0, start });
	while (!q.empty()) {
		int cur = q.top().second;
		int curDist = q.top().first;
		q.pop();
		for (pair<int, int> p : board[cur]) {
			int next = p.second;
			int nextDist = p.first;
			if (cache[next] > curDist + nextDist) {
				cache[next] = curDist + nextDist;
				q.push({ cache[next], next });
			}
		}
	}
}
int main()
{
	fastio;
	int result = INF;
	cin >> N >> E;
	FOR(i, E)
	{
		int x, y, cost;
		cin >> x >> y >> cost;

		board[x].push_back({cost, y}); // cost, npos
		board[y].push_back({cost, x}); // cost, npos
	}
	cin >> sv1 >> sv2;

	Dijikstra(1);
	path[0][1] = cache[sv1]; //start -> v1
	path[0][2] = cache[sv2]; // start -> v2

	Dijikstra(sv1);
	path[1][1] = cache[sv2]; // v1 -> v2
	path[1][2] = cache[N]; // v1 -> N

	Dijikstra(sv2);
	path[2][2] = cache[N]; // v2 -> N

	result = min(result, path[0][1] + path[1][1] + path[2][2]);
	result = min(result, path[0][2] + path[1][1] + path[1][2]);

	if(path[1][1] == INF || result == INF)cout << -1 << endl;
	else cout << result << endl;
	return 0;
}