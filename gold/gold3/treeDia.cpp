#include <iostream>
#include <vector>
#include <cstring>

#define MAX 100001
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N;
int node, result = 0;
vector<pair<int, int>> board[MAX];
bool visited[MAX];
void dfs(int cur, int cost)
{
    if (visited[cur]) return;
    if (result < cost){
    	node = cur;
        result = cost;
    }
    
    visited[cur] = true; //방문 체크
    for(pair<int, int> p : board[cur])
    {
        int next = p.first;
        int nextCost = p.second;
        dfs(next, nextCost + cost);
    }
}
int main()
{
	cin >> N;
	int c, n, cost;
	FOR(i, N)
	{
		cin >> c;
		while(true)
		{
			cin >> n;
			if(n < 0) break;
			cin >> cost;
			board[c].push_back({n, cost});
			board[n].push_back({c, cost});
		}
	}

	dfs(1, 0);

	memset(visited, false, sizeof(visited));
	result = 0;
	dfs(node, 0);

	cout << result << endl;
	return 0;
}