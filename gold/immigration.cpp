//#3079

#include<iostream>
#include<cmath>

#define MAX 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;
ll N, M;
ll board[MAX], minist = pow(10, 9);
int main()
{
	fastio;
	cin >> N >> M;
	FOR(i, N)
	{
		cin >> board[i];
		minist = min(minist, board[i]);
	}

	ll l = 0, r = minist * M, result = r;
	while(l <= r)
	{
		ll tmp_cnt = 0;
		ll _time = (l + r)/2;
		
		if(l == _time || r == _time) break;
		FOR(i, N)
			tmp_cnt += (_time-(_time%board[i]))/board[i];

		if(tmp_cnt >= M){
			r = _time;
			result = min(result, _time);
		}
		else
			l = _time;

	}

	cout << result << endl;
	return 0;
}