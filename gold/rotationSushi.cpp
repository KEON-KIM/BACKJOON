//#15961
#include <iostream>
#include <deque>
#include <algorithm>

#define VAL 3002
#define MAX 3000002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, D, K, C, result;
int board[MAX], visited[VAL];
deque<int> dQue;
void print()
{
	cout << "============== RESULT : " << result << endl;
	FOR(i, D)
		cout << visited[i] << " ";
	
	cout << endl;
}
int main(){
	fastio;
	cin >> N >> D >> K >> C;
	FOR(i, N)
		cin >> board[i];

	int cnt = 0;
	FOR(i, K) // Init
	{
		dQue.push_back(board[i]);
		if(!visited[board[i]]++)		
			cnt++;
	}

	FOR(i, N)
	{
		int idx = (i+K)%N;
		dQue.pop_front();
		if(!--visited[board[i]]) cnt--; // 맨 앞 주문 제거

		dQue.push_back(board[idx]); // 주문 추가
		if(!visited[board[idx]]++)// 중복 확인
			cnt++;

		if(!visited[C]) 
			result = max(result, cnt+1); // 쿠폰확인
		else
			result = max(result, cnt);
	}
	
	cout << result << endl;

	return 0;
}