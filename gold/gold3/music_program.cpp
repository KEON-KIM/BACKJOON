// #2623
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 1002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
using namespace std;

bool visited[MAX];
int N, M, phase[MAX];
vector<int> graph[MAX];
vector<int> answer;
int main()
{
	cin >> N >> M;
	queue<int> Que;
	FOR(i, M)
	{
		int n, input;
		vector<int> tmp;

		cin >> n;
		FOR(i, n)
		{
			cin >> input;
			tmp.push_back(input);
		} 
		FOR(i, n)
		{
			if(i < n -1)
				graph[tmp[i]].push_back(tmp[i+1]);
			if(i > 0)
				phase[tmp[i]]++;
		}
	}

	for(int i = 1; i <= N; i++)
		if(!phase[i])
			Que.push(i);
	while(!Que.empty())
	{
		int cur = Que.front();
		Que.pop();

		answer.push_back(cur);
		FOR(i, graph[cur].size())
		{
			int next = graph[cur][i];
			if(!--phase[next])
			{
				Que.push(next);
			}
		}
	}
	if(answer.size() == N)
		FOR(i, N)
			cout << answer[i] << endl;
	else
		cout << 0 << endl;
	return 0;
}
