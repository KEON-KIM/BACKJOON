// #14699
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 5001
#define endl '\n'
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
int board[MAX], result[MAX];
vector<int> path[MAX];
priority_queue <pair<int, int>> pq;
void Input()
{
	cin >> N >> M;

	FOR(i, N){
		cin >> board[i];
		pq.push({board[i], i});
	}

	FOR(i, N) result[i] = 1; // Init
	int x, y;
	FOR(i, M)
	{
		cin >> x >> y;
		if(board[x] > board[y])
			path[y].push_back(x);
		else if(board[x] < board[y])
			path[x].push_back(y);
	}
}

void Solution()
{
	while(!pq.empty())
	{
		int addVal = 0;
		int idx = pq.top().second;
		pq.pop();

		for(int k : path[idx])
			addVal = max(addVal, result[k]);
		
		result[idx] += addVal;
	}

}
int main()
{
	Input();
	Solution();
	FOR(i, N)
		cout << result[i] << endl;

	return 0;
}