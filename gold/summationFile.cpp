//Huffman coding
#include <iostream>
#include <queue>

#define MAX 1000001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
using namespace std;

typedef long long ll;

int T, N;
ll board[MAX];
int main()
{
	fastio;
	cin >> T;
	FOR(t, T)
	{
		priority_queue<ll, vector<ll>, greater<ll>> pQue;
		ll sum = 0;

		cin >> N;
		FOR(i, N)
		{
			int input;
			cin >> input;
			pQue.push(input);
		}

		while(pQue.size() > 1)
		{
			ll x = pQue.top();
			pQue.pop();
			ll y = pQue.top();
			pQue.pop();
			pQue.push(x + y);
			sum += (x + y);
		}

		cout << sum << endl;
	}
	return 0;
}