#include <iostream>

#define MAX 1000001
#define MOD 1000000000
using namespace std;

typedef long long ll;
int N;
ll dp[MAX];
int main()
{
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 2;
	cin >> N;
	for(int i = 4; i < MAX; i++)
		dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])% MOD); 
	
	cout << dp[N] << endl;
	return 0;
}