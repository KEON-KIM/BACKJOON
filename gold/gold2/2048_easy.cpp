//#12100
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

#define FOR(i, a, n) for(int i = a; i < n; i++)
#define RFOR(i, n) for(int i = n-1; i >= 0; i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, answer = -1;
void print(vector<vector<int>> board)
{
	cout << "============" << endl;
	FOR(i, 0, N)
	{
		FOR(j, 0, N)
			cout << board[i][j] << ' ';
		cout << endl;
	}
}

int getMax(vector<vector<int>> board)
{
    int res = -1;
    FOR(i, 0, N)
    	FOR(j, 0, N)
            res = max(res, board[i][j]);

    return res;
}

vector<vector<int>> left(vector<vector<int>> board)
{
	FOR(i, 0, N)
    {
    	vector<bool> visited(N, false);
        FOR(j, 1, N)
        {
            if (board[i][j] == 0)
                continue;
            RFOR(k, j)
            {
                if (board[i][k] == board[i][k + 1] && !visited[k])
                {
                    board[i][k] *= 2;
                    board[i][k + 1] = 0;
                    visited[k] = true;
                    break;
                }
                else if (board[i][k] == 0)
                {
                    board[i][k] = board[i][k + 1];
                    board[i][k + 1] = 0;
                }
                else
                    break;
            }
        }
    }
	cout << "LEFT"; print(board);
	return board;
}

vector<vector<int>> right(vector<vector<int>> board)
{
	FOR(i, 0, N)
    {
    	vector<bool> visited(N, false);
    	RFOR(j, N-1)
        {
            if (board[i][j] == 0)
                continue;
            FOR(k, j+1, N)
            {
                if (board[i][k] == board[i][k-1] && !visited[k])
                {
                    board[i][k] *= 2;
                    board[i][k-1] = 0;
                    visited[k] = true;
                    break;
                }
                else if (board[i][k] == 0)
                {
                    board[i][k] = board[i][k-1];
                    board[i][k-1] = 0;
                }
                else
                    break;
            }
        }
    }
	cout << "RIGHT"; print(board);
	return board;
}
vector<vector<int>> up(vector<vector<int>> board)
{
	FOR(i, 0, N)
    {
    	vector<bool> visited(N, false);
        FOR(j, 1, N)
        {
            if (board[j][i] == 0)
                continue;
            RFOR(k, j)
            {
                if (board[k][i] == board[k+1][i] && !visited[k])
                {
                    board[k][i] *= 2;
                    board[k+1][i] = 0;
                    visited[k] = true;
                    break;
                }
                else if (board[k][i] == 0)
                {
                    board[k][i] = board[k+1][i];
                    board[k+1][i] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
	cout << "UP"; print(board);
	return board;
}
vector<vector<int>> down(vector<vector<int>> board)
{
	FOR(i, 0, N)
    {
    	vector<bool> visited(N, false);
    	RFOR(j, N-1)
        {
            if (board[j][i] == 0)
                continue;
            FOR(k, j+1, N)
            {
                if (board[k][i] == board[k-1][i] && !visited[k])
                {
                    board[k][i] *= 2;
                    board[k-1][i] = 0;
                    visited[k] = true;
                    break;
                }
                else if (board[k][i] == 0)
                {
                    board[k][i] = board[k-1][i];
                    board[k-1][i] = 0;
                }
                else
                    break;
            }
        }
    }
	cout << "DOWN"; print(board);
	return board;
}
void dfs(int dep, vector<vector<int>> board)
{
	answer = max(answer, getMax(board));
	if(dep == 5) return;

	dfs(dep+1, left(board));
	dfs(dep+1, right(board));
	dfs(dep+1, up(board));
	dfs(dep+1, down(board));
}

int main()
{
	fastio;
	cin >> N;

	vector<vector<int>> board(N, vector<int>(N));
	FOR(i, 0, N)
		FOR(j, 0, N)
			cin >> board[i][j];

	dfs(0, board);
	cout << answer;
	return 0;
}