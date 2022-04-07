#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define MAX 501
#define INF LLONG_MAX
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N, M;
bool visited[MAX];
ll dist[MAX];
vector<pair<pii, ll>> board;

void Init()
{
	FOR(i, N)
	{
		dist[i] = INF;
	}
}
void BellmanFord()
{
    dist[1] = 0;
    for(int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            int From = board[j].first.first;
            int To = board[j].first.second;
            int Cost = board[j].second;
 
            if (dist[From] == INF) continue;
            if (dist[To] > dist[From] + Cost) dist[To] = dist[From] + Cost;
        }
    }
 
    for(int i = 0; i < board.size(); i++)
    {
        int From = board[i].first.first;
        int To = board[i].first.second;
        int Cost = board[i].second;
 
        if (dist[From] == INF) continue;
        if (dist[To] > dist[From] + Cost)
        {
            cout << -1 << endl;
            return ;
        }
    }

    for(int i = 2; i <= N; i++){
    	if(dist[i] == INF) cout << -1 << endl;
    	else cout << dist[i] << endl;
    }
}
int main()
{
	cin >> N >> M;
	FOR(i, M)
	{
		int a, b, c;
		cin >> a >> b >> c;
		board.push_back({{a, b}, c}); // {cost, next}
	}
	Init();
	BellmanFord();

	return 0;
}
/*


bool Dijikstra(int start)
{
	bool flag = false;
	dist[start] = 0;
	priority_queue<pli, vector<pli>, greater<pli>> pQue;
	pQue.push({0, start});

	while(!pQue.empty())
	{
		int cur = pQue.top().second;
		int cost = pQue.top().first;
		pQue.pop();

		for(pii p : board[cur])
		{
			int next = p.second;
			int nextCost = p.first;

			if(dist[next] > dist[cur] + nextCost)
			{
				dist[next] = dist[cur] + nextCost;
				if(dist[next] < nextCost) 
					return false;
				
				pQue.push({dist[next], next});
			}
		}
		
	}
	return true;

}
*/