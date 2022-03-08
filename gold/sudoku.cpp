// #2580 / backtracking
#include<iostream>
#include<vector>
#include<cstring>

#define MAX 9
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int zeroCnt = 0, sudoku[MAX][MAX];
vector<pair<int, int>> cache;
bool dia(int x, int y, int val)
{
	for(int i = (x/3)*3; i < ((x/3)*3) + 3; i++)
		for(int j = (y/3)*3; j < ((y/3)*3) + 3; j++)
		{
			if(i == x && j == y) continue;
			if(val == sudoku[i][j])
				return false;
		}

	FOR(i, MAX)
		if((sudoku[x][i] == val && i != y)|| (sudoku[i][y] == val && i != x))
			return false;
	
	return true;
}

/*bool dfs(int x, int y)
{
	if(dia(x, y, sudoku[x][y]))
	{
		if(zeroCnt == 0)
			return true;
		
		FOR(i, MAX)
			FOR(j, MAX)
				if(!sudoku[i][j])
					for(int k = 1; k < 10; k++)
					{
						if(!visited[i][j][k]){
							zeroCnt--;
							sudoku[i][j] = k;
							visited[i][j][k] = true;
							if(dfs(i, j)) return true;
							visited[i][j][k] = false;
							sudoku[i][j] = 0;
							zeroCnt++;
						}
					}
	}
	return false;
}*/
bool dfs(int cur)
{
	int x = cache[cur].first;
	int y = cache[cur].second;
	if(cur == zeroCnt)
	{
		return true;
	}
	for(int i = 1; i <= 9; i++)
	{
		cout << x << "/" << y << "/" << i <<  endl;
		if(dia(x, y, i)){
			sudoku[x][y] = i;
			if(dfs(cur+1)) return true;
		}
	}
	sudoku[x][y] = 0;

	// for(int i = 1; i <= 9; i++) visited[x][y][i] = false;

	return false;
}

void Print()
{
	FOR(i, MAX)
	{
		FOR(j, MAX)
			cout << sudoku[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	FOR(i, MAX)
		FOR(j, MAX){
			cin >> sudoku[i][j];
			if(!sudoku[i][j]){
				cache.push_back({i, j});
				zeroCnt++;
			} 
		}

	if(dfs(0))
		Print();


	/*FOR(i, MAX)
		FOR(j, MAX)
			if(!sudoku[i][j])
				for(int k = 1; k < 10; k++)
				{
					if(!visited[i][j][k])
					{
						zeroCnt --;
						sudoku[i][j] = k;
						visited[i][j][k] = true;
						if(dfs(i, j))
						{
							Print();
							return 0;
						}
						visited[i][j][k] = false;
						sudoku[i][j] = 0;
						zeroCnt ++;
					}
					
				}*/

	return 0;
}