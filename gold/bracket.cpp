// #10422
// @Reference kukekyakya <https://kukekyakya.tistory.com/entry/%EB%B0%B1%EC%A4%80-10422-%EA%B4%84%ED%98%B8>
#include <iostream>

#define MAX 5001
#define MOD 1000000007
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long ll;
int T, N;
ll DP[MAX/2 + 1];
void Init()
{
	DP[0] = 1;
	DP[1] = 1;
	for (int i = 2; i < MAX/2 + 1; i++)
	{
		ll s = 0;
		for (int j = 1; j <= i/2; j++)
		{
			s += (DP[j - 1] * DP[i - j]) % MOD;
		}
		DP[i] = (2 * s + (i%2 ? DP[i/2] * DP[i/2] : 0)) % MOD;
	}
}

int main(void)
{
	cin >> T;
	
	Init();
	FOR(i, T)
	{
		cin >> N;
		cout << (N%2 ? 0 : DP[N/2]) << endl;
	}

	return 0;
}