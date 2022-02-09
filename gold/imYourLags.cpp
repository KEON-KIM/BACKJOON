//#17352
#include<iostream>
#include<vector>

#define MAX 300002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, dest = 0;
vector<int> board[MAX];
vector<int> roots;
bool visited[MAX];

void dfs(int idx)
{
	FOR(i, board[idx].size())
	{
		int next = board[idx][i];
		if(visited[next]) continue;
		visited[next] = true;
		dfs(next);
	}

	dest = max(dest, idx);
}

int main()
{
	fastio;
	cin >> N;
	FOR(i, N-2)
	{
		int x, y;
		cin >> x >> y;
		board[x].push_back(y);
		board[y].push_back(x);
	}
	for(int i = 1; i <= N; i++){
		if(board[i].size() == 1)
			roots.push_back(i);
	}
	if(!roots.size())
	{
		cout << N - 1 << " " << N << endl;
		return 0;
	}

	FOR(i, roots.size())
	{
		int start = roots[i];
		if(!visited[start]){
			visited[start] = true;
			dfs(start);
			break;
		}
	}

	for(int i = 1; i <= N; i++){
		if(!visited[i])
		{
			if(i > dest)
				cout << dest << " " << i << endl;
			else
				cout << i << " " << dest << endl;
			break;
		}
	}

	return 0;
}
