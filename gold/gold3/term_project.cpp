//#9466 / DFS
// @Reference jaimemin <https://jaimemin.tistory.com/674>

#include <iostream>
#include <cstring>

#define MAX 100002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef long long ll;
int T, N, result, term_info[MAX];
bool visited[MAX] = {false, };
bool isdefine[MAX] = {false, };

void dfs(int cur)
{
	visited[cur] = true;
	int next = term_info[cur];
	if(!visited[next])
		dfs(next);
	else if(!isdefine[next])
	{
		for(int i = next; i != cur; i = term_info[i])
			result++;
		result++;
	}
	isdefine[cur] = true;
}

int main()
{
	fastio;
	cin >> T;
	FOR(t, T)
	{
		result = 0;
		memset(visited, false, sizeof(visited));
		memset(isdefine, false, sizeof(isdefine));
		cin >> N;

		for(int i = 1; i <= N; i++)
			cin >> term_info[i];

		for(int i = 1; i <= N; i++)
			if(!visited[i])
				dfs(i);

		cout << N - result << endl;
	}
	return 0;
}

/*
void dfs(int cur)
{
	
	if(visited[cur])
	{
		flag = true;
		temp = cur;
		isCycle[cur] = true;
		return;
	}if(isCycle[cur]) return;

	isCycle[cur] = true;
	visited[cur] = true;
	dfs(term_info[cur]);
	visited[cur] = false;
	if(!flag) {isCycle[cur] = false; isdefine[cur] = true;}
	if(temp == cur) // find Cycle
	{
		// cout << "FUCK : " << temp << endl;
		flag = false;
	}
}*/