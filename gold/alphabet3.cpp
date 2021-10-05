#include<stack>
#include<string>
#include<iostream>

using namespace std;

char board[20][20];
bool visit[26] ={false,};
int N,M, cmp;

void dfs(int x, int y, int result)
{
	int dx,dy;
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	for(int i = 0; i < 4; i++)
	{
		dx = x + dxdy[i][0];
		dy = y + dxdy[i][1];

		if(dx >= 0 && dx < N && dy >= 0 && dy < M)
		{
			if(!visit[board[dx][dy] - 'A']){
				visit[board[dx][dy] - 'A'] = true;
				dfs(dx,dy,result+1);
				visit[board[dx][dy] - 'A'] = false;
			}
			else {
				if(result > cmp)cmp = result;
			}
		}
	}
}
int main()
{
	string line;

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> line;
		for(int j = 0; j < M; j++)
		{
			board[i][j] = line[j];
		}
	}

	visit[board[0][0] - 'A'] = true;
	dfs(0,0,1);
	
	cout << cmp << endl;

	return 0;
}
