//#1949

#include <iostream>
#include <vector>
#include <queue>

#define MAX 10001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
 
int N;
int dp[10001][2];
int board[10001];
vector<int> graph[10001];
bool visited[10001] = {false, };
 
void dfs(int cur)
{
    visited[cur] = true;
    
    dp[cur][0] = 0;
    dp[cur][1] = board[cur];
    
    for(int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if(visited[next]) continue;
        dfs(next);
        
        dp[cur][0] += max(dp[next][0], dp[next][1]);
        dp[cur][1] += dp[next][0];
    }
}

int main()
{
	fastio;
	int u, v;
    cin >> N;
    FOR(i, N) cin >> board[i];
   	FOR(i, N-1)
   	{
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }

    dfs(0);
    cout << max(dp[0][0], dp[0][1]);
    return 0;
}
