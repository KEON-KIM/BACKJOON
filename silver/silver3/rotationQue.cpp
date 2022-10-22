//#1021
#include <iostream>
#include <vector>
#include <deque>

#define MAX 52
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int N, M;
int board[MAX], popCnt[MAX];
int main()
{
	deque<int> dQue;
	cin >> N >> M;
	FOR(i, N) dQue.push_back(i);
	FOR(i, M) cin >> board[i];

	int result = 0;
	FOR(i, M)
	{
		int cur = dQue.front();
		if(cur == board[i])
		{
			// for(int j = cur; j <= N; j++) popCnt[j]++;
			dQue.pop_front();
		}
		else
		{
			int forward = 0;
			int reverse = 0;
			deque<int> dq1 = dQue;
			deque<int> dq2 = dQue;
			while(dq1.front() != board[i])
			{
				int x = dq1.front();
				dq1.pop_front();
				dq1.push_back(x);
				forward++;
			}
		
			while(dq2.front() != board[i])
			{
				int x = dq2.back();
				dq2.pop_back();
				dq2.push_front(x);
				reverse++;
			}
			if(forward < reverse)
			{
				dQue = dq1;
				result += forward;
			}
			else
			{
				dQue = dq2;
				result += reverse;
			}
			dQue.pop_front();
		}
	}
	cout << result;
	return 0;
}