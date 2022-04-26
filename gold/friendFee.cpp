#include <iostream>
#include <vector>
#include <queue>

#define MAX 10002
#define RES "Oh no"
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;
typedef pair<int, int> pii;

int N, M, C;
bool visited[MAX];
int costs[MAX];
vector<int> board[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pQue;

void dfs(int idx)
{
	visited[idx] = true;
	for(int next : board[idx])
		if(!visited[next])
			dfs(next);
}

int main()
{
	int result = 0;
	cin >> N >> M >> C;
	FOR(i, N){
		cin >> costs[i];
		pQue.push({costs[i], i});
	}

	FOR(i, M)
	{
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}

	while(!pQue.empty())
	{
		int cost = pQue.top().first;
		int idx = pQue.top().second;
		pQue.pop();

		if(!visited[idx])
		{
			result += cost;
			dfs(idx);
		}
	}

	if(result > C)
		cout << RES;
	else
		cout << result << endl;
	return 0;
}