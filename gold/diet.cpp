//#19942
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define FOR(i, a, n) for(int i = a; i < n; i++)
#define MAX 15
#define INF 100000001
using namespace std;


int N, board[MAX][5], dest[4];
bool visited[MAX];

vector<int> planner;
priority_queue<pair<int ,vector<int>>, vector<pair<int ,vector<int>>>, greater<pair<int ,vector<int>>>> result;
struct _data{
	int mp, mf, ms, mv, cost;
	_data(int p, int f, int s, int v, int c)
	{
		mp = p;
		mf = f;
		ms = s;
		mv = v;
		cost = c;
	}
	void dataSum(int p, int f, int s, int v, int c)
	{
		mp += p;
		mf += f;
		ms += s;
		mv += v;
		cost += c;
	}
	void dataSub(int p, int f, int s, int v, int c)
	{
		mp -= p;
		mf -= f;
		ms -= s;
		mv -= v;
		cost -= c;
	}
};
//_data dest;


/*bool dia(int idx, _data d)
{
	FOR(i, idx + 1, N)
	{
		if(!visited[i])
		{
			if(d.cost + board[idx][4] < result.top().first)
				return false;
		}
	}
	return true;
}*/
void dfs(int index, _data D)
{
	FOR(i, index, N)
	{
		if(!visited[i] && D.cost + board[i][4] <= result.top().first)
		{
			visited[i] = true;
			D.dataSum(board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
			planner.push_back(i+1);
			dfs(i, D);
			visited[i] = false;
			D.dataSub(board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
			planner.erase(planner.end()-1);
		}
		if(D.mp >= dest[0] && D.mf >= dest[1] && D.ms >= dest[2] && D.mv >= dest[3]){
			result.push(make_pair(D.cost, planner));
		}
	}

}

int main()
{
	cin >> N;
	FOR(i, 0, 4)
		cin >> dest[i];
	int Total = 0;
	FOR(i, 0, N){
		FOR(j, 0, 5)
			cin >> board[i][j];
		Total += board[i][4];
	}

	result.push({Total, {MAX} });

	FOR(i, 0, N-1)
	{
		_data cur = _data(board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
		visited[i] = true;
		planner.push_back(i+1);
		dfs(i, cur);
		planner.erase(planner.end()-1);
	}

	if(result.size() == 1)
		cout << -1 << endl;
	else
	{
		cout << result.top().first << endl;
		for(int i : result.top().second) cout << i << " ";
	}

	return 0;
}