// #2060
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

#define INIT 987654321
#define MAX 51

using namespace std;

int N, result = INIT;
int board[MAX][MAX];
priority_queue<int, vector<int>, greater<int>> cache;

void print()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	// INIT 
	int a, b;
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(i==j) continue;
			else board[i][j] = INIT;
		}
	}
	while(true)
	{
		cin >> a >> b;
		if(a+b < 0) break;
		board[a][b] = 1;
		board[b][a] = 1;
	}

	//Floyd Washal
	for(int via = 1; via <= N; via++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				board[i][j] = min(board[i][j], board[i][via] + board[via][j]);

	for(int i = 1; i <= N; i++)
	{
		int temp = -1;
		for(int j = 1; j <= N; j++)
			temp = max(temp, board[i][j]);
		
		if(temp < result)
		{
			while(!cache.empty())
				cache.pop();
			cache.push(i);
			result = temp;
		}

		else if (temp == result){
			cache.push(i);
			result = temp;
		}
	}

	cout << result << " "<< cache.size() << endl;

	while(!cache.empty()){
		cout << cache.top() << " ";
		cache.pop();
	}
	cout << endl;
	
	return 0;
}


