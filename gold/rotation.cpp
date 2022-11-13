#include<iostream>
#include<vector>
#define MAX 301
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M, R;
int board[MAX][MAX];
int result[MAX][MAX];
vector<int> compare;

void print(int n, int m)
{
	int minR = min(n, m);
	int key = 1;
	while(minR >= 0)
	{
		int i = key, j = key;
		while(i < n){
			cout << board[i][j] << " ";
			i++;
			// cout << "-";
		}
		while(j < m)
		{
			cout << board[i][j] << " ";
			j++;
			// cout << "-";
		}
		while(i > key)
		{
			cout << board[i][j] << " ";
			i--;
			// cout << "+";
		}
		while(j > key)
		{
			cout << board[i][j]<< " ";
			j--;
			// cout << "+";
		}
		n--;
		m--;
		key++;
		minR -= 2;
	}	
}
int main()
{
	fastio;
	cin >> N >> M >> R;
	int minR = min(N, M);
	FOR(i, N)
		FOR(j, M)
			cin >> board[i][j];

	print(N, M);
	return 0;
}