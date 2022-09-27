//#16236
//@Reference chanhuiseok <https://chanhuiseok.github.io/posts/baek-21/>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 31
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int N, state, eat;
int board[MAX][MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pii> fish[7];
bool eat_fish[MAX][MAX];
int bfs(int start_x, int start_y, int dest_x, int dest_y)
{
	queue<pipii> Que;
	Que.push({0, {start_x, start_y}});
	bool visited[MAX][MAX] = {false, };

	visited[start_x][start_y] = true;
	while(!Que.empty())
	{
		int move = Que.front().first;
		int x = Que.front().second.first;
		int y = Que.front().second.second;
		Que.pop();

		if(x == dest_x && y == dest_y) return move;
		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
			if(board[dx][dy] > state) continue;
			if(!visited[dx][dy])
			{
				visited[dx][dy] = true;
				Que.push({move+1, {dx, dy}});
			}
		}
	}

	return -1;
}
void print()
{
	cout << "===================" << endl;
	FOR(i, N){
		FOR(j, N)
			cout << board[i][j] << ' ';

		cout << endl;
	}
}
int main()
{
	fastio;
	cin >> N;
	queue<pii> Que;
	FOR(i, N)
		FOR(j, N)
		{
			cin >> board[i][j];
			if(!board[i][j]) continue;
			if(board[i][j] == 9) Que.push({i, j});
			else
				fish[board[i][j]].push_back({i, j});
		}

	int answer = 0;
	state = 2; eat = 0;
	while(!Que.empty())
	{
		int x = Que.front().first;
		int y = Que.front().second;
		Que.pop();
		board[x][y] = 0;
		priority_queue<pipii, vector<pipii>, greater<pipii>> pQue;
		FOR(i, state)
		{
			FOR(k, fish[i].size())
			{
				int dx = fish[i][k].first;
				int dy = fish[i][k].second;

				if(eat_fish[dx][dy]) continue;
				int res = bfs(x, y, dx, dy);

				if(res != -1)
					pQue.push({res, {dx, dy}});
			}
		}
		/*priority_queue<pipii, vector<pipii>, greater<pipii>> pQue2;
		while(!pQue.empty())
		{
			int move = pQue.top().first;
			int dx = pQue.top().second.first;
			int dy = pQue.top().second.second;
			pQue.pop();
			cout << "MOVE : " << move << " DX : " << dx << " DY : " << dy << endl;
			pQue2.push({move, {dx, dy}});
		}*/
		if(!pQue.empty())
		{
			int move = pQue.top().first;
			int dx = pQue.top().second.first;
			int dy = pQue.top().second.second;
			// cout << "next : " << dx << "/" << dy << endl;
			eat_fish[dx][dy] = true;
			answer += move;
			if(++eat/ state)
			{
				state < 7? state++ : state;
				eat = 0;
			}
			Que.push({dx, dy});
		}
	}
	cout << answer;
	return 0;
}