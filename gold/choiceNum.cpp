//#2230 Two Pointer
#include<iostream>
#include<algorithm>

#define MAX 100001
#define INF 2000000000
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;
ll N, M, result = INF;
ll board[MAX];

int main()
{
	int start = 0, end = 0;
	ll diff;
	
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> board[i];

	sort(board, board+N);

	while(start <= end && start < N && end < N)
	{
		if(diff >= M){
			result = min(result, diff);
			if(start == end){
				end++;
				diff = board[end] - board[start];
			}
			else
			{
				start++;
				diff = board[end] - board[start];
			}
		}
		else{
			end++;
			diff = board[end] - board[start];
		}
	}

	cout << result << endl;
	return 0;
}