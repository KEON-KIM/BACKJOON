// #11578
#include <iostream>
#include <bitset>
#include <cmath>

#define INF 987654321
#define endl '\n'
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M, result, answer = 987654321;
int board[11];
bool visited[11];

void dfs(int idx, int cnt, bitset<11> sol)
{
	if(sol == result)
	{
		answer = min(answer, cnt);
		return;
	}
	if(cnt == M+1) return;
	for(int i = idx+1; i <= M; i++)
	{
		if(!visited[i])
			dfs(i, cnt+1, (bitset<11> (sol) | bitset<11> (board[i])));
	}
}
int main()
{
	fastio;
	cin >> N >> M;
	FOR(i, M){
		int n, cnt = 0;
		cin >> n;
		FOR(j, n){
			int value; cin >> value;
			cnt += pow(2, value-1);
		}
		board[i] = cnt;
	}
	result = pow(2, N) - 1;

	FOR(i, M)
		dfs(i, 1, board[i]); // index, curCnt, solve

	if(answer == INF)
		cout << -1 << endl;
	else cout << answer << endl;
	return 0;
}
