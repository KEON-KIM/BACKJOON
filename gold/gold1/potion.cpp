#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#define MAX 51
#define RES 1000000000
#define INF 10000000000001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
typedef long long ll;

int N, M;
map<string, ll> love;
map<string, int> visited;
map<string, vector<string>> menu;
ll dfs(string str)
{
	// cout << str << " / " << love[str] << endl;
	if(love[str] != INF && !menu[str].size()) {
		if(!love[str]) love[str] = INF;
		return love[str];
	}
	if(visited[str]) {return INF;} // 에러
	for(string s : menu[str])
	{
		bool flag = false;
		visited[str] = true;
		ll res = 0;
		string buff;
		istringstream iss(s);
		vector<pair<string, int>> tmp;
		while(getline(iss, buff, '+'))
		{
			string word = buff.substr(1);
			int n = buff[0] - '0';
			tmp.push_back({word, n});
		}

		FOR(i, tmp.size())
		{
			visited[s] = true;
			ll v = dfs(tmp[i].first);
			visited[s] = false;
			if(v == INF)  // v == INF 길없음, v== -1 루프
			{
				// visited[str] = false;
				flag = true;
				res = INF;
				break;
			}
			res += tmp[i].second * v;
		}
		visited[str] = false;
		if(!flag) love[str] = min(res, love[str]);
	}

	return love[str];
}
int main()
{
	fastio;
	ll value;
	string input;
	cin >> N >> M;
	FOR(i, N)
	{
		cin >> input >> value;
		love[input] = value;
	}

	FOR(i, M)
	{
		string buff;
		cin >> input;
		istringstream iss(input);
		vector<string> tmp;
		while(getline(iss, buff, '='))
			tmp.push_back(buff);
		
		menu[tmp[0]].push_back(tmp[1]);
		if(!love[tmp[0]]) love[tmp[0]] = INF;
	}

	ll result = dfs("LOVE");
	if(result == INF) cout << -1;
	else if(result < RES) cout << result;
	else cout << RES+1;
 	
	return 0;
}