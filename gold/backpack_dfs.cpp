#include<iostream>
#include<vector>
#define MAX 100
using namespace std;

int visit[100];
int N, M, great = 0;

vector<pair<int, int>> bag;

void dfs(int weight, int value)
{
	if(weight == M) 
	{
		if(value > great) great = value;
		return;
	}
	else if (weight > M) return;
	else
	{
		for(int i = 0; i < N; i++)
		{
			if (!visit[i]){
				great = max(great, value);
				visit[i] = 1;
				dfs(weight + bag[i].first, value + bag[i].second);
				visit[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	int a,b;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		bag.push_back(make_pair(a,b));
	}

	dfs(0, 0);

	cout << great << endl;
	return 0;
}