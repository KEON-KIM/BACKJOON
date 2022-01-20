//#1522
//@Reference boomrabbit <https://boomrabbit.tistory.com/57>
#include<iostream>
#include<string>

#define FOR(i, n) for(int i = 0; i < n ;i++)
#define INF (int)1e9

using namespace std;

string s;
int solve(int x, int len)
{
	int ret = 0;
	for (int i = x; i < x + len; i++)
		if (s[(i+1)%s.length()] == 'a')
			ret++;
	return ret;
}

int main()
{
	cin >> s;

	int cnt = 0, result = INF;

	FOR(i, s.length())
		if (s[i] == 'b')cnt++;

	FOR(i, s.length())
		result = min(result, solve(i, cnt));

	cout << result << endl;
	return 0;
}
