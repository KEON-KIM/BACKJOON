#include<vector>
#include<stack>
#include<string>
#include<iostream>
#include<algorithm>


#define MAX 400

using namespace std;

char board[20][20];
int visit[20][20];
int N,M;

void print()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}
void printa()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cout << visit[i][j];
		}
		cout << endl;
	}
}
void printcook(vector<int> v)
{
	for(int i : v) cout << i << "|";
	cout <<endl;
}
int main()
{
	string line;
	stack<pair<pair<int, int>, vector<int>>> cache;
	
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
	vector<int> tmp = {(int)board[0][0]};
	cout << endl;
	print();
	visit[0][0] = 1;

	cache.push(make_pair(make_pair(0,0),tmp));
	while(!cache.empty())
	{
		// cout << "?"<<endl;
		x = cache.top().first.first;
		y = cache.top().first.second;
		vector<int> cookie = cache.top().second;	

		cache.pop();

		for(int i = 0; i < 4; i++)
		{
			dx = x + dxdy[i][0];
			dy = y + dxdy[i][1];
			if(dx >= 0 && dx < N && dy >= 0 && dy < M)
			{
				if(find(cookie.begin(), cookie.end(), (int)board[dx][dy]) == cookie.end() && visit[dx][dy] == 0){
					cout << dx << "|" << dy << endl;
					visit[dx][dy] = visit[x][y] + 1;
					cookie.push_back((int)board[dx][dy]);
					cache.push(make_pair(make_pair(dx,dy), cookie));
				}
				else
				{
					if(result < visit[x][y]) result = visit[x][y];
				}
			}
			
		}
		printa();
		printcook(cookie);
	}

	cout << result << endl;

	return 0;
}
