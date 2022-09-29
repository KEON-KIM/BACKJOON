//#2263
//@Reference donggoolosori <https://donggoolosori.github.io/2020/10/15/boj-2263/>
#include <iostream>
#include <cstring>
#include <vector>

#define MAX 100001
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N;
int Index[MAX];
int inOrder[MAX];
int postOrder[MAX];
void dfs(int in_start, int in_end, int post_start, int post_end)
{
	if(in_start > in_end || post_start > post_end) return;
	int root = Index[postOrder[post_end]];
	int l = root - in_start;
	cout << inOrder[root] << ' ';

	dfs(in_start, root - 1, post_start, post_start + l - 1);
	dfs(root + 1, in_end, post_start + l, post_end - 1);
}
int main()
{
	fastio;
	cin >> N;
	FOR(n, N)
	{
		cin >> inOrder[n];
		Index[inOrder[n]] = n;
	}
	FOR(n, N)
		cin >> postOrder[n];

	dfs(1, N, 1, N);
	return 0;
}