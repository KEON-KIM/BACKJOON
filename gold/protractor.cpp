//#2916
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD 360
#define FOR(i, n) for(int i = 0; i < n; i++)

int N, M;
bool angle[361];
int main()
{
	cin >> N >> M;

    int A;
	angle[0] = true;
	FOR(i, N)
	{
		cin >> A;
		int next = 0;
		while (true)
		{
			angle[next] = true;
            FOR(j, MOD)
			{
				if (angle[j])
				{
					angle[(next + j) % MOD] = true;
					angle[abs(next - j)] = true;
				}
			}
			next = (next + A) % MOD;
			if (!next) break;
		}
	}

	FOR(i, M)
	{
		cin >> A;
		cout << (angle[A] ? "YES" : "NO") << endl;
	}
}