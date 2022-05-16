// #2141
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX 100001
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int N;
vector<pair<ll, ll>> post;
int main()
{
	int A, X;
	int result;
	/*auto cmp = [](pii a, pii b){
			if(a.first >= b.first) {
				if(a.first == b.first)
				{
					if(a.second < b.second)
						return false;
					else
						return true;
				}
				else
					return false;
			}
			else
				return true;
		};
	priority_queue<pii, vector<pii>, decltype(cmp) > pQue(cmp); */
	ll total = 0;
	cin >> N;
	FOR(i, N)
	{
		cin >> A >> X;
		post.push_back({A, X});
		total += X;
	}
	sort(post.begin(), post.end());
	ll cmp = 0;
	for(int i = 0; i < post.size(); i++)
	{
		cmp += post[i].second;
		if(cmp >= (total+1)/2)
		{
			cout << post[i].first;
			break;
		}
	}
	return 0;
}