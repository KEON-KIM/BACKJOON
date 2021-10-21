//#2672
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define MAX 25

using namespace std;

int N, oneCnt = 0, cnt;
int board[MAX][MAX];
vector<int> complex;

void dfs(int x, int y)
{
	if(x < 0 || x >= N || y < 0 || y >= N) return;
	if(!board[x][y]) return;

	board[x][y] = 0;
	oneCnt--;

	dfs(x+1,y);dfs(x-1,y);dfs(x,y+1);dfs(x,y-1);
}

int main()
{
	string str;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> str;
		for(int j = 0; j < N; j++)
		{
			board[i][j] = str[j] - '0';
			if(board[i][j]) oneCnt++;
		}
	}
	int checkPoint = oneCnt;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(board[i][j]){
				dfs(i, j);
				complex.push_back(checkPoint - oneCnt);
				checkPoint = oneCnt;
			} 

		}
		if(!oneCnt) break;
	}
	sort(complex.begin(), complex.end());

	cout << complex.size() << endl;
	for(int i : complex) cout << i << endl;
	
	return 0;
}