#include <iostream>
#include <queue>

#define MAX 201
#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, M, K, result = -1;
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int Hdxdy[8][2] = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
					 {2, 1}, {1, 2}, {2, -1}, {1, -2}};

bool board[MAX][MAX];
bool visited[MAX][MAX][31];
int bfs()
{
	visited[0][0][0] = true;
	queue<pair<pair<int, int>, pair<int, int>>> Que;
	Que.push({{0, 0}, {0, 0}});
	while(!Que.empty())
	{
		int k = Que.front().first.first;
		int val = Que.front().first.second;
		int x = Que.front().second.first;
		int y = Que.front().second.second;
		// cout << x << " / " << y << " : " << k << " | " <<  val << endl;
		Que.pop();

		if(x == N-1 && y == M-1) 
			return val;
		

		if(k < K)
		{
			FOR(i, 8)
			{
				int dx = x + Hdxdy[i][0];
				int dy = y + Hdxdy[i][1];

				if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
				if(visited[dx][dy][k+1] || board[dx][dy]) continue;
				// cout << "!K : "<< k <<"/" << dx << "/" << dy << "/" << val << " : ";
				// cout <<board[dx][dy] << " | " << visited[dx][dy] << endl; 
			
				Que.push({{(k + 1), (val + 1)}, {dx, dy}});
				visited[dx][dy][k+1] = true;
			}
		}
		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			if(board[dx][dy] || visited[dx][dy][k+1]) continue;
			// cout <<"!K : "<< k << "/" << dx << "/" << dy <<"/" << val<< " : ";
			// cout <<board[dx][dy] << " | " << visited[dx][dy] << endl; 
			
			Que.push({{k, (val + 1)}, {dx, dy}});
			visited[dx][dy][k] = true;
		}
	}
	return -1;
}
int main()
{
	cin >> K >> M >> N;
	// Init();
	FOR(i, N)
		FOR(j, M)
			cin >> board[i][j];
	bfs();
	

	cout << result << endl;
	return 0;
}