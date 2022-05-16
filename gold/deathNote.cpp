//#2281
//@Reference Nimgnoej <https://nim-code.tistory.com/151>
#include <iostream>
#include <cstring>
#include <cmath>

#define MAX 1001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
using namespace std;

int N, M;
int board[MAX];
int DP[MAX][MAX]; //[써야하는 이름의 인덱스 값][해당 줄에 지금까지 쓰인 글자 수] = 빈칸 개수 
int dfs(int n, int len) // 써야하는 이름의 인덱스 값, 현재줄의 뒷칸 포함 길이
{
	if(n >= N) 
		return 0;

	int& res = DP[n][len];
	if(res != -1)
		return DP[n][len];

	// 분기점 
	// 한 칸 내려쓸 경우 
	res = pow((M - len + 1), 2) + dfs(n + 1, board[n] + 1);
	// 같은 줄일 경우
	if(len + board[n] <= M)
		res = min(res, dfs(n + 1,len + board[n] + 1));

	return res;
}
int main()
{
	fastio;
	cin >> N >> M;

	FOR(i, N)
		cin >> board[i];
	memset(DP, -1, sizeof(DP));
	cout << dfs(0, 0) << endl;
	return 0;
}