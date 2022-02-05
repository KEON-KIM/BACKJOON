//#7569
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 101
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int N, M, H, tomato = 0, result = 0;
int board[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int dxdy[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};


struct data
{
	int x, y, z, day;
	data(int a, int b, int c, int d)
	{
		x = a;
		y = b;
		z = c;
		day = d;
	}
};
vector<data> starting;
void bfs(int a, int b, int c, int d)
{
	queue<data> Que;
	Que.push(data(a, b, c, d));
	visited[a][b][c]  = true;

	while(!Que.empty())
	{
		int x = Que.front().x;
		int y = Que.front().y;
		int z = Que.front().z;
		int day = Que.front().day;
		Que.pop();

		for(int i = 0; i < 6; i++)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];
			int dz = z + dxdy[i][2];

			if(!tomato){
				result = day;
				return;
			} 
			if(dx < 0 || dy < 0 || dz < 0 || dx >= N || dy >= M || dz >= H) continue;
			if(visited[dx][dy][dz] || board[dx][dy][dz] == -1) continue;

			visited[dx][dy][dz] = true;
			tomato--;

			Que.push(data(dx, dy, dz, day + 1));
		}
	}
}
int main()
{
	cin >> M >> N >> H;
	FOR(i, H)
		FOR(j, N)
			FOR(k, M){
				cin >> board[i][j][k];
				if(!board[i][j][k]) tomato++;
				else starting.push_back(data(i, j, k, 0));
			}
	int cmp = 0;
	bool flag = false;
	if(!tomato){
		cout << cmp << endl;
		return 0;
	}

	FOR(i, starting.size()){
		int tmp = tomato;
		result = 0;
		memset(visited, false, sizeof(visited));
		bfs(starting[i].x, starting[i].y, starting[i].z, starting[i].day);
		if(!tomato){
			cmp = min(cmp, result);
			flag = true;
		}
		tomato = tmp;
	}
	if(flag)
		cout << cmp << endl;
	else
		cout << -1 << endl;

	return 0;
}