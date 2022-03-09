#include <iostream>

#define MAX 1001
#define endl '\n'
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RFOR(i, n) for(int i = n; i > 0; i--)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M;
int X, Y, C;
int command[MAX], board[21][21];
int upDown[4], leftRight[4];
int dxdy[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void print()
{
	FOR(i, 4)
		cout << upDown[i] <<" ";
	cout << endl;
	FOR(i, 4)
		cout << leftRight[i] << " ";
	cout << endl;
}
void dfs(int x, int y, int cnt)
{
	// cout << "========== BEFORE ===========" << endl;
	int dx = x + dxdy[command[cnt]][0];
	int dy = y + dxdy[command[cnt]][1];


	if(dx < 0 || dy < 0 || dx >= N || dy >= M || cnt == C){
		if(cnt + 1 < C) {cout << "!" << endl;dfs(x, y, cnt+1);}
		return;
	}

	/*if(x < 0 || y < 0 || x >= N || y >= M || cnt == C) {
		if(cnt < C)
		{
			cout << x << "/" << y << endl;
			dfs(x + dxdy[command[cnt-1]][0], y + dxdy[command[cnt-1]][1], cnt+1);
		}
		return;
	}*/
	// cout << "X : " << x << " Y : " << y << endl;

	if(!board[x][y])
		board[x][y] = upDown[2]; // bottom side
	else
	{
		upDown[2] = board[x][y];
		leftRight[2] = board[x][y];
		board[x][y] = 0;
	}
	// print();
	//top
	// cout << "========== AFTER ===========" << endl;
	if(command[cnt] == 1) // east
	{
		// cout << "EAST" << endl;
		int tmp = leftRight[0];
		FOR(i, 3)
			leftRight[i] = leftRight[i+1];
		leftRight[3] = tmp;
		upDown[0] = leftRight[0];
		upDown[2] = leftRight[2];
	}
	else if (command[cnt] == 2) // west
	{
		// cout << "WEST" << endl;
		int tmp = leftRight[3];
		RFOR(i, 3)
			leftRight[i] = leftRight[i-1];
		leftRight[0] = tmp;
		upDown[0] = leftRight[0];
		upDown[2] = leftRight[2];
	}
	else if (command[cnt] == 3) // north
	{
		// cout << "NORTH" << endl;
		int tmp = upDown[3];
		RFOR(i, 3)
			upDown[i] = upDown[i-1];
		upDown[0] = tmp;
		leftRight[0] = upDown[0];
		leftRight[2] = upDown[2];
	}

	else // south
	{
		// cout << "SOUTH" << endl;
		int tmp = upDown[0];
		FOR(i, 3)
			upDown[i] = upDown[i+1];
		upDown[3] = tmp;
		leftRight[0] = upDown[0];
		leftRight[2] = upDown[2];
	}
	// print();
	cout << upDown[0] << endl;
	dfs(dx, dy, cnt+1);
}

int main()
{
	cin >> N >> M >> X >> Y >> C;
	FOR(i, N)
		FOR(j, M)
			cin >> board[i][j];

	FOR(i, C)
		cin >> command[i];

	dfs(X, Y, 0); 
	return 0;
}