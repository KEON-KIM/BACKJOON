#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int N, M;
bool visited[MAX];
vector<pair<int, int>> board[MAX];// dest, cost;
int main()
{
	fastio;
	cin >> N >> M;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQue;

	FOR(i, M)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		board[x].push_back({y, cost});
		board[y].push_back({x, cost});
	}

	int result = 0;
	int maxRoad = 0;
	pQue.push({0, 1}); // cost, index;
	while(!pQue.empty())
	{
		int cost = pQue.top().first;
		int cur = pQue.top().second;
		pQue.pop();

		if (!visited[cur])
        {
        	visited[cur] = true;
        	result += cost;
        	maxRoad = max(maxRoad, cost);
        	for(pair<int, int> p : board[cur])
        	{
        		int next = p.first;
        		int nextCost = p.second;

        		if(!visited[next])
        			pQue.push({nextCost, next});
        	}
        }
	}

	cout << result - maxRoad << endl;
	return 0;
}