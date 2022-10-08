#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;


int solution(vector<int> board)
{
	int group = 0;
	vector<int> sorted = board;
	sort(sorted.begin(), sorted.end());
	int s_min = INF, s_max = -1;
	int b_min = INF, b_max = -1;
	FOR(i, board.size())
	{
		s_min = min(s_min, sorted[i]);
		s_max = max(s_max, sorted[i]);
		b_min = min(b_min, board[i]);
		b_max = max(b_max, board[i]);

		if(s_min == b_min && s_max == b_max)
		{
			group++;
			s_min = INF; s_max = -1;
			b_min = INF; b_max = -1;
		}
	}
	return group;
}
int main()
{
	vector<int> board
	 // = {1, 14, 2, 13, 16, 20, 17, 18, 24};
	 = {2, 5, 1, 9, 6, 7};
	cout << solution(board);
	return 0;
}