// #1490
#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
string input;
vector<ll> visited;
int N;
ll result = -1;

bool isDivide(ll value)
{
	FOR(i, visited.size())
	{
		if(visited[i] && value%visited[i])
			return false;
	}
	return true;
}
void bfs()
{
	queue<pair<int, ll>> Que;
	Que.push(make_pair(0, stoi(input)));
	while(!Que.empty())
	{
		int idx = Que.front().first;
		ll value = Que.front().second;
		Que.pop();
		// cout << idx <<" / "<< value << endl;

		if(isDivide(value) )
		{
			result = value;
			break;
		}
		for(int i = 1; i <= pow(10,idx)-1; i++)
		{
			// if(Que.push(make_pair(idx-1, value + i));
			cout << value + i << endl;
			if(isDivide(value+i)){
				result = value+i;
				return;
			}
		}
		value *= pow(10, 1);
		Que.push(make_pair(idx+1, value));
	}
}
int main()
{
	cin >> input;
	N = input.length();
	FOR(i, N)
		visited.push_back(input[i] - '0');
		
	bfs();

	cout << result << endl;
	return 0;
}