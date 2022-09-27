//#1766
#include <iostream>
#include <vector>
#include <queue>

#define MAX 32002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, M, visited[MAX];
vector<int> result, phase[MAX];
int main()
{
	fastio;
	cin >> N >> M;

	int a, b;
	priority_queue<int, vector<int>, greater<int>> pQue;
	FOR(i, M)
	{
		cin >> a >> b;
		phase[a].push_back(b);
		visited[b]++;
	}

	for(int i = 1; i <= N; i++)
		if(!visited[i])
			pQue.push(i);

	while(!pQue.empty())
	{
		int x = pQue.top();
		result.push_back(x);
		pQue.pop();

		FOR(i, phase[x].size())
		{
			int next = phase[x][i];
			if(!--visited[next])
				pQue.push(next);
		}
	}
	FOR(i, result.size())
	{
		cout << result[i] << ' ';
	}cout << endl;
	return 0;
}