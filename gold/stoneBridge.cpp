#include <iostream>
#include <cstring>
// #include <cmath>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

string dest, devil, angel;
int DP[21][101][2], result = 0;
int solution(int dep, int idx, int bridge)
{
	if(dep == dest.size())
		return 1;
	
	if(DP[dep][idx][bridge] > -1)
		return DP[dep][idx][bridge];
	
	int total = 0;
	if(bridge)
	{
		for(int i = idx; i < devil.length(); i++)
			if(dest[dep] == devil[i])
				total+= solution(dep+1, i+1, 0);
	}
	else
	{
		for(int i = idx; i < angel.length(); i++)
			if(dest[dep] == angel[i])
				total += solution(dep+1, i+1, 1);
	}

	DP[dep][idx][bridge] = total;
	return total;
}
int main()
{
	cin >> dest >> angel >> devil;
	memset(DP, -1, sizeof(DP));
	result += solution(0, 0, 1);
	result += solution(0, 0, 0);

	cout << result << endl;
	return 0;
}