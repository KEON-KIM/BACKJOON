//#16917
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <set>

#define MAX 21
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef pair<int, int> pii;

int N, M, result;
char board[MAX][MAX];
vector<pii> Coin;
set<vector<pii>> visited;
int dxdy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs()
{
	queue<pair<int, vector<pii>>> Que;
	Que.push({0, Coin});
	visited.insert(Coin);

	while(!Que.empty())
	{
		int dep = Que.front().first;
		vector<pii> coins = Que.front().second;
		Que.pop();

		FOR(i, 4)
		{
			int fallCnt = 0;
			vector<pii> tmp = coins;
			FOR(j, 2)
			{
				int dx = tmp[j].first + dxdy[i][0];
				int dy = tmp[j].second + dxdy[i][1];

				if(dx < 0 || dy < 0 || dx >= N || dy >= M)
				{
					fallCnt++;
					continue;
				}
				if(board[dx][dy] == '#') continue;

				tmp[j].first = dx;
				tmp[j].second = dy;
			}

			if(fallCnt) // 떨어진게 있을 경우
			{
				if(fallCnt < 2)
					return dep + 1; // 한개만 빠져나갈 곳을 찾은 경우
				
				else
					continue; // 동시에 두개 모두 빠져나갈 경우
			}

			else // 떨어진게 하나도 없을 경우
			{
				set<vector<pii>>::iterator it = visited.find(tmp);
				if(it == visited.end())
				{
					visited.insert(tmp);
					Que.push({dep + 1, tmp});
				}
			}
		}
	}

	return -1; // 모든 곳을 방문했는데도 빠져나갈 곳을 못찾을 경우
}
int main()
{
	int result;
	cin >> N >> M;
	FOR(i, N)
		FOR(j, M)
		{
			cin >> board[i][j];
			if(board[i][j] == 'o'){
				board[i][j] == '.'; // 좌표로 확인
				Coin.push_back({i, j});
			}
		}

	result = bfs();
	if(result > 10) result = -1;
	cout << result << endl;

	return 0;
}