//#1374
#include<iostream>
#include<algorithm>
#include<queue>

#define MAX 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int N, rest, result = 0;
pair<ll, ll> board[MAX];
bool visited[MAX];

int main()
{
	fastio;
	cin >> N;
	int input;
	FOR(i, N)
		cin >> input >> board[i].first >> board[i].second;

	sort(board, board+N);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;  
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