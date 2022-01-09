// #6987 / BACK TRACKING
// @Reference weenybeenymini <https://velog.io/@weenybeenymini/%EB%B0%B1%EC%A4%80-6987%EB%B2%88-%EC%9B%94%EB%93%9C%EC%BB%B5>
#include<iostream>
#include<vector>
#define FOR(i, N) for(int i = 0; i < N; i++)

using namespace std;

vector<pair<int, int>> teams;
int input[6][3], board[6][3], result = 0;

void dfs(int count)
{
	if(count == 15)
	{
		FOR(i, 6)
			FOR(j, 3)
				if(input[i][j] != board[i][j])
					return;
				
		result = 1;
		return;
	}

	int t0 = teams[count].first;
	int t1 = teams[count].second;

	// WIN
	board[t0][0]++;
	board[t1][2]++;
	dfs(count+1);
	board[t0][0]--;
	board[t1][2]--;

	//DRAW
	board[t0][1]++;
	board[t1][1]++;
	dfs(count+1);
	board[t0][1]--;
	board[t1][1]--;

	//LOSE
	board[t0][2]++;
	board[t1][0]++;
	dfs(count+1);
	board[t0][2]--;
	board[t1][0]--;
}

int main()
{
	FOR(i, 6)
		for(int j = i + 1; j < 6; j++)
			teams.push_back(make_pair(i, j));
		

	FOR(t, 4)
	{
		FOR(i, 6)
			FOR(j, 3){
				cin >> input[i][j];
				board[i][j] = 0;
			}
		dfs(0);
		cout << result << " ";
		result = 0;
	}

	return 0;
}

// int main()
// {
	// FOR(t, 4){
	// 	int score[3] = {0, 0, 0};
	// 	FOR(i, 6){
	// 		int cnt = 0;
	// 		FOR(j, 3){
	// 			cin >> board[i][j];
	// 			score[j] += board[i][j];
	// 			cnt += board[i][j];
	// 		}
	// 		if(cnt != 5) game[t] = 0;
	// 	}

	// 	// cout << "====== SCORE ======" << endl;
	// 	// cout << score[0] << "/ " << score[1] << " / " << score[2] << endl;
	// 	if(score[0] + score[1] + score[2] != 30) game[t] = 0;
	// 	if(score[0] != score[2]) game[t] = 0;

	// 	FOR(i,6){
	// 		if(board[i][1] && !divisor(score[1], board[i][1]))
	// 			game[t] = 0;
	// 	}
	// }

	// FOR(t, 4)
	// 	cout  << game[t] << " ";


	// return 0;
// }







