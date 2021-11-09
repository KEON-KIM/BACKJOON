// #14500
#include<iostream>

using namespace std;

int N, M, result = 0;
int board[502][502];

int rominoes[20][3][2] = {
// ㅡ	
	{{1,0}, {1,0}, {1,0}}, 
	{{0,-1}, {0,-1}, {0,-1}},
	{{-1,0}, {-1,0}, {-1,0}},
	{{0,1}, {0,1}, {0,1}},
// ㄱ
	{{0,1}, {1,0}, {1,0}},
	{{1,0}, {0,-1}, {0,-1}},
	{{0,-1}, {-1,0}, {-1,0}},
	{{-1,0}, {0,1}, {0,1}},
//ㅜ 
	{{0,1}, {0,1}, {1,-1}},
	{{1,0}, {1,0}, {-1,-1}},
	{{0,-1}, {0,-1}, {-1, 1}},
	{{-1,0}, {-1,0}, {1,1}},
//ㄹ
	{{1,0}, {0,1}, {1,0}},
	{{0,-1}, {-1,0}, {0,-1}},
	{{-1,0}, {0,1}, {-1,0}},
	{{0,1}, {1,0}, {0,1}},
//ㅁ
	{{0,1}, {1,0}, {0,-1}},
	{{1,0}, {0,-1}, {-1,0}},
	{{0,-1}, {-1,0}, {0,1}},
	{{-1,0}, {0,1}, {1,0}}
};

void tetris(int x, int y)
{
	int tmp_x, tmp_y, total;

	for(int i = 0; i < 20; i++)
	{	
		for(int j = 0; j < 2; j++)
		{
			tmp_x = x;
			tmp_y = y;
			total = board[x][y];
			cout << "========CUR : " << total << " =======" <<i<< "=====" << endl;
			for(int k = 0; k < 3; k++)
			{
				if(!j){
					tmp_x += rominoes[i][k][0];
					tmp_y += rominoes[i][k][1];
					if(tmp_x >= 0 && tmp_y >= 0 && tmp_x < N && tmp_y < M){
						cout <<board[tmp_x][tmp_y]<< endl;
						total += board[tmp_x][tmp_y];
					}
					
					else break;
				}

				else
				{
					tmp_x += rominoes[i][k][0];
					tmp_y -= rominoes[i][k][1];
					if(tmp_x >= 0 && tmp_y >= 0 && tmp_x < N && tmp_y < M){
						cout <<board[tmp_x][tmp_y]<< endl;
						total += board[tmp_x][tmp_y];
					}
					
					else break;
				}
			}
			result = max(total, result);
			cout << "========TOTAL : " << total << " =============" << endl;
		}
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 0 ; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> board[i][j];
		
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			tetris(i, j);

	cout << result << endl;
	return 0;
}