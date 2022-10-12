//#11437
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define endl '\n'
#define MAX 102
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

struct shark_info
{
	bool islive = false;
	int s, d, z;
	shark_info(int speed, int direct, int size, bool live)
	{
		s = speed;
		d = direct;
		z = size;
		islive = live;
	}
};
int R, C, S;
vector<vector<shark_info>> sharks;
void print()
{
	for(int i = 1; i <= R; i++)
	{
		for(int j = 1; j <= C; j++)
		{
			if(sharks[i][j].islive) cout << "1 ";
			else cout << "0 ";
		}
		cout << endl;
	}
}
vector<vector<shark_info>> Init()
{
	vector<vector<shark_info>> board;
	FOR(i, R+1)
	{
		vector<shark_info> tmp;
		FOR(j, C+1)
			tmp.push_back(shark_info(0, 0, 0, false));
		board.push_back(tmp);
	}
	return board;
}
int main()
{
	int result = 0;
	cin >> R >> C >> S;
	sharks = Init();
	FOR(i, S)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharks[r][c].s = s;
		sharks[r][c].d = d;
		sharks[r][c].z = z;
		sharks[r][c].islive = true;
	}

	FOR(c, C)
	{
		cout << "============== :" << result << endl;
		print();
		int count[MAX][MAX];
		int minR = MAX, size = 0;
		FOR(r, R)
			if(sharks[r][c].islive)
			{
				result += sharks[r][c].z;
				sharks[r][c].islive = false;
				break;
			}

		vector<vector<shark_info>> temp = Init();
		FOR(x, R)
		{
			FOR(y, C)
			{
				shark_info shark = sharks[x][y];
				if(shark.islive)
				{
					cout << "SHARK : " << x << '/' << y << "dir : "<<shark.d <<endl;
					int dx = x, dy = y, dd = shark.d;
					if( shark.d == 1 || shark.d == 2) // R
					{
						int move = abs(shark.s - x + 1) % (R - 1);
						if(shark.d == 1) // 음의 방향
						{
							int rot = (shark.s - x) >= 0 ? ((shark.s - x + 1)/(R-1)) + 1 : 0;
							if(!rot)
							{
								dx = x - shark.s;
							}
							else if(rot%2) // 부호 반대 
							{
								dd = dd == 1? 2 : 1;
								dx = 1 + move;
							}
							else // 부호 그대로
								dx = R - move;
						}

						else // 양의 방향
						{
							int move = abs(shark.s + x - 1) % (R - 1);
							int rot = (shark.s + x) > R ? (x + shark.s - 1) / (R - 1) : 0;
							if(!rot)
							{
								dx = x + shark.s;
							}
							else if(rot%2)
							{
								dd = dd == 1? 2 : 1;
								dx = R - move;
							}

							else
								dx = 1 + move;
						}
					}
					else // C
					{
						if(shark.d == 4) // 음의 방향
						{
							int move = abs(shark.s - y + 1) % (C - 1);
							int rot = (shark.s - y) >= 0 ? ((shark.s - y + 1)/(C-1)) + 1 : 0;
							if(!rot)
							{
								dy = y - shark.s;
							}
							else if(rot%2) // 부호 반대 
							{
								dd = dd == 3? 4 : 3;
								dy = 1 + move;
							}
							else // 부호 그대로 
								dy = C - move;
						}

						else // 양의 방향
						{
							int move = abs(shark.s + y - 1) % (C - 1);
							int rot = (shark.s + y) > C ? (y + shark.s - 1) / (C - 1) : 0;
							if (!rot)
							{
								dy = y + shark.s;
							}
							else if(rot%2)
							{
								dd = dd == 3? 4 : 3;
								dy = C - move;
							}

							else
								dy = 1 + move;
						}
					}
					cout << dx << "/ " << dy << " dir " << dd << endl;
					if(temp[dx][dy].islive) // 움직인 자리에 상어 존재
					{
						if(temp[dx][dy].z < shark.z) 
						{
							temp[dx][dy].s = shark.s;
							temp[dx][dy].d = dd;
							temp[dx][dy].z = shark.z;
						}
					}
					else // 움직인 자리에 상어가 없음 
					{
						temp[dx][dy].islive = true;
						temp[dx][dy].s = shark.s;
						temp[dx][dy].d = dd;
						temp[dx][dy].z = shark.z;
					}
				}
			}
		}
		sharks = temp;
	}

	cout << result;
	return 0;
}