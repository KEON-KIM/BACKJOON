//2011
#include <iostream>
#include <string>

#define MAX 5001
#define MOD 1000000
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

long long board[MAX], code[MAX];
int main()
{
	string input;
	cin >> input;
	int len = input.length();

	for (int i = 0; i < len; i++) code[i + 1] = input[i] - '0';
	FOR(i, len)
		code[i+1] = input[i] - '0';

	if (!(input[0] - '0')) cout << 0 << endl;
	else
	{
		board[0] = 1; // 0 초기화
		for (int i = 1; i <= len; i++){
			if(code[i])
				board[i] = board[i] + board[i - 1];
			
			int inf = code[i - 1] * 10 + code[i];
			if (inf >= 10 && inf <= 26)
				board[i] = (board[i] + board[i - 2])%MOD;
		}
		cout << board[len] << endl;
	}
	return 0;
}