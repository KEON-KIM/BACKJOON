#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int INF = 987654321;
const int MAX = 501;
int N, M, result = 0;
int dist[MAX][MAX], path[MAX];

void Init()
{
	FOR(i, N)
		FOR(j, N)
			dist[i][j] = i==j? 0:INF;
}
void print()
{
	FOR(i, N){
		FOR(j, N)
			cout << dist[i][j] << " ";
		cout << endl;
	}
}
int main(){
	fastio;
	cin >> N >> M;
	Init();
	FOR(i, M){
		int a, b;
		cin >> a >> b;
		dist[a-1][b-1] = 1;
	}
	
	FOR(k, N)
		FOR(i, N)
			FOR(j, N)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			
	FOR(i, N){
		FOR(j, N){
			if(i == j) continue;
			if(dist[i][j] < INF){
				path[i]++;
				path[j]++;
				if(path[i] == N-1) result++;
				if(path[j] == N-1) result++;
			}	
		}
	}	

	cout << result << endl;

	return 0;
}
// using namespace std;

// int N, M;
// vector<int> graph[MAX];
// bool visited[MAX];
// vector<int> root;
// int bfs()
// {
// 	int result = -1, depth = 1;
// 	queue<pair<int, pair<int, int>>> Que; //{depth, {cnt, idx}};
// 	if(root.size() > 1)
// 		for(int i : root)
// 			Que.push({1, {0, i}});  // {cnt, root_idx}
// 	else
// 		Que.push({1, {1, root[0]}});
	
// 	while(!Que.empty())
// 	{
// 		int dep = Que.front().first;
// 		int cnt = Que.front().second.first;
// 		int index = Que.front().second.second;
// 		Que.pop();


// 		result = max(result, cnt);
// 		for(int i : graph[index])
// 		{
// 			if(visited[i])
// 				Que.push({dep+1, {cnt+1, i}});

// 			else
// 				Que.push({dep+1, {cnt, i}});

// 			visited[i] = true;
// 		}
// 	}
// 	return result;
// }
// int main()
// {
// 	cin >> N >> M;
// 	FOR(i, M)
// 	{
// 		int a, b;
// 		cin >> a >> b;
// 		visited[b] = true;
// 		graph[a].push_back(b);
// 	}
// 	for(int i = 1; i <= N; i++)
// 		if(!visited[i]) root.push_back(i);

// 	memset(visited, false, sizeof(visited));
// 	cout << bfs() << endl;
// 	return 0;
// }