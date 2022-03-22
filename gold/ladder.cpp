// #15684
// @Reference yabmoons <https://yabmoons.tistory.com/47>
#include <iostream>

#define INF 987654321
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, M, H, result = INF;
int ladders[11][31];
bool visited[11][31]; // max 30, height += 1

bool dia()
{
	FOR(i, N)
	{
		int num = i;
		FOR(j, H)
		{
			if(visited[num][j]) // right move
				num = num + 1;
			else if (visited[num-1][j]) // left move
				num = num - 1;
		}

		if(num != i) return false;
	}
	return true; 
}

void dfs(int idx, int cnt)
{
	if(cnt > 3) return ; // when put a line into map, max count is 3  
	if(dia())
	{
		result = min(result, cnt);
		return;
	}
	for(int i = idx; i <= H; i++)
	{
		for(int j = 1; j < N; j++)
		{
			if(visited[j][i]) continue;
			if(visited[j-1][i]) continue;
			if(visited[j+1][i]) continue;

			visited[j][i] = true;
			dfs(i, cnt + 1);
			visited[j][i] = false;
		}
	}
}

int main()
{
	cin >> N >> M >> H;
	FOR(i, M)
	{
		int x, y; 
		cin >> x >> y;
		visited[y][x] = true;
	}

	dfs(1, 0);

	if(result == INF) result = -1;
	cout << result << endl;

	return 0;
}

/*#include <iostream>

#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, M, T, result = 0;
int ladders[11];
bool visited[31][11];
vector<int> board[11];

bool dia(int idx)
{
	vector<int > A, B;
	for(int i = 0; i < board[idx].size(); i++){
		A.push_back(board[idx][i]);
		if(visited[board[idx][i]][idx-1])
			return false;
	}
	for(int i = 0; i < board[idx].size(); i++){
		A.push_back(board[idx][i]);
		if(visited[board[idx][i]][idx-1])
			return false;
	}
	
}

bool dfs(int idx)
{
	if(idx == N + 1) return true;
	if(ladders[idx]%2)
	{
		FOR(i, N+1)
		{
			if(!visited[i][idx] && dia(idx))
			{
				visited[i][idx] = true;
				result++;
				dfs(idx+1);
				result--;
				visited[i][idx] = false;
			}
		}
	}
	else
	{
		if(dia(idx))
			dfs(idx+1);
		else
			return false;
	}
}

int main()
{
	cin >> N >> M >> T;
	FOR(i, M)
	{
		int x, y; cin >> x >> y;
		board[y].push_back(x);
		ladders[y]++

		visited[x][y] = true;
		// if(y + 1 < N) visited[x][y+1] = true;
		// if(y - 1 > 0) visited[x][y-1] = true;
	}
	FOR(i, N)
	{
		if(!visited[i][1])
		{
			result++;
			visited[i][1] = true;
			dfs(2);
			visited[i][1] = false
			result--;
		}
	}
	if(dfs(i))
		cout << -1 << endl;
	else
		cout << result << endl;
	
	return 0;
}*/