// #2143
#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

typedef long long ll;
int main()
{
    fastio;
    int T, n, m;
    cin >> T;
    
    cin >> n;
    vector<ll> a(n);
    FOR(i, n) cin >> a[i];
    
    cin >> m;
    vector<ll> b(m);
    FOR(i, m) cin >> b[i];

    FOR(i, n) 
    {
        ll sum = a[i];
        for (int j = i + 1; j < n; ++j) 
        {
            sum += a[j];
            a.push_back(sum);
        }
    }

    FOR(i, m)
    {
        ll sum = b[i];
        for (int j = i + 1; j < m; ++j) 
        {
            sum += b[j];
            b.push_back(sum);
        }
    }

    ll result = 0;
    sort(b.begin(), b.end());
    FOR(i, a.size()) 
    {
        ll l = 0, r = b.size()-1, mid;
        ll ub = -1, lb = -1, sum = a[i];
        
        while (l <= r) {
            mid = (l + r) / 2;
            if (sum + b[mid] >= T) 
            {
                if(sum + b[mid] == T)
                    lb = mid;
                r = mid - 1;
            }
            else if (sum + b[mid] < T) 
                l = mid + 1;
        }

        l = 0, r = b.size()-1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (sum + b[mid] > T) 
                r = mid - 1;

            else if (sum + b[mid] <= T) 
            {
                if(sum + b[mid] == T)
                    ub = mid;
                l = mid + 1;
            }
        }

        if(ub != -1 && lb != -1)
            result += (ub - lb + 1);
    }
 
    cout << result;
    return 0;
}