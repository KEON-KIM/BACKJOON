// #15299
#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
using namespace std;

int N, result = 0;
int main() {
	fastio;
	int N, ans = 0;
	cin >> N;

	int l, r; 
	l = r = -1e9 - 1;

	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;

		if (a > r) {
			result += (r - l);
			l = a, r = b;
		}
		else r = max(r, b);
	}

	result += (r - l);

	cout << result << '\n';
	return 0;
}