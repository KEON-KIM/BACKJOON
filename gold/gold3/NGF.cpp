//#17299
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

#define MAX 1000002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RFOR(i, n) for(int i = n-1; i >= 0; i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef pair<int, int> pii;

int N, board[MAX];
int visited[MAX], result[MAX];
int main()
{
	cin >> N;
	FOR(i, N)
	{
		cin >> board[i];
		visited[board[i]]++; // 1 ~ 10^6
	}
	memset(result, -1, sizeof(result));
	stack<pii> St; // {visited[idx], idx}
	RFOR(i, N)
	{
		while(!St.empty() && visited[board[i]] >= St.top().first)
			St.pop();
		
		if(!St.empty()) result[i] = St.top().second;
		St.push({visited[board[i]], board[i]});
	}
	FOR(i, N)
		cout << result[i] << ' ';

	return 0;
}