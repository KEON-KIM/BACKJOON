#include<iostream>

using namespace std;

int dp[10001];
int main()
{
	for(int i = 1; i <= 10000; i++)
	{
		int k = 0;
		for(char c : to_string(i))  k += c - '0';
		dp[i + k]++;
	}

	for(int i = 1; i <= 10000; i++)
		if(dp[i] == 0) cout << i << endl;

	return 0;
}