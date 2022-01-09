#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 100001
#define INF 10000000 // MAX * 1000
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<pair<int, int>> board[MAX];
int visited[MAX];
int N, S, E;
bool isfind = false;

void dfs(int s, int res, int maxValue) // 
{
	if(isfind) return;
	if(s == E) {
		isfind = true;
		// cout << ">" << endl;
		// result = min(result, res - maxValue);
		cout << res - maxValue << endl;
		return ;
	}

	visited[s] = 1;

	for(pair<int, int> p : board[s])
	{
		int des  = p.first;
		int value = p.second;

		if(!visited[des])	
			dfs(des, res+value, max(maxValue, value));
	}
}
int main()
{
	fastio;
	cin >> N >> S >> E;
	int x, y, value;
	FOR(i, N-1){
		cin >> x >> y >> value;

		board[x].push_back(make_pair(y, value));
		board[y].push_back(make_pair(x, value));
	}

	dfs(S, 0, 0);

	// cout << result << endl;
	return 0;
}

