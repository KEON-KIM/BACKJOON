//#3067
//@Reference Crocus <https://www.crocus.co.kr/1206>
#include <iostream>
#include <cstring>

#define N_MAX 21
#define M_MAX 10001
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
 
int T, N, M;
int coins[N_MAX], DP[M_MAX];
int main()
{    
	cin >> T;
 
 	FOR(t, T)
    {
    	cin >> N;
        memset(DP, 0, sizeof(DP));
 
 		FOR(i, N)
 			cin >> coins[i];
	 	
	 	cin >> M;
        DP[0] = 1;
        FOR(i, N)
            for(int j = 1; j<= M; j++)
                if (j - coins[i] >= 0)
                    DP[j] += DP[j - coins[i]];
            
        cout << DP[M] << endl;
    }
    return 0;
}