// #2056
// @Reference chosh95 <https://chosh95.tistory.com/426>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10001
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, result = 0;
int costs[MAX], times[MAX]; 
vector<int> board[MAX];
int main()
{
	cin >> N;
	FOR(i, N){
		int n, c;
		cin >> costs[i] >> n;
		FOR(j, n) {
			cin >> c;
			board[i].push_back(c);
		}
	}

	FOR(i, N) {
		int cur = 0;
		for(int j = 0; j < board[i].size(); j++)
			cur = max(cur, times[board[i][j]]);
		times[i] = cur + costs[i];
	}

	for (int i = 1; i <= N; i++) 
		result = max(result, times[i]);

	cout << result;
}


// #include <iostream>
// #include <vector>
// #include <queue>

// #define MAX 10001
// #define FOR(i, n) for(int i = 1; i <= n; i++)

// using namespace std;
// typedef pair<int, int> pii;
// vector<pii> board[MAX];
// vector<int> condition[MAX];
// int N, result = 0;
// int costs[MAX];
// int Solution(int start)
// {
// 	queue<int> Que;
// 	Que.push(start); // {cost, index};
// 	int res = 0;
// 	res += costs[start];

// 	while(!Que.empty())
// 	{
// 		int cur = Que.front();
// 		Que.pop();

// 		int maxTime = 0;
// 		for(pii p : board[cur])
// 		{
// 			int cnt = 0;
// 			int Time = p.first;
// 			int prior = p.second;

// 			maxTime = max(maxTime, p.first);
// 			for(int idx : condition[prior])
// 			{
// 				if(!costs[idx])
// 					break;
// 				else 
// 					cnt++;
// 			}
// 			if(cnt == condition[prior].size()){
// 				Que.push(prior);
// 				costs[prior] = res + Time;
// 			}
// 		}
// 		res += maxTime;
		
// 	}
// 	return res;
// }

// int main()
// {
// 	cin >> N;
// 	FOR(i, N)
// 	{
// 		int a, n, f;
// 		cin >> a >> n;
// 		if(!n) costs[i] = a;
// 		FOR(j, n)
// 		{
// 			cin >> f;
// 			board[f].push_back({a, i}); // {cost, index};
// 			condition[i].push_back(f);
// 		}
// 	}

// 	cout << Solution(1) << endl;
// 	return 0;
// }