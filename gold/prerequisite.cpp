//#14567
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

#define MAX 1001
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;
int N, M;
int indegree[MAX], answer[MAX];

vector<int> subject[MAX];
int main()
{
	fastio;
	cin >> N >> M;

	int a, b;
	FOR(i, M){
		cin >> a >> b; 
		subject[a].push_back(b);
		indegree[b]++;
	}
	// FOR(i, N)
	// 	answer[i] = 1* (N+1); 


	queue<int> Que;
	vector<int> result;
	FOR(i, N)
	{
		if(!indegree[i]){
			Que.push(i);
			answer[i] = 1;
		}
	}

	FOR(i, N)
	{
		int prev = Que.front();
		Que.pop();
		result.push_back(prev);

		for(int t : subject[prev]){
			indegree[t]--;
			if(!indegree[t])
				Que.push(t);
			answer[t] = answer[prev] +1;
		}
	}
	

	FOR(i, N)
		cout << answer[i] << " ";
	cout << endl;

	return 0;
}