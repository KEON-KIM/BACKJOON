#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 51
#define INF 2501
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> pp;

int N;
char board[MAX][MAX];
int dist[MAX][MAX];
int dxdy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void Init()
{
	FOR(i, N)
		FOR(j, N) dist[i][j] = INF;
}
vector<int> findDir(pii start)
{
	vector<int> dir;
	FOR(i, 4)
	{
		int dx = start.first + dxdy[i][0];
		int dy = start.second + dxdy[i][1];

		if(dx < 0 || dy < 0 || dx >= MAX || dy >= MAX 
			|| board[dx][dy] == '*') continue;
		dir.push_back(i);
	}

	return dir;
}
void print()
{
	FOR(i, N){
		FOR(j, N)
			cout <<dist[i][j] << " ";
		cout << endl;
	}
}
int bfs(pii start, pii endPoint)
{
	int result;
	queue<pp> Que;
	vector<int> v= findDir(start);
	for(int i : v)
		Que.push({start, i}); // {x, y}, {dir, cnt}

	dist[start.first][start.second] = 0;
	while(!Que.empty())
	{
		int x = Que.front().first.first;
		int y = Que.front().first.second;
		int dir = Que.front().second;
		cout << x <<"/"<< y <<"/"<< dir << endl;
		print();
		Que.pop();

		int dx = x + dxdy[dir][0];
		int dy = y + dxdy[dir][1];
		if(dx < 0 || dy < 0 || dx >= MAX || dy >= MAX) continue;
		if(board[dx][dy] == '*') continue;
		if(board[dx][dy] == '#') dist[dx][dy] = dist[x][y];
		if(board[dx][dy] == '!' && dist[dx][dy] >= dist[x][y]+1)
		{
			if(dir/2) // cur Dir : left, right;
			{
				Que.push({{dx, dy}, 0}); // bottom
				Que.push({{dx, dy}, 1}); // top
			}
			else
			{
				Que.push({{dx, dy}, 2});// right
				Que.push({{dx, dy}, 3});// left
			}
			dist[dx][dy] = dist[x][y] + 1;
		}
		else
		{
			if(dist[dx][dy] >= dist[x][y]){
				Que.push({{dx, dy}, dir});
				dist[dx][dy] = dist[x][y];
			}

		}
	}
	return dist[endPoint.first][endPoint.second];
}
int main()
{
	pii startPoint = {0, 0};
	pii endPoint = {0, 0};
	cin >> N;
	string input;
	Init();
	FOR(i, N)
	{
		cin >> input;
		FOR(j, N){
			board[i][j] = input[j];
			if(input[j] == '#')
			{
				if(!startPoint.first && !startPoint.second)
					startPoint = {i, j};
				else
					endPoint = {i, j};
			}
		}
	}

	cout << bfs(startPoint, endPoint);
	return 0;
}