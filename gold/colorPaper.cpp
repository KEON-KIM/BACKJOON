#include <iostream>
#include <algorithm>

#define MAX 1001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, result = 0;
int board[MAX]; // depth check
pair<int, int> number[101]; // colorPaper size

void dfs(int x, int y, int idx, int depth)
{
	result = max(result, depth);
	FOR(i, N)
	{
		if(i == idx) continue;
		if((number[i].first <= x && number[i].second <= y )
			|| (number[i].first <= y && number[i].second <= x))
			if(depth+1 > board[i]){
				board[i] = depth+1;
				dfs(number[i].first, number[i].second, i, depth+1);
			}
	}
}
int main()
{
	cin >> N;
	FOR(i, N)
	{
		int a, b;
		cin >> a >> b;
		board[i] = 1;
		number[i] = make_pair(a, b);
	}
	sort(number, number+N, greater<pair<int, int>>());

	FOR(i, N)
	{
		int x = number[i].first;
		int y = number[i].second;
		dfs(x, y, i, 1);
	}
	cout << result;
	return 0;
}