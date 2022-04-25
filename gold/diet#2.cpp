//#1484
#include <iostream>
#include <vector>
#include <math.h>

#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long ll;

int G;
vector<int> answer;
bool Square(ll n) // 
{
	ll cmp = sqrt(n);
	if(!(sqrt(n) - cmp)) return true;

	return false;
}

int main()
{
	cin >> G;
	ll C = 1, B = 0; // current, before;
	while((C*C) - (B*B) <= G)
	{
		ll cmp = (C*C) - G;
		if(cmp > 0 && Square(cmp))
			answer.push_back(C);
		
		B = C;
		C++;
	}

	if(answer.size() < 1)
		cout << -1;
	else
		for(int i = 0; i < answer.size(); i++)
			cout << answer[i] << endl;
	return 0;
}