#include <iostream>
#include <climits>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
void solution(vector<vector<int>> fees, int t)
{
	ll min_val = LONG_MAX, max_val = -1;
	FOR(i, fees.size())
	{
		ll fee = (t/fees[i][0] + 1) * fees[i][1];
		min_val = min(min_val, fee);
		max_val = max(max_val, fee);
	}
	cout << min_val << " " << max_val << endl;
}
int main()
{
	vector<vector<int>> fees = {{4, 1000}, {6, 1000}, {21, 3000}, {16, 2000}, {26, 3000}};
	solution(fees, 27);
	return 0;
}