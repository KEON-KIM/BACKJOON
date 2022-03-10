// #1922 // MST/ Kruskal's Algorithm
// @Reference jaimemin <https://jaimemin.tistory.com/802>
#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M;
bool visited[MAX];
vector<pair<int, int>> board[MAX]; // [cur]{cost, next}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQue;
int main()
{

    fastio;
    cin >> N >> M;

    FOR(i, M)
    {
        int a, b, cost; cin >> a >> b >> cost;
        board[a].push_back({ cost, b });
        board[b].push_back({ cost, a });
    }

    pQue.push({ 0, 1 }); // {minCost, cur}
    int result = 0;
    while (!pQue.empty())
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
        		int nextCost = p.first;
        		int next = p.second;

        		if(!visited[next])
        			pQue.push({nextCost, next});
        	}
        }
    }
    cout << result << endl;

    return 0;
}
