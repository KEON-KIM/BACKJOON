#include <iostream>
#include <vector>
#include <cstring>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX 101

using namespace std;

int N, M;

vector<int> Hboard[MAX], Lboard[MAX];
int Lvisited[MAX], Hvisited[MAX];
// vector<pair<int, int>> graph;

int hdfs(int x){
	int depth = 1;
	for(int i = 0; i < Hboard[x].size(); i++){
		if(!Hvisited[Hboard[x][i]]){
			Hvisited[Hboard[x][i]] = 1;
			depth += hdfs(Hboard[x][i]);
		}
	}

	return depth;
}

int ldfs(int x)
{
	int depth = 1;
	for(int i = 0; i < Lboard[x].size(); i++){
		if(!Lvisited[Lboard[x][i]]){
			Lvisited[Lboard[x][i]] = 1;
			depth += ldfs(Lboard[x][i]);
		}

	}
	return depth;
}

int main()
{
	int x, y, result = 0;
	fastio;

	cin >> N >> M;

	for(int i = 0; i < M; i++)
	{
		cin >> x >> y;
		Hboard[y].push_back(x);
		Lboard[x].push_back(y);
	}

	for(int i = 1; i <= N; i++){ 
		memset(Hvisited, 0, sizeof(Hvisited));
		memset(Lvisited, 0, sizeof(Lvisited));

		Hvisited[i] = 1; Lvisited[i] = 1;

		// cout << hdfs(i) << " / " << ldfs(i) << endl;
		if(hdfs(i) > (N+1)/2 || ldfs(i) > (N+1)/2) 
			result++;
	}

	cout << result << endl;
	return 0;
}