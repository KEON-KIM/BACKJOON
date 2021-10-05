#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
bool isvisited(vector<int> visits)
{
	for(int i : visits) if(i == 0) return false;

	return true;
}

void printv(vector<int> v)
{
	for(int i = 0; i< v.size(); i++)
	{
		if(i == v.size() - 1) cout << v[i]<< endl;
		else cout << v[i] << " ";
	}
	// for(int i : v) cout << i << " ";
	// cout << endl;
}

bool isthere(vector<int> history, int a)
{
	for(int i : history) if(i == a) return true;
	return false;
}

void dfs(vector<pair<int, int>>cmd, vector<int> visits, int root)
{
	int n = root;
	stack<int> cache;
	if(cmd.size() > 0)cache.push(root);
	vector<int> history = {root};

	while(!cache.empty())
	{
		n = cache.top();
		cache.pop();
		if(!isthere(history, n))history.push_back(n);

		for(int i = 0; i < cmd.size(); i++)
		{
			if(cmd[i].first == n && visits[i] == 0 )
			{
				cache.push(cmd[i].second);
				visits[i] = 1;
			}
			else if (cmd[i].second == n && visits[i] == 0)
			{
				cache.push(cmd[i].first);
				visits[i] = 1;
			}
		}
	}
	printv(history);
}

void bfs(vector<pair<int, int>> cmd, vector<int> visits, int root)
{
	int n;
	queue<int> cache;
	if(cmd.size() > 0)cache.push(root);
	vector<int> history = {root};
	while(!cache.empty())
	{
		n = cache.front();
		cache.pop();
		if(!isthere(history,n))history.push_back(n);

		for(int i = cmd.size() -1 ; i >= 0; i--)
		{
			if(cmd[i].first == n && visits[i] == 0 )
			{
				cache.push(cmd[i].second);
				visits[i] = 1;
			}
			else if (cmd[i].second == n && visits[i] == 0)
			{
				cache.push(cmd[i].first);
				visits[i] = 1;
			}
		}
	}
	printv(history);
}

int main()
{
	int N, K, r, x, y;
	bool isStart= false;
	cin >> N >> K >> r;
	vector<pair<int, int>> cmd;
	vector<int> visits(K, 0);
	// visits[r-1] = 1;

	for(int i = 0; i < K; i++)
	{
		pair<int, int> tmp;
		cin >> x >> y;
		// if(x == r || y == r) isStart = true;
		if (x < y){tmp.first = x; tmp.second = y;} 
		else{tmp.first = y; tmp.second = x;} 
		cmd.push_back(tmp);
	}

	// if(isStart)
	// {
	// sort(cmd.begin(), cmd.end());
	sort(cmd.begin(), cmd.end(), greater<pair<int, int>>());
	dfs(cmd, visits, r);
	// sort(cmd.begin(), cmd.end());
	bfs(cmd, visits, r);
	// }
    return 0;
}
