#include<iostream>
#include<algorithm>

#define MAX 10002
#define COIN 102
using namespace std;
int T, K;

// int DP[MAX][COIN]; // K, T;
int DP[COIN][MAX];
pair<int, int> coin[COIN];

void print()
{
	for(int i = 1; i <= K; i++)
	{
		for(int j = 1; j <= T; j++)
			cout << DP[i][j] <<" ";
		cout << endl;
	}
}
int main()
{
	cin >> T >> K;

	for(int i = 1; i <= K; i++){
		int p, n;
		cin >> p >> n;
		coin[i] = make_pair(p, n);
	}

	for(int i = 1; i <= K; i++)
	{
		int p = coin[i].first;
		int n = coin[i].second;

		DP[i-1][0] = 1;
		for(int j = 1; j <= n; j++)
		{
			for(int k = p * j; k <= T; k++)
			{
				DP[i][k] += DP[i-1][k - (p * j)];
			}
		}

		for(int j = 1; j <= T; j++)
			DP[i][j] += DP[i-1][j];	
	}
	print();
	cout << DP[K][T] << endl;


	return 0;
}
	/*
	sort(coin+1, coin+(K+1));

	for(int i = 1; i <= K; i++)
	{
		for(int j = 1; j <= T; j++)
		{

			DP[i][j] = DP[i-1][j];
			if(j > coin[i].first){//} && j/coin[i].first <= coin[i].second){
				cout << i << "/" << j << ": "<<j/(coin[i].first) << endl;
				DP[i][j] += DP[i-1][j/coin[i].first];
			}
			if(!(j%coin[i].first) && (j/coin[i].first <= coin[i].second)) DP[i][j]++;
		}
	}
	print();
	cout << DP[K][T] << endl;

	return 0;
}
*/