// #1715
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, res = 0, answer = 0, chk;
int main()
{
	priority_queue<int, vector<int>, greater<int>> pQue;

	fastio;
	cin >> N;
	FOR(i, N)
	{
		int input; cin >> input;
		pQue.push(input);
	}

	int res = pQue.top();
	pQue.pop();
	while(!pQue.empty())
	{
		res += pQue.top();
		pQue.pop();
		answer += res;
		if(res > pQue.top() && pQue.size() > 1)
		{
			pQue.push(res);
			res = pQue.top();
			pQue.pop();
		}
	}

	cout << answer << endl;

	return 0;
}