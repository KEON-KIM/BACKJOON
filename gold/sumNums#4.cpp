//#2015
//@Reference Crocus </www.crocus.co.kr/602>
#include <iostream>
#include <map>
 
#define MAX 200001
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;
ll N, K, ans = 0; 
int prefixSum[200001];

map<int, ll> MAP;
int main() 
{
	fastio;
 	cin >> N >> K;
    FOR(i, N)
    {
        int tmp;
        cin >> tmp;
        prefixSum[i] = prefixSum[i - 1] + tmp;
    }
 
 	FOR(i, N)
    {
        if (prefixSum[i] == K)
            ans++;

        ans += MAP[prefixSum[i] - K];
        MAP[prefixSum[i]]++;
    }
 
    cout << ans << endl;
 
    return 0;
}
