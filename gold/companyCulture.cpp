#include <iostream>
#include <vector>
#include <queue>

#define MAX 100002
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<int> board[MAX];
int scores[MAX];
void dfs(int n)
{
	for(int next : board[n]){
		scores[next] += scores[n];
		dfs(next);
	}
}
int main()
{
	fastio;
	cin >> N >> M;
	FOR(i, N)
	{
		int root;
		cin >> root;
		if(root > 0)
			board[root].push_back(i);
	}

	FOR(i, M)
	{
		int n, point;
		cin >> n >> point;
		scores[n] += point;
	}

	dfs(1);
	FOR(i, N)
		cout << scores[i] << " ";

	return 0;
}