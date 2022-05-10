#include <iostream>
#include <vector>
#include <queue>

#define MAX 1002
#define INF 100000000001;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
bool visited[MAX];
vector<pii> board[MAX];
void Prim(int start)
{
	ll result = 0;
	int maxRoad = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pQue;
	pQue.push({0, start}); // cost, index;

	while(!pQue.empty())
	{
		int cost = pQue.top().first;
		int cur = pQue.top().second;
		pQue.pop();

		if (!visited[cur])
        {
        	visited[cur] = true;
        	result += cost;
        	for(pair<int, int> p : board[cur])
        	{
        		int next = p.second;
        		int nextCost = p.first;

        		if(!visited[next])
        			pQue.push({nextCost, next});
        	}
        }
	}
	cout << result << endl;
}
int main()
{
	fastio;
	cin >> N;
	FOR(i, N)
	{
		int cost;
		FOR(j, N)
		{
			cin >> cost;
			if(i < j)
			{
				board[i].push_back({cost, j});
				board[j].push_back({cost, i});
			}
		}
	}

	Prim(1);

	return 0;
}