//#5972
//Algorithm : Dijiksta Algorithm

#include<iostream>
#include<queue>
#include<vector>

#define MAX 50010
#define INF 999999999
#define FOR(i, n) for(int i = 1; i <= n; i++) 
using namespace std;

int N, M, Distance[MAX];
vector<pair<int, int>> map[MAX];

int Dijikstra(int start)
{
	Distance[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
	PQ.push(make_pair(start, Distance[start]));

	while(!PQ.empty())
	{
		int cur = PQ.top().first;
		int dis = PQ.top().second;
		PQ.pop();

		for(int i = 0; i < map[cur].size(); i++)
		{
			int next = map[cur][i].first;
			int _distance = map[cur][i].second;

			if(_distance + Distance[cur] < Distance[next])
			{
				Distance[next] = _distance + Distance[cur];
				PQ.push(make_pair(next, _distance)); 
			}
		}
	}

	return Distance[N];
}

void init()
{
	FOR(i, M)
		Distance[i] = INF;
}

int main()
{
	cin >> N >> M;
	FOR(i, M){
		int x, y, cost;
		cin >> x >> y >> cost;
		map[x].push_back(make_pair(y, cost));
		map[y].push_back(make_pair(x, cost));
	}

	init();
	cout << Dijikstra(1) << endl;

	// cout << Distance[N] << endl;
	return 0;
}