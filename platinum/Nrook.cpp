#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
int n, m, k, mod = 1000001;
ll dp[101][101][101];
 
ll go(int n, int m, int k) {
    if (n < 0 || m < 0 || k < 0) return 0;
    if (k == 0) return 1;
    ll& ret = dp[n][m][k];
    if (ret != -1) return ret;
    ret = 0;
    ret += go(n - 1, m, k);
    ret += go(n - 1, m - 1, k - 1) * m;
    // kill each other rooks 
    ret += go(n - 1, m - 2, k - 2) * m * (m - 1) / 2;
    ret += go(n - 2, m - 1, k - 2) * m * (n - 1);
    ret %= mod;
    return ret;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    cout << go(n, m, k) << '\n';
}
