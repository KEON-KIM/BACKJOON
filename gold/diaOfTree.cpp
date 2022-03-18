// #1967
#include <iostream>
#include <vector>

#define endl '\n'
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct info
{
	int x;
	int y;
	int cost;
};

int N, result;
vector<info> board;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
void make_graph(int size)
{
	visited.resize(size+1, false);
	graph.resize(size+1);
	FOR(i, board.size())
	{
		graph[board[i].x].push_back({board[i].y, board[i].cost});
		graph[board[i].y].push_back({board[i].x, board[i].cost});	
	}
}

void dfs(int start, int cost)
{
	result = max(result, cost);

	for(pair<int, int> p : graph[start])
	{
		int next = p.first;
		int nextCost = p.second;
		if(visited[next]) continue;

		visited[next] = true;
		dfs(next, cost + nextCost);
		visited[next] = false;
	}
}
int main()
{
	cin >> N;
	int sizeMax = 0;
	FOR(i, N-1)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		board.push_back({x, y, cost});
		sizeMax = max(sizeMax, max(x, y));
	}
	make_graph(sizeMax);

	FOR(i, sizeMax+1)
	{
		if(graph[i].size() < 1) continue;

		visited[i] = true;
		dfs(i, 0);
		visited[i] = false;
	}

	cout << result << endl;

	return 0;
}