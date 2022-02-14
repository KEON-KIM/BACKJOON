//#2194
#include<iostream>
#include<queue>

#define FOR(i, n) for(int i = 1; i <= n; i++)
#define MAX 501
using namespace std;

int N, M, A, B, K, result = -1;
int dxdy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
bool visited[MAX][MAX], board[MAX][MAX];
pair<int, int> dest;
pair<int, int> cur;

bool isMove(int x, int y)
{
	for(int i = x; i < x + A ; i++)
		for(int j = y; j < y + B; j++)
			if(i <= 0 || j <= 0 || i > N || j > M || board[i][j]) return false;

	return true;
}

void bfs(pair<int, int> start)
{
	queue<pair<pair<int, int>, int>> Que;
	if(isMove(start.first, start.second))
		Que.push(make_pair(start, 0));

	while(!Que.empty())
	{
		int x = Que.front().first.first;
		int y = Que.front().first.second;
		int moveCnt = Que.front().second;
		Que.pop();

		// cout << "(CURRENT) X : " << x << " Y : " << y << endl;  

		if(x == dest.first && y == dest.second)
		{
			result = moveCnt;
			return;
		}
		FOR(i, 4)
		{
			int dx = x + dxdy[i-1][0];
			int dy = y + dxdy[i-1][1];
			int maxDx = dx + A - 1;
			int maxDy = dy + B - 1;
			
			if(dx <= 0 || dy <= 0 || dx > N || dy > M || visited[dx][dy] || maxDx > N || maxDy > M)
			{
				// cout << "X : " << dx << " Y : " << dy << endl;
				continue;
			}	

			if(!isMove(dx, dy)) continue;
			Que.push(make_pair(make_pair(dx, dy), moveCnt+1));
			visited[dx][dy] = true;
		}
	}
}
void Input()
{	
	int x, y;
	cin >> N >> M >> A >> B >> K;

	FOR(i, K)
	{
		cin >> x >> y;
		board[x][y] = true;
	}
	cin >> cur.first >> cur.second;
	cin >> dest.first >> dest.second;
}

int main()
{
	Input();
	bfs(cur);

	cout << result << endl;
	return 0;
}