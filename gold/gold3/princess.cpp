//#1941
#include <iostream>
#include <vector>
#include <queue>

#define MAX 52
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
int result = 0;
char board[5][5];
bool candidate[25] = {false, };
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool bfs()
{
	queue<pii> Que;
	bool visited[5][5] = {false, };
	FOR(i, 25) // 그룹 후보 순회
	{
		if(candidate[i])
		{
			if(Que.empty())
			{
				visited[i/5][i%5] = true;
				Que.push({i/5, i%5}); // {x, y}, cnt;
				break;
			}
		}
	}
	int cnt, move;
	cnt = move = 0;
	while(!Que.empty())
	{
		int x = Que.front().first;
		int y = Que.front().second;
		Que.pop();

		move++;
		if(board[x][y] == 'Y') cnt++;
		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];
			if(dx < 0 || dy < 0 || dx >= 5 || dy >= 5) continue;
			if(visited[dx][dy] || !candidate[5*dx + dy]) continue; // 이미 방문한 노드이거나 후보가 아닌경우
			visited[dx][dy] = true;
			Que.push({dx, dy});
		}
	}
	if(cnt > 3 || move < 7) return false;
	return true;
}
void dfs(int idx, int cnt)
{
	if(cnt == 7)
	{
		if(bfs()) 
		{
			result++;
			/*FOR(i, 25) if(candidate[i]) cout << i << ' ';
			cout << endl;
			FOR(i, 5)
			{
				FOR(j, 5)
				{
					cout << candidate[i*5+j] << ' ';
				}cout << endl;
			}
			cout << "================" << endl;*/
		}
		return;
	}

	for(int i = idx+1; i < 25; i++)
	{
		candidate[i] = true;
		dfs(i, cnt+1);
		candidate[i] = false;
	}
}

int main()
{
	FOR(i, 5)
		FOR(j, 5)
			cin >> board[i][j];

	FOR(i, 25)
	{
		candidate[i] = true;
		dfs(i, 1);
		candidate[i] = false;
	}

	cout << result;
	return 0;
}