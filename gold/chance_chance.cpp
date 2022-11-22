#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 102
#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;
int N, M, total = 0;
int board[MAX][MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pii> dist[10002]; // 총 만개의 노드가 생성될 수 있다.
int bfs(pair<int, int> start, pair<int, int> finish)
{
	bool visited[MAX][MAX];
	memset(visited, false, sizeof(visited));
	queue<pair<int, pair<int, int>>> Que;
	Que.push({0, start});
	// cout << "sTART : " << start.first << "/" << start.second <<endl;
	visited[start.first][start.second] = true;
	while(!Que.empty())
	{
		int move = Que.front().first;
		int x = Que.front().second.first;
		int y = Que.front().second.second;
		// cout << "X : " << x <<" Y : " << y << endl;
		Que.pop();

		if(x == finish.first && y == finish.second)
			return move;
		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];
			// cout << dx << "/" << dy << endl;
			if(dx < 0 || dy < 0 || dx >= N || dy >= M) {continue;}
			if(visited[dx][dy] || board[dx][dy] == 1) {continue;}
			// cout << '!' << endl;
			Que.push({move+1, {dx, dy}});
			visited[dx][dy] = true;
		}
	}

	return -1;
}
int solution()
{
	cin >> N >> M;
	vector<pii> gold;
	FOR(i, N)
		FOR(j, M)
		{
			cin >> board[i][j];
			if(board[i][j] == 2)
				gold.push_back({i, j});
		}

	int x, y;
	cin >> x >> y;
	int s = gold.size();
	FOR(i, gold.size())
	{
		int start_dist = bfs({0, 0}, gold[i]);
		int finish_dist = bfs(gold[i], {x-1, y-1});

		if(start_dist == -1 || finish_dist == -1) 
			return -1;
		total += start_dist;
		total += finish_dist;
		dist[0].push_back({start_dist, i+1});
		dist[i+1].push_back({finish_dist, s+1});
		dist[gold.size()+1].push_back({finish_dist, i+1});
	}

	FOR(i, gold.size()){
		FOR(j, gold.size()){
			if( i == j ) continue;
			int tmp = bfs(gold[i], gold[j]);

			if(tmp == -1){
				return -1;
			}
			total += tmp;
			dist[j+1].push_back({tmp, i+1});
		}
	}
	FOR(i, gold.size()+1){
		FOR(j, dist[i].size())
		{
			cout <<" I : " << i << "  || "<< dist[i][j].first << " / " << dist[i][j].second << endl;
		}
	}

	int answer = Prim();
	return answer;
}

int main()
{
	cout << solution();
	return 0;
}

// Input_1
/*3
3
0 1 0
1 0 1
0 2 2
1
1*/


// Input_2
// 5
// 7
// 0 0 2 1 0 2 1
// 0 1 1 1 0 0 1
// 0 0 0 0 2 1 1
// 1 1 0 1 0 1 0
// 0 2 0 1 0 0 0
// 5
// 7