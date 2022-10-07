#include <iostream>
#include <vector>

#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

vector<int> solution(vector<int> board) 
{
	int max_num = -1, min_num = INF;
	int max_cnt = 0, min_cnt = 0;
	FOR(i, board.size())
	{
		if(max_num < board[i]) {max_cnt++; max_num = board[i];}
		if(min_num > board[i]) {min_cnt++; min_num = board[i];}
	}
	vector<int> answer;
	answer.push_back(max_cnt-1); answer.push_back(min_cnt-1);
	return answer;
}

int main()
{
	int N, input;
	vector<int> board;
	cin >> N;
	FOR(i, N)
	{
		cin >> input;
		board.push_back(input);
	}
	vector<int> answer = solution(board);
	cout << answer[0] << ' ' << answer[1];
	return 0;
}