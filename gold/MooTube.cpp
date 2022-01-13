#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

#define MAX 5002

typedef long long ll;
using namespace std;

int N, Q;
vector<pair<ll, ll>> board[MAX];
bool visited[MAX];

int main()
{
	ll x, y, z;
	cin >> N >> Q;
	for(int i = 1; i < N; i++)
	{
		cin >> x >> y >> z;
		board[x].push_back(make_pair(y, z));
		board[y].push_back(make_pair(x, z));
	}

	for(int i = 0; i < Q; i++)
	{
		queue<ll> Que;
		ll k, v, cnt = 0;
		memset(visited, false, sizeof(visited));

		cin >> k >> v;

		visited[v] = true;
		Que.push(v);

		while(!Que.empty())
		{
			ll idx = Que.front();
			Que.pop();
			for(pair<ll, ll> p : board[idx]){
				if(p.second >= k && !visited[p.first])
				{
					cnt++;
					Que.push(p.first);
					visited[p.first] = true;
				}
			}
		}

		cout << cnt << endl;
	}
	
	return 0;
}