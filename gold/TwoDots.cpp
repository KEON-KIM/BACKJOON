#include <iostream>
#include <vector>
#include <cstring>

#define MAX 51
#define ALPHA 26
#define INIT 5
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef pair<int, int> pii;

int N, M, startDir = INIT;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dxdy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

pii goal;
vector<pii> info[ALPHA];
void print()
{
	FOR(i, N){
		FOR(j, M)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
bool dfs(int x, int y, int cnt, int chr) //dir은 dfs가 끝나기 전까지 변하지 않는다.
{
	// cout << x << y << endl;

	FOR(i, 4)
	{
		int dx = x + dxdy[i][0];
		int dy = y + dxdy[i][1];

		if(dx < 0 || dy < 0 || dx >= N || dy >= M){ continue;}
		if((goal.first == x && goal.second == y) && cnt >= 4) return true;
		if(board[dx][dy] != chr || visited[dx][dy]){continue;}
		// cout << "?IDX : " << i  << endl;
		visited[dx][dy] = true;

		if(dfs(dx, dy, cnt+1, chr))
			return true;
	}

	return false;
}
void Init(int i)
{
	for(pii p : info[i])
	{
		int x = p.first;
		int y = p.second;
		visited[x][y] = false;
	}
}
int main()
{
	cin >> N >> M;
	string input;
	FOR(i, N)
	{
		cin >> input;
		FOR(j, M){
			board[i][j] = input[j] - 'A';
			info[board[i][j]].push_back({i, j});
		}
	}
	
	FOR(i, ALPHA)
	{
		for(pii p : info[i]) // 방향 결정을 위해
		{
			Init(i);
			int x = p.first;
			int y = p.second;
			if(!visited[x][y])
			{
				goal = {x, y};
				if(dfs(x, y, 0, i))
				{
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}