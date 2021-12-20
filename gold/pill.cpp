#include<iostream>
#include<cstring>
#include<cmath>

#define MAX 31
typedef long long ll;
using namespace std;
ll n, DP[MAX][MAX];

void solution()
{
	memset(DP, 0, sizeof(DP));
	for(int i = 0; i <= n; i++) 
		DP[0][i] = 1;

	for(int W = 1; W < n; W++){
		for(int H = 0; H < n; H++)
		{
			if(H == 0)
				DP[W][H] = DP[W-1][1];
			else
				DP[W][H] = DP[W][H-1] + DP[W-1][H+1];
		}
	}
	cout << DP[n-1][1] << endl;
}
int main()
{
	while(true)
	{
		cin >> n;
		if(!n) break;
		solution();
	}
	
	return 0;
}