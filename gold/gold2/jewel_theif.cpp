// #1202
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 300001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N, K;
int main()
{
	int idx = 0;
	ll answer = 0;

	int knap[MAX];
	pii jewel[MAX];
	priority_queue<int> pQue;

	cin >> N >> K;
	FOR(i, N)
	{
		int w, v;
		cin >> w >> v;
		jewel[i] = {w, v};
	}
	FOR(i, K)
	{
		int weight;
		cin >> weight;
		knap[i] = weight;
	}

	sort(jewel, jewel + N);
	sort(knap, knap + K);
	
	FOR(i, K)
	{
		while(idx < N && knap[i] >= jewel[idx].first)
		{
			pQue.push(jewel[idx].second);
			idx++;
		}
		if(!pQue.empty())
		{
			answer += pQue.top();
			pQue.pop();
		}
	}
	cout << answer;
	return 0;
}