#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N;
const int MAX = 50 + 1;
const int INF = 2555;
int board[MAX][MAX];
int costs[MAX][MAX];
bool visited[MAX][MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

typedef pair<int, pair<int, int>> pipii;
void print()
{
	FOR(i, N){
		FOR(j, N)
			cout << costs[i][j] << " ";
		cout << endl;
	}
}

int bfs(int startX, int startY)
{
	priority_queue<pipii, vector<pipii>, greater<pipii>> pQue;
	pQue.push({0, {startX, startY}});
	visited[startX][startY] = true;
	costs[startX][startY] = 0;
	while(!pQue.empty())
	{
		int x = pQue.top().second.first;
		int y = pQue.top().second.second;
		int cost = pQue.top().first;
		pQue.pop();

		if(x == N-1 && y == N-1) return cost;
		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];

			if(dx < 0 || dy < 0 || dx >= N || dy >= N || visited[dx][dy]) continue;
			if(costs[dx][dy] > cost)
			{
				visited[dx][dy] = true;
				if(!board[dx][dy]){
					pQue.push({cost + 1, {dx, dy}});
					costs[dx][dy] = cost + 1;
				}
				else{
					pQue.push({cost, {dx, dy}});
					costs[dx][dy] = cost;
				}

			}
		}
	}
	return -1;
}

void Init()
{
	FOR(i, N)
		FOR(j, N)
			costs[i][j] = INF;
}

int main()
{
	cin >> N;
	FOR(i, N)
	{
		string input;
		cin >> input;
		FOR(j, N)
		{
			board[i][j] = input[j] - '0';
		}
	}
	Init();
	cout << bfs(0, 0) << endl;

	return 0;
}