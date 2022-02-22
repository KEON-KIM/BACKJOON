//#11278
#include<iostream>
#include <cmath>
#include <queue>

#define N_MAX 22
#define M_MAX 101
#define endl '\n'
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;
int N, M, result = 0;
bool num[N_MAX] = {false, }, flag = false;
pair<int, int> board[M_MAX];


bool Calculation(int idx)
{
	if(board[idx].first < 0 && board[idx].second < 0) // (-, -)
		return ((!(num[abs(board[idx].first)])) || (!(num[abs(board[idx].second)])));

	else if(board[idx].first < 0 && board[idx].second >= 0) // (-, +)
		return ((!(num[abs(board[idx].first)])) || num[board[idx].second]);

	else if(board[idx].first >= 0 && board[idx].second < 0) // (+, -)
		return (num[board[idx].first] || (!(num[abs(board[idx].second)])));

	else //(+, +)
		return (num[board[idx].first] || num[board[idx].second]);
}

void dfs(int dep)
{
	if(flag) return;
	if(dep == N+1)
	{
		FOR(i, M)
		{
			if(!Calculation(i)){
				flag = false;
				break;
			}
			flag = true;
		}

		if(flag){
			result = 1;
		}
		return;
	}
	// FOR(i, 2)
	num[dep] = true; dfs(dep+1); if(flag) return;
	num[dep] = false; dfs(dep+1); if(flag) return;
}

int main()
{
	int a, b;
	cin >> N >> M;

	FOR(i, M){
		cin >> a >> b;
		board[i] = make_pair(a, b);
	}

	dfs(1);
	cout << result << endl;
	if(result){
		for(int i = 1; i <= N; i++)
			cout <<num[i] << " ";
		cout << endl;
	}
	return 0;
}