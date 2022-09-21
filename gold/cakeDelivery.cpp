#include <iostream>
#include <cstring>

#define MAX 10001
#define INF 200000
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N;
int dp[MAX];
pii board[MAX];
pii startPoints;
int dfs(pii cur, int idx)
{
	int &ref = dp[idx];
	if(ref != -1) return 0;
	if(idx == N-1) return abs(cur.first - board[idx].first) + abs(cur.second - board[idx].second);
	
	int result = INF;
	result = min(result, (abs(cur.first - board[idx].first) + abs(cur.second - board[idx].second))
	 + dfs({board[idx].first, board[idx].second}, idx+1));
	result = min(result, (abs(cur.first - board[idx].first + 1) + abs(cur.second - board[idx].second))
	 + dfs({board[idx].first+1, board[idx].second}, idx+1));
	result = min(result, (abs(cur.first - board[idx].first - 1) + abs(cur.second - board[idx].second))
	 + dfs({board[idx].first-1, board[idx].second}, idx+1));
	result = min(result, (abs(cur.first - board[idx].first) + abs(cur.second - board[idx].second + 1))
	 + dfs({board[idx].first, board[idx].second+1}, idx+1));
	result = min(result, (abs(cur.first - board[idx].first) + abs(cur.second - board[idx].second - 1))
	 + dfs({board[idx].first, board[idx].second-1}, idx+1));
	cout << result << endl;
	return ref = result; 

}
int main()
{
	cin >> N;
	cin >> startPoints.first >> startPoints.second;
	FOR(i, N)
	{
		int x, y;
		cin >> x >> y;
		board[i] = {x, y};
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(startPoints, 0);
	return 0;
}