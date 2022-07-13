#include <iostream>
#include <string>
#include <queue>
#include <map>

#define MAX 51
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int N, M, K;
int result = -1;
int board[MAX][MAX];
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
map<string, int> visited;
void bfs(int a, int b)
{
	string start = "";
	start += (a + '0');
	start += (b + '0');
	if(visited[start]++) return;
	cout << a << "/" << b << endl;
	queue<pair<pair<int, string>, pair<int, int>>> Que;
	Que.push({{board[a][b], start}, {a, b}});

	while(!Que.empty())
	{
		int x = Que.front().second.first;
		int y = Que.front().second.second;

		int cost = Que.front().first.first;
		string cnt = Que.front().first.second;
		Que.pop();

		if(cnt.length()/2 == K)
		{
			cout << cnt << " : " << cost << endl;
			result = max(result, cost);
			continue;
		}
		FOR(i, 4)
		{
			int dx = x + dxdy[i][0];
			int dy = y + dxdy[i][1];
			string tmp = cnt;
			bool flag = false;
			for(int i = 0; i < cnt.length(); i+=2)
			{
				if(cnt[i] == dx+'0' && cnt[i+1] == dy+'0') 
				{
					flag = true;
					break;
				}
			}
			tmp += dx + '0';
			tmp += dy + '0';
			if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			if(visited[tmp]++) {cout << "VISITED"<<endl;continue;}
			Que.push({{cost+board[dx][dy], tmp}, {dx, dy}});
		}
	}
}
int solution()
{
	FOR(i, N){
		FOR(j, M){
			bfs(i, j);
		}
	}

	return result;
}
int main()
{
	cin >> N >> M >> K;
	FOR(i, N)
		FOR(j, M)
			cin >> board[i][j];
	cout << solution();
	return 0;
}
/*
0 3 5 4 2
1 2 2 1 1
4 1 3 6 3
1 0 9 1 7*/