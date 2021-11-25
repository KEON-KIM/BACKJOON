// #15683
#include<iostream>
#include<vector>

using namespace std;


int n, m;
int map[9][9];
vector<pair<int, int>> data;
vector<int> addr;
// * data[5];


void dfs(int type, int x, int y)
{
	if(type == 1)
	{

	}
	else if(type == 2)
	{

	}
	else if(type == 3)
	{

	}
	else if(type == 4)
	{

	}
	else
	{
		int count = 0;
		for(int i = x; i < n; i++)
		{
			if(x == i) continue;
			if(map[x+i][y])
			{

			}
		}
	}

}
int main()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for(int j =0; j < m; j++){
			cin >> map[i][j];
			if(map[i][j] != 6 || map[i][j] != 0 ){
				data.push_back(make_pair(i, j));
			}
		}

	int x, y;
	for(int i = data.size()-1; i > 0; i--)
	{
		for(int j = 0; j < data[i].size(); j++)
		{
			x = data[i][j].first;
			y = data[i][j].second;
			dfs(i, x, y);
		}
	}
		
	

	return 0;
	
}