// #10986	
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MOD 1001
#define MAX 1000002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
using namespace std;

int N, M;
ll board[MAX], psum[MAX], cnt[MOD];
int main()
{
	fastio;
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		cin >> board[i];
		psum[i] = (board[i] + psum[i-1])%M;
		cnt[psum[i]]++;
	}
	
	ll res = 0;
	FOR(i, M)
		res += cnt[i] * (cnt[i] - 1);
	cout << res/2 + cnt[0];
	return 0;
}