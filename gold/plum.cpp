// #2240
// @ Reference mygumi <https://mygumi.tistory.com/140>
#include <iostream>

#define TMAX 1001
#define WMAX 32
using namespace std;

int T, W, result = -1;
int second_info[TMAX], DP[3][TMAX][WMAX];

// void solution(bool tree, int move, int get_in, int sec) // 완전탐색
// {
	
// 	if(move > W || sec > T ) return;
// 	if(!tree && second_info[sec] == 1) get_in++;
// 	else if(tree && second_info[sec] == 2) get_in++;
// 	result = max(get_in, result);
// 	solution(tree, move, get_in, sec+1);
// 	solution(!tree, move+1, get_in, sec+1);
// }
int main()
{
	cin >> T >> W;
	for(int i = 1; i <= T; i++)
		cin >> second_info[i];
	
	for(int i = 1; i <= T; i++)
	{
		for(int j = 1; j <= W+1; j++)
		{
			if(second_info[i] == 1)
			{
				DP[1][i][j] = max(DP[1][i-1][j] + 1, DP[2][i-1][j-1] + 1);
				DP[2][i][j] = max(DP[1][i-1][j-1], DP[2][i-1][j]); 
                result = max(result, DP[1][i][j]);
			}
			else
			{
                if(i == 1 && j == 1) continue;
				DP[2][i][j] = max(DP[2][i-1][j]+1, DP[1][i-1][j-1] + 1);
				DP[1][i][j] = max(DP[2][i-1][j-1], DP[1][i-1][j]);
                result = max(result, DP[2][i][j]);
			}
		}
	}
	// solution(false, 0, 0, 0);
	cout << result << endl;
	return 0;
}