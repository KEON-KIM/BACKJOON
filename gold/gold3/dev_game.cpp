// #1516
#include <iostream>
#include <vector>
#include <queue>

#define MAX 502
#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef pair<int, int> pii;

int N;
vector<int> building[MAX];
int main()
{
	queue<int> Que;
	int input, cost, in[MAX] = {0, };
	int dist[MAX], result[MAX] = {0, };
	cin >> N;
	FOR(i, N)
	{
		cin >> dist[i+1];
		while(true)
		{
			cin >> input;
			if(input<0) break;
			building[input].push_back(i+1);
			in[i+1]++;
		}
	}
    
	FOR(i, N)
		if(!in[i+1]) Que.push(i+1);

	while(!Que.empty())
	{
		int cur = Que.front();
		Que.pop();
		result[cur] += dist[cur];
		FOR(i, building[cur].size())
		{
			if(!(--in[building[cur][i]]))
				Que.push(building[cur][i]);
			result[building[cur][i]] = max(result[building[cur][i]], result[cur]);
		}
	}
	FOR(i, N)
		cout << result[i+1] << endl;

	return 0;
}