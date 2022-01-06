//#13164

#include<iostream>
#include<queue>

#define MAX 300001
using namespace std;

int N, K, board[MAX], result = 0;
int main()
{
	priority_queue<int> PQ;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> board[i];
		if(i > 0) PQ.push(board[i] - board[i-1]);
	}
	int cnt = 0;

	while(!PQ.empty())
	{
		if(cnt >= K-1)
			result += PQ.top();
		PQ.pop();
		cnt++;
	}
	
	cout << result << endl;


	return 0;
}