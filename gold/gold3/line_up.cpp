// #2252
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 32002
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, M;
vector<int> board[MAX];
vector<int> condi[MAX];
bool isRoot[MAX];
bool visited[MAX] = {false, };
bool isvisited(int x)
{
	FOR(i, condi[x].size())
		if(!visited[condi[x][i]])
			return false;
	return true;
}
int main()
{
	memset(isRoot, true, sizeof(isRoot));
	cin >> N >> M;
	FOR(i, M)
	{
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		condi[b].push_back(a);
		isRoot[b] = false;
	}

	queue<int> Que;
	for(int i = 1; i <= N; i++)
		if(isRoot[i])
		{
			visited[i] = true;
			Que.push(i);
		}
	while(!Que.empty())
	{
		int x = Que.front();
		Que.pop();

		cout << x << ' ';
		FOR(i, board[x].size())
		{
			if(!visited[board[x][i]] && isvisited(board[x][i]))
			{
				visited[board[x][i]] = true;
				Que.push(board[x][i]);
			}
		}
	}

	return 0;
}