//#21610
#include<iostream>
#include<queue>
#include<vector>

#define MAPSIZE 51
#define CMDSIZE 102
#define FOR(i, n) for(int i = 1; i <= n; i++)

using namespace std;

int N, M;
int board[MAPSIZE][MAPSIZE][2], command[CMDSIZE][2];
int dxdy[9][2] = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int rain[4][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

vector<pair<int, int>> cloud[CMDSIZE];
void print()
{
	cout << "=======PRINT=======" << endl;
	FOR(i, N){
		FOR(j, N)
			cout << board[i][j][0] << " ";
		cout << endl;
	}
}

pair<int, int> move(int x, int y, int dir, int cnt)
{
	int dx = x + dxdy[dir][0] * cnt;
	int dy = y + dxdy[dir][1] * cnt;

	dx = dx > N ? dx%N : dx;
	dx = dx < 1 ? N + (dx%N) : dx;
	dy = dy > N ? dy%N : dy;
	dy = dy < 1 ? N + (dy%N) : dy;

	board[dx][dy][0] += 1;
	board[dx][dy][1] = 1;
	return make_pair(dx, dy);
}

void isRainning(pair<int, int> p)
{
	for(int i = 0; i < 4; i++){
		int x = p.first + rain[i][0];
		int y = p.second + rain[i][1];

		if (x < 1 || x > N || y < 1 || y > N) continue;
		if(board[x][y][0])
			board[p.first][p.second][0] += 1;
	}
}

void cloudMove(int cnt, int dir, int cmdCnt)
{
	for(int i = 0; i < cloud[cmdCnt].size(); i++)
		cloud[cmdCnt][i] = move(cloud[cmdCnt][i].first, cloud[cmdCnt][i].second, dir, cnt);

	for(int i = 0; i < cloud[cmdCnt].size(); i++)
		isRainning(cloud[cmdCnt][i]);
}

void solution()
{
	for(int i = 1; i <= M; i++)
	{
		int direction = command[i][0];
		int moveCnt = command[i][1];

		
		if(i == 1){
			cloud[i].push_back(make_pair(N, 1));
			cloud[i].push_back(make_pair(N, 2));
			cloud[i].push_back(make_pair(N-1, 1));
			cloud[i].push_back(make_pair(N-1, 2));
		}

		cloudMove(moveCnt, direction, i);

		// for(int j = 1; j <= N; j++)
		// 	for(int k = 1; k <= N; k++)
		FOR(j, N)
			FOR(k, N)
				if(board[j][k][0] >= 2 && !board[j][k][1]){
					board[j][k][0] -= 2;
					cloud[i+1].push_back(make_pair(j, k));
				}
		
		for(int j = 0; j < cloud[i].size(); j++)	
			board[cloud[i][j].first][cloud[i][j].second][1] = 0;
	}
}

int main()
{
	int result = 0;
	cin >> N >> M;
	FOR(i, N)
		FOR(j, N)
			cin >> board[i][j][0];

	FOR(i, M)
		cin >> command[i][0] >> command[i][1];
	
	
	solution();

	FOR(i, N)
		FOR(j, N)
			result+= board[i][j][0];

	cout << result << endl;
	return 0;
}