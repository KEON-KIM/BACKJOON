//#14940
#include<iostream>
#include<queue>

#define MAX 1001
#define FOR(i, n) for(int i = 0; i < n ;i++)
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
#define endl '\n'

using namespace std;

int N, M;
int board[MAX][MAX];
int dxdy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[MAX][MAX];
pair<int, int> dest;

void bfs(int s_x, int s_y)
{
	queue<pair<int, int>> Que;
	Que.push(make_pair(s_x, s_y));
	visited[s_x][s_y] = true;
	board[s_x][s_y] = 0;
	while(!Que.empty())
	{
		int x = Que.front().first;
		int y = Que.front().second;
		Que.pop();

		for(int i = 0; i < 4; i++)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];
			if(dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
			if(visited[dx][dy] || !board[dx][dy]) continue;

			board[dx][dy] = board[x][y] + 1;
			visited[dx][dy] = true;
			Que.push(make_pair(dx, dy));
		}
	}
}

void print()
{
	FOR(i, N){
		FOR(j, M){
			if(!visited[i][j] && board[i][j])
				cout << -1 << " ";
			else cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cin >> N >> M;

	FOR(i, N)
		FOR(j, M){
			cin >> board[i][j];
			if(board[i][j] == 2) dest = make_pair(i, j);
		}
		
	bfs(dest.first, dest.second);

	print();


	return 0;
}