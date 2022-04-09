//#1939
//@Reference jaimemin <https://jaimemin.tistory.com/710>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
const int MAX = 100000 + 1;

int N, M;
int S, E;
vector<pair<int, int>> board[MAX];
bool visited[MAX];

bool bfs(int cost)
{
    queue<int> Que;

    Que.push(S);
    visited[S] = true;
    while (!Que.empty())
    {

        int cur = Que.front();
        Que.pop();
        if (cur == E)
            return true;

        for(pii p : board[cur])
        {
            int next = p.first;
            int nextCost = p.second;
            if (!visited[next] && cost <= nextCost)
            {
                visited[next] = true;
                Que.push(next);
            }
        }
    }

    return false;
}



int main(void)
{
	fastio;
    cin >> N >> M;

    int maxCost = 0;
    for (int i = 0; i < M; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;

        board[a].push_back({b, cost});
        board[b].push_back({a, cost});
        maxCost = max(maxCost, cost); //최대 중량 업데이트
    }

    cin >> S >> E;

    //이진 탐색
    int low = 0, high = maxCost;
    while (low <= high)
    {
        memset(visited, false, sizeof(visited));

        int mid = (low + high) / 2;
        if (bfs(mid))
            low = mid + 1;

        else
            high = mid - 1;
    }

    cout << high << endl;

    return 0;
}


