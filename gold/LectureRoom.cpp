// #11000
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 200001

using namespace std;

int n;
pair<int, int> p[MAX];
priority_queue<int, vector<int>, greater<int>> cache;

void solution()
{
	cache.push(p[0].second);
	for(int i = 1; i < n; i++)
	{
		cout <<"TOP : " << cache.top() << endl;
		if(cache.top() <= p[i].first)
		{
			cache.pop();
			cache.push(p[i].second);
		}
		else
			cache.push(p[i].second);
	}
}
int main()
{
	int a, b;
	cin >> n;
	for(int i = 0; i < n ; i++)
		cin >> p[i].first >> p[i].second;
	
	sort(p, p+n);
	solution();

	cout << cache.size() << endl;
	return 0;
}