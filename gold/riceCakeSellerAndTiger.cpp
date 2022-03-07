// #16432
#include <iostream>
#include <vector>

#define MAX 1001
#define endl '\n'
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, result[MAX];
bool visited[MAX][10];
bool flag = false;
vector<int> days[MAX];

bool dfs(int day)
{
	if(day == N+1) {
		return true;
	}
	for(int i : days[day])
	{
		if(result[day-1] != i && !visited[day][i])
		{ 
			result[day] = i;
			visited[day][i] = true;
			if(dfs(day+1)) return true;
		}
	}
	return false;
}

void print()
{
	cout << "====== PRINT ======" << endl;
	FOR(i, N){
		for(int j = 0; j < days[i].size(); j++)
			cout << days[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int n, x;

	fastio;
	cin >> N;
	FOR(i, N){
		cin >> n;
		FOR(j, n){
			int x; cin >> x;
			days[i].push_back(x);
		}
	}

	if(!dfs(1)) cout << -1 << endl;
	else 
		FOR(i, N)
			cout << result[i] << endl;
	

	return 0;
}