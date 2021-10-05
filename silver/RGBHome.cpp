#include <iostream>

using namespace std;

int minValue(int dp[3])
{
	int min = 9999999;
	for(int i = 0; i < 3; i++)
		if(dp[i] <= min)min = dp[i];
		
	return min;
}

// int main()
// {
// 	int dp[1001][3], N, min, index;
// 	int cache[3] = {0,1,2};

// 	// int* a = RGB;
// 	cin >> N;
// 	for(int i = 0; i < N; i++)
// 		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
	
// 	for(int i = 1; i < N; i++){
// 		for(int j = 0; j < 3; j ++){
// 			min = 9999999;
// 			index = 0;
// 			for(int k = 0; k < 3; k++){
// 				if(k != cache[j] && dp[i][k] <= min) {
// 					min = dp[i][k];
// 					index = k;
// 				}
// 			}
// 			cache[j] = index;
// 			dp[0][j] += dp[i][cache[j]];
// 		}
// 	}
// 	cout << minValue(dp[0]) << endl;

// 	return 0;
// }
int Min(int a, int b){ return (a > b) ? b : a;}

int main()
{
	int dp[1001][3], N, min, index;
	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

	for(int i = 1; i < N; i++){
		for(int j = 0; j < 3; j++)
		{
			if(j == 0) 
				dp[i][j] += Min(dp[i-1][1], dp[i-1][2]);
			
			else if( j == 1)
				dp[i][j] += Min(dp[i-1][0], dp[i-1][2]);
			else 
				dp[i][j] += Min(dp[i-1][0], dp[i-1][1]);
		}
	}

	cout << Min(Min(dp[N-1][0], dp[N-1][1]),dp[N-1][2]) << endl;

	return 0;
}

// // void minIndex(vector<vector<int>> cache, int a, int b)
// // {
// // 	int min = 999999;
	
// // 	for(int i = b;  i < 3; i++)
// // 	{
// // 		for(int j = 0; j < 3; j++)
// // 		{
// // 			if(i != j ){
// // 				if (cache[a][i] + cache[a+1][j] <= min){
// // 					min = cache[a][i] + cache[a+1][j];
// // 					cnt[a] = i; cnt[b] = j;
// // 				}
// // 			}
// // 		}
// // 	}
// // }

// // int solution(vector<vector<int>> cache)
// // {
// // 	int n = 0;
// // 	for(int i = 0; i < cache.size()-1; i++)
// // 		minIndex(cache, i, cnt[i]);

// // 	return 0;
// // }
// int minValue(int dp[3])
// {
// 	int min = 9999999;
// 	for(int i = 0; i < 3; i++)
// 		if(dp[i] <= min)min = dp[i];
		
// 	return min;
// }

// int main()
// {
// 	int dp[1001][3], N, min, index;
// 	int cache[3] = {0,1,2};

// 	// int* a = RGB;
// 	cin >> N;
// 	for(int i = 0; i < N; i++)
// 		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
	
// 	for(int i = 1; i < N; i++){
// 		for(int j = 0; j < 3; j ++){
// 			min = 9999999;
// 			index = 0;
// 			for(int k = 0; k < 3; k++){
// 				if(k != cache[j] && dp[i][k] <= min) {
// 					min = dp[i][k];
// 					index = k;
// 				}
// 			}
// 			cache[j] = index;
// 			dp[0][j] += dp[i][cache[j]];
// 		}
// 	}
// 	// solution(cache);
// 	cout << minValue(dp[0]) << endl;

// 	// cout << SUM << endl;

// 	return 0;
// }