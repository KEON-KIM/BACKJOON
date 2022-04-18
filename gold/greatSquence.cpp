#include <iostream>
#include <string>

#define FOR(i,n) for(int i = 1; i <= n; i++)
using namespace std;

int N;
string result;
bool flag = false;
bool pass(string board)
{
	int size = board.size();
	FOR(i, size/2) // 문자열 길이 1 ~ size/2까지 확인
		// 이전 문자열 / 현재 중복 확인해야 할 문자열
		if(board.substr(size - i, i) == board.substr(size - 2 * i, i))
			return true;

	return false;
}

void dfs(string board, int depth)
{
	if(flag) return;
	if(pass(board)) return;

	if(depth == N){
		flag = true;
		result = board;
	}
	FOR(i, 3)
		dfs(board+char(i + '0'), depth + 1);
}

int main() {
	cin >> N;
	dfs("", 0);
	cout << result << endl;
}