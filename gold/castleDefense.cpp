#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 17
#define INF 987654321
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, M, T;
int last = 0, result = 0;
const int archer_cnt = 3;
int archer[MAX];
int temp[MAX][MAX];
int map[MAX][MAX];
vector<pair<int, int>> tmpQue;
queue<pair<int, pair<int, int>>> Que; //{Turn, {x, y}}
/*int bfs()
{
	
	int res = 0;
	int worldTurn = -1;
	int tmp[MAX];
	int board[MAX][MAX];
	while(!Que.empty())
	{
		bool isDead = false;
		int turn = Que.front().first;
		int x = Que.front().second.first; // not dx : after archers attact enemy
		int y = Que.front().second.second;
		Que.pop();
		if(worldTurn != turn)
		{
			FOR(i, M)
				tmp[i] = archer[i];
			worldTurn = turn;
		}
		if(worldTurn != turn){ // when new turn start, reset isAttack of archer : archer[MAX]
			cout << "============" << endl;
			memset(board, 0, sizeof(board));
			FOR(i, M)
			{
				tmp[i] = archer[i];
				cout << tmp[i] << " ";
			}
			cout << endl;
			board[x][y] = 1;
			int size = Que.size();
			cout << "===board==== res : "<< res << endl;
			FOR(i, size)
			{
				int a = Que.front().second.first;
				int b = Que.front().second.second;
				Que.pop();
				board[a][b] = 1;
				Que.push({turn, {a, b}});
			}
			FOR(i, N){
				FOR(j, M)
					cout << board[i][j] << " ";
				cout << endl;
			}
			worldTurn = turn;
		}
		cout << turn << "|" << x << "|" << y << endl;
		int mindist = INF;
		int index = 0;
		int overlap = 0;
		FOR(i, M)
		{
			if(tmp[i]) // each archer attact enemy
			{
				int distance = (abs(0 - x) + abs(i - y));
				if(x && distance <= T) 
				{
					if(distance < mindist)
					{
						mindist = distance;
						index = i;
						isDead = true;
					}
				}
			}
		}

		if(isDead) 
		{
			res++;
			tmp[index] = 0;
			continue;
		}
		if(x - 1 < 0 ) continue;
		Que.push({turn+1, {x-1, y}});
	}
	return res;
}*/
void print()
{
	cout << "===== PRINT =====" << endl;
	FOR(i, N){
		FOR(j, M)
			cout << map[i][j] << " ";
		cout << endl;
	}
}
int play()
{
	int res = 0;
	FOR(t, N) // turn;
	{
		print();
		//attack
		vector<pair<int, int>> cache;
		FOR(i, M)
		{
			if(archer[i])
			{
				int mindist = INF;
				pair<int, int> minIdx;
				FOR(j, N)
					FOR(k, M)
						if(map[j][k])
						{
							// if(j == 1 && k == 2) cout << "FUCK" << endl;
							int distance = (abs(0 - j) + abs(i - k));
							if(mindist >= distance && distance <= T)
							{
								if(mindist == distance && minIdx.second > k)
								{
									cout << "DISTANCE=1 ["<< i <<"] : " << distance << " pos : " << j << "/" << k << endl;
									minIdx = {j, k};
								}
								else if(mindist > distance)
								{
									cout << "DISTANCE ["<< i <<"] : " << distance << " pos : " << j << "/" << k << endl;
									mindist = distance;
									minIdx = {j, k};
								}

							}
						}

				cache.push_back(minIdx);
			}
		}
			for(pair<int, int> p : cache)
			{
				if(map[p.first][p.second] && p.first && p.second)
					res++;
				// cout << p.first << "/" << p.second << endl;
				map[p.first][p.second] = 0;
			}
		
		// move
		FOR(i, N)
			FOR(j, M)
				temp[i][j] = (i < N - t + 1)? map[i+1][j] : 0;	
		
			
		FOR(i, N)
			FOR(j, M)
				map[i][j] = temp[i][j];
		
	}
	return res;
}

void Reset()
{
	memset(map, 0, sizeof(map));
	for(pair<int, int> p : tmpQue)
		map[p.first][p.second] = 1;
}

void batch(int depth,int end)// all batch cases
{
	if(depth==end) // archer count
	{
		cout << "======= RESET ======= result :" << result << endl;
		FOR(i, M)	
			cout << archer[i] << " ";
		cout << endl;
		result = max(result, play());
		Reset();
	}

	else
	{
		int tmp = last;
		for(int i = last + 1; i <= M; i++)
		{
			archer[i] = 1;
			last = i;
			batch(depth+1, end);
			last = tmp;
			archer[i] = 0;
		}
	}
}

void reverse()
{
	FOR(i, N)
	{
		FOR(j, M)
		{
			map[i][j] = temp[N-i+1][j];
			if(map[i][j])
				tmpQue.push_back({i, j});
		}
	}
}

int main()
{
	cin >> N >> M >> T;

	FOR(i, N)
		FOR(j, M)
			cin >> temp[i][j];

	reverse();
	batch(0, archer_cnt);
	cout << result << endl;

	return 0;
}