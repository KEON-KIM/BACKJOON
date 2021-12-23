#include <iostream>
#include <queue>
#define MAX 1000002

using namespace std;
int F, S, G, U, D, board[MAX];

int main()
{
	queue<int> Que; //x, cost
	cin >> F >> S >> G >> U >> D;

	for(int i = 1; i <= F; i++)
		board[i] = MAX; 

	board[S] = 0;

	Que.push(S);
	int cur = 1;
	while(!Que.empty())
	{
		int cur = Que.front();
		Que.pop();

		if(cur == G) break;
		if(cur+U <= F && board[cur+U] > board[cur]+1){
			board[cur+U] = board[cur] +1;
			Que.push(cur+U);
		}

		if(cur-D > 0 && board[cur-D] > board[cur]+1)
		{
			board[cur-D] = board[cur]+1;
			Que.push(cur-D);
		}
	}

	if(board[G] == MAX) cout << "use the stairs" << endl;
	else cout << board[G] << endl;

	return 0;
}