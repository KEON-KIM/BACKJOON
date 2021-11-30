// #2470 TwoPoints Algorithms
// @Reference jaimemin <https://jaimemin.tistory.com/680>
#include <iostream>
#include <algorithm>
#define MAX_SIZE 100001
#define MAX 1000000001;

using namespace std;

int board[MAX_SIZE], n;
pair<int ,int> node;

void solution()
{
	int sum;
	int i = 0, j = n-1;
	node.first = MAX; node.second = MAX;
	while( i < j)
	{
		sum = board[i] + board[j];
		if(abs(node.first + node.second) > abs(sum)){
			node.first = board[i];
			node.second = board[j];
		}

		if(sum < 0)
			i++;
		else
			j--;
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> board[i];
	sort(board, board+n); // sort for using twopoints algorithm
 	solution();

 	cout << min(node.first, node.second) << " " << max(node.first, node.second)<< endl;
	return 0;
}