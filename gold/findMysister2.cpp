//#12851
#include<iostream>
#include<queue>

#define MAX 100001

using namespace std;
int n, m, cnt, t;
int visited[MAX];

void bfs()
{
	queue<pair<int, int>> Que;
	Que.push(make_pair(n,0));

	visited[n] = 1;
	while(!Que.empty())
	{
		int cur = Que.front().first;
		int time = Que.front().second;
		Que.pop();
		visited[cur] = 1;
		if(cnt && cur == m && t == time)
			cnt++;
		if(!cnt && cur == m)
		{
			t = time;
			cnt++;
		}

		if(cur * 2 < MAX && !visited[cur * 2])
			Que.push(make_pair(cur * 2, time + 1));
		if(cur + 1 < MAX && !visited[cur + 1])
			Que.push(make_pair(cur + 1, time + 1));
		if(cur - 1 >= 0 && !visited[cur - 1])
			Que.push(make_pair(cur - 1, time + 1));
	}

}

int main()
{
	cin >> n >> m;
	bfs();
	cout << t << "\n" << cnt << endl;
	return 0;
}

