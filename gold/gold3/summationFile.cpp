// #11066
// @Reference melonicedlatte <https://melonicedlatte.com/algorithm/2018/03/22/051337.html>
#include <iostream>
#include <algorithm>

#define MAX 502
#define INF 987654321
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
using namespace std;
 
int dp[MAX][MAX];
int cost[MAX];
int sum[MAX];
int T, K, i;
int main() {
    cin >> T;
    FOR(t, T)
    {
        cin >> K;
        for(int i = 1; i <= K; ++i)
        {
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }
        for(int d = 1; d < K; ++d)
        {
            for(int tx = 1; tx + d <= K; ++tx)
            {
                int ty = tx + d;
                dp[tx][ty] = INF;
                for(int mid = tx; mid < ty; ++mid)
                    dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid+1][ty] + sum[ty] - sum[tx - 1]);
            }
        }
        cout << dp[1][K] << endl;
    }
    return 0;
}
