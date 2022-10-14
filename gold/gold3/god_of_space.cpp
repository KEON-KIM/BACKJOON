#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

#define endl '\n'
#define MAX 1003
#define INF 1000002

#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

int N, M, K;
pdd board[MAX];
double graph[MAX][MAX];
bool visited[MAX] = {false, };
int main()
{
	fastio;
	int a, b;
	cin >> N >> M;
	FOR(i, N)
	{
		cin >> a >> b;
		board[i] = {a, b};
	}
	FOR(i, N)
	{
		FOR(j, N)
		{
			if(i == j) continue;
			double len = sqrt(pow(board[j].first - board[i].first, 2) + pow(board[j].second - board[i].second, 2));	
			graph[i][j] = len;
		}
	}
	priority_queue<pdi, vector<pdi>, greater<pdi>> pQue;
	double dist[MAX], answer = 0;
	FOR(i, N) dist[i] = INF;
	FOR(i, M)
	{
		cin >> a >> b;
		graph[a][b] = 0;
		graph[b][a] = 0;
	}

	visited[1] = true;
	FOR(i, N) pQue.push({graph[1][i], i});
	while(!pQue.empty())
	{
		double len = pQue.top().first;
		int idx = pQue.top().second;
		pQue.pop();
		
		if(!visited[idx])
		{
			visited[idx] = true;
			answer += len;

			FOR(i, N)
			{
				if(i != idx && !visited[i])
				{
					pQue.push({graph[idx][i], i});
				}
			}
		}
	}
	// FOR(i, N) answer += dist[i];
	round(answer * 100) / 100;
	cout << fixed;
	cout.precision(2);
	cout << answer;

	return 0;
}