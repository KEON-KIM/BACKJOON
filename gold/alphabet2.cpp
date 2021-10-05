#include<stack>
#include<string>
#include<iostream>

using namespace std;

char board[20][20];
int N,M;

int main()
{
	string line, cookie;
	stack<pair<pair<int, int>, string>> cache;
	
	int x, y, dx, dy, result = 1;
	int dxdy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> line;
		for(int j = 0; j < M; j++)
		{
			board[i][j] = line[j];
		}
	}

	cookie += board[0][0];

	cache.push(make_pair(make_pair(0,0), cookie));
	while(!cache.empty())
	{
		x = cache.top().first.first;
		y = cache.top().first.second;
		
		cookie = cache.top().second;
		cache.pop();

		for(int i = 0; i < 4; i++)
		{	
			string tmp = cookie;
			dx = x + dxdy[i][0];
			dy = y + dxdy[i][1];
			if(x >= 0 && x < N && y >= 0 && y < M)
			{
				if(tmp.find(board[dx][dy]) == string::npos){
					tmp+=board[dx][dy];
					cache.push(make_pair(make_pair(dx,dy), tmp));
				}
				else 
					if(result < tmp.size())result = tmp.size();
			}
		}
	}

	cout << result << endl;

	return 0;
}
