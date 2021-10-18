//2577
#include<iostream>
#include<string>

using namespace std;


int A, B, C;
int dp[10] = {0,};

int main()
{
	cin >> A >> B >> C;

	long long result = A * B * C;
	cout << result << endl;

	string answer = to_string(result);
	for(char c : answer)
		dp[c - '0']++;

	for(int i : dp)
		cout << i << endl;
	
	return 0;
}