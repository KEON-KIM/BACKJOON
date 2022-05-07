#include <iostream>
#include <queue>
#include <cmath>

#define MAX 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, T, G;
int visited[MAX];
int bfs(int start)
{
	queue<int> Que;
	Que.push(start);

	visited[start] = 1;
	while(!Que.empty())
	{
		int num = Que.front();
		int cost = visited[num];
		Que.pop();
		// cout << "asdf : " << num << endl;
		if(cost > T) return 0; 
		if(num == G) {
			cout << "what?" << endl;
			return 1;
		}

		int a = num + 1;
		int b = (num*2) - pow(10,(to_string(num*2).size()-1));
		cout << "A : " << a << " B : " << b << " COST : " << cost << endl;
		if((a > 0 && a < MAX) && !visited[a])
		{
			Que.push(a);
			visited[a] = cost+1;
		}
		if((b > 0 && num*2 < MAX) && !visited[b])
		{
			Que.push(b);
			visited[b] = cost+1;
		}
	}

	return 0;
}
int main()
{
	cin >> N >> T >> G;
	bfs(N);
	if(!visited[G])
		cout << "ANG";
	else
		cout << visited[G]-1 << endl;
	// if(!bfs(N) || !visited[G])
	// 	cout << "ANG" << endl;
	// else
		
	return 0;
}