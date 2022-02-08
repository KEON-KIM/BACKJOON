//#20500
//@Reference steady-coding <https://steady-coding.tistory.com/339>
#include<iostream>
#include<cstring>
#include<cmath>

#define MAX 1516
#define INF 1000000007
using namespace std;

typedef long long ll;
ll N, board[3][MAX];
int main()
{
	cin >> N;

    board[0][2] = board[1][2] = 1;

    for (int i = 3; i <= N; i++) {
    	board[0][i] = (board[1][i - 1] + board[2][i - 1]) % INF;
    	board[1][i] = (board[0][i - 1] + board[1][i - 1]) % INF;
    	board[2][i] = (board[0][i - 1] + board[2][i - 1]) % INF;
    }

	cout << board[0][N] << endl;
	return 0;
}
	// DEBUGING
	/*cin >> N;
	cout << "FUCK " << endl;
	T = pow(10, N);
	int i = 15, j = 2;

	cout << T << endl;
	while(i < T)
	{
		bool flag = false;
		string tmp = to_string(i);
		cout << tmp << endl;

		for(char c : tmp){
			if(c != '1' && c != '5')
				flag = true;
		}

		if(!flag)board[tmp.length()]++;
		i = 15 * j;
		j++;
	}

	string tmp = to_string(T);
	for(int i = 0; i < tmp.length(); i++)
	{
		cout << i << "th : " << board[i] << endl;
	}

	return 0;
}*/