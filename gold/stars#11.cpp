#include<iostream>

#define HMAX 3072 + 1
#define WMAX 6144 + 1
#define endl '\n'
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define RFOR(i, n) for(int i = n; i > 0; i--)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M; 
bool board[HMAX][WMAX];

void Stars(int H, int W)
{

	cout << "H : " << H << " W : " << W << endl;
	board[H][W] = true;
	board[H+1][W-1] = board[H+1][W+1] = true;
	for(int i = W - 2; i < W + 3; i++)
	{
		board[H+2][i] = true;
	}
}
void print()
{
	FOR(i, N)
	{
		FOR(j, M)
		{
			if(board[i][j])
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
}
void Recursion(int height, int width, int mod)
{
	int h = height + mod/2;
	int maxWidth = ((mod/3)*(5+1));

	if(mod/3 == 1)
		Stars(height, width);

	else
	{
		Recursion(height, width, mod/2); // 1
		Recursion(h, width - mod/2, mod/2); // 2
		Recursion(h, width + mod/2, mod/2); // 3
	}
	

}
int main()
{
	cin >> N;
	M = ((N/3)*(5+1))-1;
	Recursion(1, N, N);
	print();
	return 0;
}