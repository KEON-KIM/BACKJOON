//#4781

#include <iostream>
#include <cstring>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define CANDY 5001
#define MONEY 10001
#define EPSILON 0.01

using namespace std;

pair<int, int> candy[CANDY];
int N, C, DP[MONEY];
double M, P;

int main() // knapsack Problem
{
	fastio;
	while(true)
	{
		cin >> N >> M;
		memset(DP, 0, sizeof(DP));
		if(N == 0 && M < EPSILON) break;

		for(int i = 0; i < N; i++){
			cin >> C >> P;
			candy[i] = make_pair(C, P * 100 + 0.5);
		}
		int Money = (int)(M * 100 + 0.5);
		for(int i = 0; i < N; i++)
			for(int j = candy[i].second; j <= Money; j++)
				DP[j] = max(DP[j], DP[j - candy[i].second] + candy[i].first);
			
		
		cout << DP[Money] << endl;
	}

	return 0;
}