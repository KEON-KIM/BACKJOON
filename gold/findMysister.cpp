// #13548
// @Reference jeonds1127 <https://jdselectron.tistory.com/58>

#include<iostream>
#include<deque>

#define MAX 100001

using namespace std;

int n, m;
int cost[MAX];

void bfs()
{
	deque<int> dq;
	dq.push_back(n);
	cost[n] = 1;
	while(!dq.empty())
	{
		int cur = dq.front();
		dq.pop_front();

		if(cur == m) return;

		if(cur * 2 < MAX && !cost[cur*2])
		{
			dq.push_front(cur*2);
			cost[cur*2] = cost[cur];
		}
		if(cur + 1 < MAX && !cost[cur+1])
		{
			cost[cur+1] = cost[cur] + 1;
			dq.push_back(cur+1);
		}
		if(cur - 1 > 0 && !cost[cur-1])
		{
			cost[cur-1] = cost[cur] + 1;
			dq.push_back(cur-1);
		}
	}

}
int main()
{
	cin >> n >> m;
	bfs();
	cout << cost[m]-1 << endl;
	return 0;
}