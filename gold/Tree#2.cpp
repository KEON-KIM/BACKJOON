#include <iostream>
#include <vector>
#include <queue>

#define MAX 502
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
using namespace std;

int N = 1, M = 1;
bool visited[MAX];
vector<int> board[MAX];
void Init()
{
	FOR(i, N)
	{
		board[i].clear();
		visited[i] = false;
	}
}
bool DFS(int start, int before)
{
	visited[start] = true;
	for(int next : board[start])
	{
		if(next == before) continue;
		if(visited[next]) return false; // cycle
		if(!DFS(next, start)) return false;
	}

	return true;
}

int main()
{
	fastio;
	int t = 0;
	while(true)
	{
		cin >> N >> M;
		if(N == 0 && M == 0) break;

		Init();
		FOR(i, M)
		{
			int u, v;
			cin >> u >> v;
			board[u].push_back(v);
			board[v].push_back(u);
		}

		int result = 0;
		FOR(i, N)
			if(!visited[i])
				if(DFS(i, 0)) result++;
				
			
		cout << "Case " << ++t;

		if(result > 1)
			cout << ": A forest of "<< result << " trees." << endl;

		else if(result == 1)
			cout << ": There is one tree." << endl;

		else
			cout << ": No trees." << endl;
	}
	return 0;
}