// #1050
// @Reference hoji25 <https://hoji25.tistory.com/3?category=1000450>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long ll;

int N, M;
const int limit = 1000000000;
int main()
{
	cin >> N >> M;
	map<string, int> cost;
	vector<pair<string, vector<pair<int, string>>>> v;

	int c;
	string input; // input1, input2;
	FOR(i, N)
	{
		cin >> input >> c;
		cost[input] = c;
	}

	FOR(i, M)
	{
		string input;
		cin >> input;

		string buff;
		vector<string> temp; // 레시피 재료들
		istringstream iss(input);
		while(getline(iss, buff, '='))	
			temp.push_back(buff);

		istringstream iss_(temp[1]);
		vector<pair<int, string>> tmp; // 레시피의 재료
		while(getline(iss_, buff, '+'))
		{
			string str = buff.substr(1);
			if(!cost[str]) cost[str] = -1;
			tmp.push_back({buff[0] - '0', str});
		}
		if(!cost[temp[0]]) cost[temp[0]] = -1;
		v.push_back({temp[0], tmp});
	}

	bool flag = true;
	while(flag)
	{
		flag = false;
		FOR(i, v.size())
		{
			ll sum = 0;
			string name = v[i].first;
			for(pair<int, string> p : v[i].second)
			{
				int cnt = p.first;
				string str = p.second;
				if(cost[str] != -1)
				{
					sum += cnt * (ll)cost[str];
					if(sum > limit) sum = limit + 1;
				}
				else
				{
					sum = -1;
					break;
				}
			}
			if(sum > 0)
				if(cost[name] == -1 || cost[name] > sum)
				{
					cost[name] = sum;
					flag = true;
				}
		}
	}


	if(!cost["LOVE"])
		cout << "-1" << endl;
	else
		cout << cost["LOVE"] << endl;

	return 0;
}
/*#include <iostream>
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
map<string, bool> update;
map<string, bool> visited;
map<string, vector<string>> menu;
ll dfs(string str)
{
	//if(update[str]) return love[str]; // 최신화 되었으면 건들지 않음
	//update[str] = true;

	if(love[str] != INF && !menu[str].size())
	{
		if(!love[str]) love[str] = INF;
		return love[str];
	}
	for(string s : menu[str])
	{
		// cout << s << endl;
		bool flag = false;
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
			if(visited[tmp[i].first]) {res = INF; break;} // 

			visited[tmp[i].first] = true;
			dfs(tmp[i].first);
			visited[tmp[i].first] = false;

			if(love[tmp[i].first] == INF)  {res = INF; break;}
			res += love[tmp[i].first] * tmp[i].second;
		}

		love[str] = min(res, love[str]);
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

	visited["LOVE"] = true;
	dfs("LOVE");
	ll result = love["LOVE"];
	if(result == INF) cout << -1;
	else if(result < RES) cout << result;
	else cout << RES+1;
 	
	return 0;
}
//example
/*
2 9
A 10
C 60
LOVE=1A+1B
LOVE=1B+1C
LOVE=1D+1A
D=1A+1B
D=1A+1C
B=3A+2C
B=1A+1D
B=1A+1C
C=1A+1B

answer = 40
*/
