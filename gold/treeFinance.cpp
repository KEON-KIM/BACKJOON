// #16235
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 11
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, M, K, result = 0;
int board[MAX][MAX]; // map
int S2D2[MAX][MAX]; // robot.
vector<int> Tree[MAX][MAX]; // year

void sorted()
{
	FOR(i, N)
		FOR(j, N)
			sort(Tree[i][j].begin(), Tree[i][j].end());
}
/*void print()
{
	cout << "=========== PRINT ===========" << endl;
	FOR(i, N){
		FOR(j, N)
			cout << board[i][j] << " ";
		cout << endl;
	}
	cout << "=========== TREE ===========" << endl;
	FOR(i, N){
		FOR(j, N)
			cout << Tree[i][j] << " ";
		cout << endl;
	}
	cout << "=========== ISTREE ===========" << endl;
	FOR(i, N){
		FOR(j, N)
			cout << isTree[i][j] << " ";
		cout << endl;
	}
}*/
void Spring(int x, int y, int k)
{	
	FOR(x, N)
		FOR(y, N)
			FOR(k, Tree[x][y].size())
				for(int i = x - 1; i <= x + 1; i++)
				{
					for(int j = y - 1; j <= y + 1; j++)
					{
						if(i < 1 || i > N || j < 1 || j > N) continue;
						if(board[i][j] - Tree[i][j][k-1] >= 0) // Grow Tree!
						{
							board[i][j] -= Tree[x][y][k-1];		
							Tree[x][y][k-1]++;
							return;
						}
					}
				}
	// Dead Tree
	Tree[x][y][k] = 0;
}

void Summer()
{
	FOR(x, N)
		FOR(y, N)
			FOR(k, Tree[x][y].size())
				if(!Tree[x][y][k]){
					board[x][y] += Tree[x][y][k]/2;
					Tree[x][y].erase(Tree[x][y].begin());
				}
}

void Autumn()
{
	FOR(x, N)
		FOR(y, N)
			FOR(k, Tree[x][y].size())
				if(!Tree[x][y][k]%5)
					for(int i = x - 1; i <= x + 1; i++)
						for(int j = y -1; j <= y + 1; j++)
						{
							if(i < 1 || i > N || j < 1 || j > N || (i == x && j == y)) continue;
							Tree[i][j].push_back(1);
						}
}

void Winter()
{
	FOR(i, N)
		FOR(j, N)
			board[i][j] += S2D2[i][j];
}

void routine()
{
	FOR(x, N)
		FOR(y, N)
			FOR(k, Tree[x][y].size())
				Spring(x, y, k);

	Summer();
	Autumn();

	sorted();
	Winter();
}

void Init()
{
	FOR(i, N)
		FOR(j, N)
			board[i][j] = 5;
}
int main()
{
	cin >> N >> M >> K;
	Init();
	FOR(i, N)
		FOR(j, N)
			cin >> S2D2[i][j];
		
	FOR(i, M)
	{
		int x, y, z;
		cin >> x >> y >> z;
		Tree[x][y].push_back(z);
	}

	FOR(i, K)
		routine();

	FOR(i, N)
		FOR(j, N)
			result += Tree[i][j].size();
	cout << result << endl;
	

	return 0;
}