// 10836
#include <iostream>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
using namespace std;

double board[20][20][20];
vector<int> notPrime = {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18};
int main(void) {
	int T = 90/5;
	double A, B;
	cin >> A >> B;
	A /= 100;
	B /= 100;
	board[0][0][0] = 1;
	// cout << A << B << endl;
	FOR(t, T)
		FOR(a, t + 1){
			FOR(b, t + 1)
			{
				board[t + 1][a][b] += board[t][a][b] * (1.0 - A) * (1.0 - B); // 둘다 골 못 넣을 경우
				board[t + 1][a + 1][b] += board[t][a][b] * A * (1.0 - B); // A만 골넣을 경우
				board[t + 1][a][b + 1] += board[t][a][b] * (1.0 - A) * B; // B만 골넣을 경우
				board[t + 1][a + 1][b + 1] += board[t][a][b] * A * B; // 둘다 골 넣을 경우
			}

	double res = 1;
	for(int a : notPrime)
		for(int b : notPrime)
			res -= board[T][a][b];

	cout << res << endl;
}