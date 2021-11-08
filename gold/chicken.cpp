// #15686
// @Reference jaimemin <https://jaimemin.tistory.com/1059> 

#include<iostream>
#include<vector>
#include<cmath>

#define MAX 987654321;

using namespace std;

int N, M, result = MAX;
int board[51][51];
int visit[14];

vector<pair<int, int>> house, chicken;

int distance(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(int index, int visited)
{
	if(visited == M)
	{
		int tmp = 0;
		for(int i = 0 ; i < house.size(); i++)
		{
			int dist = MAX;
			for(int j = 0; j < chicken.size(); j++)
				if(visit[j])
					dist = min(dist, distance(house[i].first, house[i].second, chicken[j].first, chicken[j].second));
			
			tmp += dist;
		}
		result = min(tmp, result);
		return;
	}	
	if(index == chicken.size()) return;
	
	visit[index] = true;
	dfs(index + 1, visited + 1);
	visit[index] = false;
	dfs(index + 1, visited);
}


int main()
{
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 1)
				house.push_back(make_pair(i,j));
			else if (board[i][j] == 2)
				chicken.push_back(make_pair(i,j));
		}
	}

	dfs(0,0);
	cout << result << endl;
	
	return 0;
}