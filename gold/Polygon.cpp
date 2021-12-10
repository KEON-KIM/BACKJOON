//#2166
// @Reference degurii <https://degurii.tistory.com/147>

#include <iostream>

using namespace std;
typedef long long ll;
 
int n;
ll result = 0;
pair<ll, ll> points[10000];

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return x1*y2 + x2*y3 + x3*y1 - (y1*x2 + y2*x3 + y3*x1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> points[i].first >> points[i].second;
	
    pair<ll, ll> s = points[0];
	for (int i = 1; i < n - 1; i++) 
		result += ccw(s.first, s.second, 
			points[i].first, points[i].second, 
			points[i + 1].first, points[i + 1].second);
	

    result = abs(result);
    cout << result/2;
    if(result & 1) cout << ".5";
    else cout <<".0";
}