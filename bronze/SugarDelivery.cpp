#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int dp[2001][2001];
vector<int> answer;

void init(int k)
{
	for(int i = 0; i <= k; i++)
		for(int j = 0; j <= k; j++)
			dp[i][j] = 3 * i + 5 * j;
}

void find(int k, int N)
{
	for(int i = 0; i <= k; i++)
		for(int j = 0; j <= k; j++)
			if(dp[i][j] == N) answer.push_back(i+j);
}

int main()
{
	int N, k;
	cin >> N;
	k = N/3;

	init(k);find(k,N);
	sort(answer.begin(), answer.end());
	if(!answer.size()) cout << -1 << endl;
	else cout << answer[0] << endl;

	return 0;
}