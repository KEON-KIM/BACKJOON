#include <iostream>
#include <queue>
#include <deque>

#define MAX 100001
#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, K;
int board[MAX * 3];
int visited[MAX * 3];
vector<int> answer;
void Init()
{
	FOR(i, MAX)
		board[i] = INF;
}
bool range(int val)
{
	return val >= 0 && val <= 100000;
}
void bfs()
{
	deque<int> dq;
	dq.push_front(N);
	board[N] = 0;

	while(!dq.empty())
	{
		int idx = dq.front();
		int val = board[idx];
		dq.pop_front();

		if(idx == K) 
			return;
		
		if(range(idx - 1) && board[idx - 1] > val + 1)
		{
			dq.push_back(idx - 1);
			visited[idx - 1] = idx;
			board[idx - 1] = val + 1;
		}

		if(range(idx + 1) && board[idx + 1] > val + 1)
		{
			dq.push_back(idx + 1);
			visited[idx + 1] = idx;
			board[idx + 1] = val + 1;
		}

		if(range(idx * 2) && board[idx * 2] > val + 1)
		{
			dq.push_front(idx * 2);
			visited[idx * 2] = idx;
			board[idx * 2] = val + 1;
		}
	}
}

int main()
{
	cin >> N >> K;
	Init();
	bfs();
	int idx = K;
	cout << board[K] << endl;
	answer.push_back(K);
	while(idx != N)
	{
		answer.push_back(visited[idx]);
		idx = visited[idx];
	}
	for(int i = answer.size()-1; i >= 0; i--)
		cout << answer[i] << " ";
	cout << endl;

	return 0;
}