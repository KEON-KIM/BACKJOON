// #1083
#include <iostream>

#define MAX 51
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
int N, S, board[MAX], cnt = 0;
bool flag = false;

void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void bubble(int idx)
{
	int max = board[idx];
	int maxIdx = idx;
	for(int i = idx + 1; i < N; i++)
		if(S - (i - idx) >= 0)
			if(max < board[i])
			{
				max = board[i];
				maxIdx = i;
			}

	for(int i = maxIdx; i > idx; i--)
		swap(board[i], board[i-1]);

	S -= (maxIdx - idx);

	if(S <= 0)
		flag = true;	
}

int main()
{
	cin >> N;
	FOR(i, N)
		cin >> board[i];

	cin >> S;
	FOR(i, N)
		if(!flag)
			bubble(i);
		
	FOR(i, N)
		cout << board[i] << " ";
	cout << endl;
}