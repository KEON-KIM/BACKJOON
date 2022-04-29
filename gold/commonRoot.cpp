// #3584
// @Reference pearlcrum 
// <https://pearlcrum.tistory.com/entry/BaekJoon-3584%EB%B2%88-%EA%B0%80%EC%9E%A5-%EA%B0%80%EA%B9%8C%EC%9A%B4-%EA%B3%B5%ED%86%B5-%EC%A1%B0%EC%83%81C>
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10001
#define FOR(i, n) for(int i= 0; i < n; i++)

int T, N;
int parent[MAX];
bool visited[MAX];
int main()
{
	int root;
	cin >> T;
	FOR(t, T)
	{
		cin >> N;
		FOR(i, N) // init;
		{
			visited[i] = false;
			parent[i] = i;
		}
		int a, b;
		FOR(i, N-1){
			cin >> a >> b;
			parent[b] = a;
		}

		int u, v;
		cin >> u >> v;
		visited[u] = true;
		while(u != parent[u])
		{
			u = parent[u];
			visited[u] = true;
		}

		while(true)
		{
			if(visited[v])
			{
				cout << v << endl;
				break;
			}
			v = parent[v];
		}
	}
	return 0;
}