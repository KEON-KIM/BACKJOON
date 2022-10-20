// #1041
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
int N, dice[7], minist[4];
int main()
{

	cin >> N;
	ll result = 0;
	int maxi = -1;
	memset(minist, 0x3f, sizeof(minist));
	FOR(i, 6) 
	{
		cin >> dice[i];
		result += dice[i];
		minist[1] = min(minist[1], dice[i]);
		maxi = max(maxi, dice[i]);
	}
	vector<pair<int, int>> v;
	for(int i = 0; i < 7/2; i++) v.push_back({dice[1 + i], dice[6 - i]});
	for(int i = 0; i < v.size(); i++)
		for(int j = i+1; j < v.size(); j++)
			minist[2] = min(minist[2], min(v[i].second + v[j].second, v[i].first + v[j].first));

	minist[3] = min(v[0].first + v[1].first + v[2].first, v[0].second + v[1].second + v[2].second);
	if(N > 1)
	{
		result = (5 * (long long)N*N - 16 * N + 12) * minist[1];
		result += 4 * minist[3];
		result += (8 * N - 12) * minist[2];
	}
	
	else result -= maxi;


	cout << result;
	return 0;
}
