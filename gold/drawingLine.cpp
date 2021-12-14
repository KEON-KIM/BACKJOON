#include<iostream>
#include<queue>

#define INF 1234567890
using namespace std;

int N, key = -INF, result = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	cin >> N;
	int a, b;
	for(int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if(a < b)
			pq.push(make_pair(a,b));
		else
			pq.push(make_pair(b,a));
	}

	while(!pq.empty())
	{
		if(key < pq.top().second){
			if(key >= pq.top().first)
				result += pq.top().second - key;
			
			else
				result += pq.top().second - pq.top().first;
		}
		key = max(pq.top().second, key);
		pq.pop();
	}

	cout << result << endl;

	return 0;
}