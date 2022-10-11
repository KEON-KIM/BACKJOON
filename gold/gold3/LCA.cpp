//#11437
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define endl '\n'
#define MAX 100002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, M;
int parents[MAX], levels[MAX];
vector<int> graph[MAX];
int dfs(int an, int bn)
{
	if(levels[an] < levels[bn]) swap(an, bn); // a_node가 더 낮은 레벨에 있도록
	while(levels[an] != levels[bn]) // a_node와 b_node의 레벨이 같을 때까지 순회
		an = parents[an];

	while(an != bn) // a_node와 b_node의 부모가 같아질 때까지 순회
	{
		an = parents[an];
		bn = parents[bn];
	}

	return an;
}
void make_tree(int cur, int prev) // leveling 작업
{
	parents[cur] = prev;
	levels[cur] = levels[prev]+1;

	FOR(i, graph[cur].size()) // 자식 순회
	{
		int child = graph[cur][i];
		if(child == prev) continue; // 양방향 그래프이기 때문에 부모일 경우
		make_tree(child, cur);
	}
}
int main()
{
	cin >> N;
	FOR(i, N-1)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	make_tree(1, 0);

	cin >> M;
	FOR(i, M)
	{
		int a, b;
		cin >> a >> b;
		cout << dfs(a, b) << endl;
	}
	return 0;
}