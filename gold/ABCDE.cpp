// #13023
// @Reference <https://doorrock.tistory.com/65>

#include<iostream>
#include<vector>
#include<cstring>

#define MAX 2001

using namespace std;

vector<int> board[MAX]; 
int n, m, visited[MAX], result = 0;

void dfs(int x, int cnt)
{
	if(cnt >= 4) {
		result = 1;
		return;
	}

	for(int i : board[x])
		if(!visited[i]){
			if(result) return;

			visited[i] = 1;
			dfs(i, cnt+1);
			visited[i] = 0;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int a, b;

	for(int i = 0; i < m; i++){
		cin >> a >> b;

		board[a].push_back(b);
		board[b].push_back(a);
	}

	for(int i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		dfs(i, 0);
		if(result)
		{
			cout << result << endl;
			return 0;
		}
	}

	cout << result << endl;

	return 0;
}