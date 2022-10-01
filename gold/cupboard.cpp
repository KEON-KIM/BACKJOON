#include<iostream>
#include<vector>
#define MAX 21
#define INF 987654321
using namespace std;

int N, T, result = INF;
int cmd[MAX];

void dfs(int x1, int x2, int move, int cnt)
{
	if(cnt == T) {result = min(move, result); return;}
	if(abs(cmd[cnt] - x1) > abs(cmd[cnt] - x2))
		dfs(x1, cmd[cnt], move + abs(cmd[cnt] - x2), cnt +1);

	else if(abs(cmd[cnt] - x1) < abs(cmd[cnt] - x2))
		dfs(cmd[cnt], x2, move + abs(cmd[cnt] - x1), cnt +1);

	else
	{
		dfs(x1, cmd[cnt], move + abs(cmd[cnt] - x2), cnt +1);
		dfs(cmd[cnt], x2, move + abs(cmd[cnt] - x1), cnt +1);
	}

}
int main()
{
	int x1, x2;
	cin >> N;
	cin >> x1 >> x2;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> cmd[i];
	}

	dfs(x1, x2, 0, 0);

	cout << result << endl;
	
	return 0;
}