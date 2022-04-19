#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX 100002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll M, N, L;
ll hunter[MAX];
bool solution(int x, int y)
{
	int l = 0;
	int r = M-1;
	int cnt = 0;
	while(l <= r)
	{
		int mid = (l+r)/2;
		// cout << "(X, Y) : " << x <<"|"<<y <<" " << mid << endl;
		if(abs(hunter[l] - x) + y <= L) return true;	
		if(abs(hunter[r] - x) + y <= L) return true;

		if(abs(hunter[mid] - x) + y <= L) return true;
		else
		{
			if(hunter[mid] > x) {
				r = mid-1;
			}
			else {
				l = mid+1;
			}
		}
	}

	return false;
}
void print()
{
	FOR(i, M)
		cout << hunter[i] << " ";
	cout << endl;
}

int main()
{
	fastio;
	int result = 0;
	cin >> M >> N >> L;

	FOR(i, M)
	{
		cin >> hunter[i];
	}sort(hunter, hunter+M);

	ll x, y;
	FOR(i, N)
	{
		cin >> x >> y;		
		if(solution(x, y))
			result++;
	}
	cout << result << endl;
	return 0;
}