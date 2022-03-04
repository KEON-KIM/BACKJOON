// 1719
#include <iostream>
#include <vector>
#include <queue>

#define MAX 201
#define INF 987654321
#define endl '\n'
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int N, M;
vector<pair<int, int>> map[MAX];
pair<int, int> result[MAX][MAX]; // idx, cost
void Print()
{
	FOR(i, N)
	{
		FOR(j, N)
		{
			if(i == j) cout << '-' << " ";
			else cout << result[i][j].first << " ";
		}
		cout << endl;
	}
}
void Dijikstra(int start)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pQue; // <cost, <start,pos>> // shortest distance 
	pQue.push({0, {start, start}});

	while(!pQue.empty())
	{
		int cost = pQue.top().first;
		int root = pQue.top().second.first;
		int pos = pQue.top().second.second;
		pQue.pop();

		for(pair<int, int> p : map[pos])
		{
			int npos = p.first;
			int ncost = p.second;

			if(result[start][npos].second > cost + ncost)
			{
				if(start == pos)
					root = npos;
				pQue.push({cost+ncost, {root, npos}});
				result[start][npos].second = cost+ncost;
				result[start][npos].first = root;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	int x, y, cost;
	FOR(i, M)
	{
		cin >> x >> y >> cost;
		map[x].push_back({y, cost});
		map[y].push_back({x, cost});
	}

	FOR(i, N){
		FOR(j, N) result[i][j].second = INF; // INIT;
		Dijikstra(i);
	}

	Print();

	return 0;
}