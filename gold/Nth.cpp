#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 2550000

using namespace std;
int n;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> board(MAX);
	cin >> n;
	for(int i = 0; i < n*n; i++)
		cin >> board[i];
	sort(board.begin(), board.end(), greater<int>());
	cout << board[n-1] << endl;
	return 0;
}