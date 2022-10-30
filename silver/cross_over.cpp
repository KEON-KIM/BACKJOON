//#11497
#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, M;
int main()
{
	cin >> N;
	int board[MAX];
	FOR(i, N)
	{
		cin >> M;
		int task[MAX];
		FOR(j, M)
			cin >> board[j];

		sort(board, board+M);
		int l = 0, r =  M-1;
		FOR(j, M)
		{
			if(j%2) task[r--] = board[j];
			else task[l++] = board[j];
		}
		int result = abs(task[0] - task[M-1]);
		FOR(j, M-1)
			result = max(result, abs(task[j] - task[j+1]));
		cout << result << endl;
	}
	return 0;
}
