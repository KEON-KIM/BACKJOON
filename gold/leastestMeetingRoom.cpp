#include<iostream>
#include<algorithm>
#include<queue>

#define MAX 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int N, result = 0;
pair<ll, ll> board[MAX];
int main()
{
	cin >> N;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;

	FOR(i, N)
		cin >> board[i].first >> board[i].second;

	sort(board, board+N);
	FOR(i, N){
		if (PQ.size() > 0) {
			if (PQ.top().first > board[i].first)
				result++;
			else
				PQ.pop();
		}
		else
			result++;

		PQ.push(make_pair(board[i].second, board[i].first));
	}

	cout << result << endl;
	return 0;
}