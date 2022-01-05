//#14395
#include <iostream>
#include <queue>
#include <set>
#include <string>
#define MAX 1000000000

using namespace std;

int s, t;

typedef long long ll;
int main()
{
	cin >> s >> t;
	if (s == t) {
		cout << 0 << "\n";
		return 0;
	}
	queue<pair<ll, string>> Que;
	set<ll> visited;

	Que.push(make_pair(s, ""));
	while (!Que.empty())
	{
		ll n = Que.front().first;
		string res = Que.front().second;

		if (n == t) {
			cout << res << "\n";
			return 0;
		}
		Que.pop();

		if (0 <=  n*n && n*n <= MAX && visited.count(n*n) == 0 ) {
			Que.push({ n*n, res + "*" });
			visited.insert(n*n);
		}
		if (0 <= n + n && n + n <= MAX && visited.count(n+n) == 0) {
			Que.push({ n + n, res + "+" });
			visited.insert(n + n);
		}
		if (0 <= n - n && n - n <= MAX && visited.count(n-n) == 0) {
			Que.push({ n - n, res + "-" });
			visited.insert(n - n);
		}
		if (n != 0 && 0 <= n / n && n / n <= MAX && visited.count(n/n) == 0) {
			Que.push({ n / n, res + "/" });
			visited.insert(n / n);
		}
	}

	cout << -1 << endl;
	return 0;
}

// #include<iostream>
// #include<queue>

// using namespace std;
// typedef long long ll;

// ll s, t, visited[2];
// // int s, t;

// void bfs()
// {
// 	queue<pair<ll ,string>> Que;
// 	Que.push(make_pair(s, ""));
// 	Que.push(make_pair(1, "/"));
// 	Que.push(make_pair(0, "-"));

// 	while(!Que.empty())
// 	{
// 		ll x = Que.front().first;
// 		string res = Que.front().second;
// 		Que.pop();
// 		cout << x << " / " << res << endl;

// 		if(x == 0 || x == 1)
// 		{
// 			if(visited[x])
// 				continue;
// 			else 
// 				visited[x] = 1;
// 		}

// 		if(x > t) continue;

// 		else if(x == t) {
// 			cout << res << endl;
// 			return ;
// 		}

// 		else {
// 			Que.push(make_pair(x*x, res+'*'));
// 			Que.push(make_pair(x+x, res+'+'));
// 		}	
// 	}

// 	cout << -1 << endl;
// }
// int main()
// {
// 	cin >> s >> t;

// 	if(s==t) cout << 0 << endl;
// 	else bfs();
	
// 	return 0;
// }