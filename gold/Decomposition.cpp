//#2225
//@Reference hotehrud <https://github.com/hotehrud/acmicpc/blob/master/algorithm/dp/2225.java>
#include <iostream>
#define INF 1000000000
#define MAX 202

typedef long long ll;

using namespace std;


int N, K;
ll DP[MAX][MAX];

int main()
{
	cin >> N >> K;


	for(int i = 0; i <= N; i++)
		DP[1][i] = 1;


	for(int i = 1; i <= K; i ++)
		for(int j = 0; j <= N; j++)
			for(int k = 0; k <= j; k++)
			{
				DP[i][j] += DP[i-1][j-k];
				DP[i][j] %= INF;
			}
		
	

	cout << DP[K][N] << endl;
	
	return 0;
}