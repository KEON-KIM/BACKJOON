// 15683
#include <iostream>

#define INF 987654321
#define endl '\n'

using namespace std;
 
struct CCTV
{
    int type, r, c;
};

int N, M;
int  board[8][8];
int cctv_size, result = INF;
const int rotation[6] = { 0, 4, 2, 4, 4, 1 };  // 0, 1, 2, 3, 4, 5번 카메라.
CCTV cctv[8];
 
void board_cpy(int desc[8][8], int src[8][8])
{
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < M; ++c)
            desc[r][c] = src[r][c];
}

void update(int dir, CCTV cctv)
{
    dir %= 4;   
    if (dir == 0)            // 동쪽
    {
        for (int c = cctv.c + 1; c < M; ++c)
        {
            if (board[cctv.r][c] == 6) break;
            board[cctv.r][c] = -1;
        }
    }
    else if (dir == 1)    // 북쪽
    {
        for (int r = cctv.r - 1; r >= 0; --r)
        {
            if (board[r][cctv.c] == 6) break;
            board[r][cctv.c] = -1;
        }
    }
    else if (dir == 2)    // 서쪽
    {
        for (int c = cctv.c - 1; c >= 0; --c)
        {
            if (board[cctv.r][c] == 6) break;
            board[cctv.r][c] = -1;
        }
    }
    else if (dir == 3)    // 남쪽
    {
        for (int r = cctv.r + 1; r < N; ++r)
        {
            if (board[r][cctv.c] == 6) break;
            board[r][cctv.c] = -1;
        }
    }
}
void DFS(int cctv_idx)
{
    if (cctv_idx == cctv_size)
    {
        int cnt = 0;
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < M; ++c)
            {
                if (board[r][c] == 0)
                    ++cnt;
            }
        }
        if (result > cnt)
            result = cnt;
        return;
    }
    int backup[8][8];
    int type = cctv[cctv_idx].type;
 
    for (int dir = 0; dir < rotation[type]; ++dir)
    {
        board_cpy(backup, board);
 
        if (type == 1)         
        {
            update(dir, cctv[cctv_idx]);
        }
        else if (type == 2)       
        {
            update(dir, cctv[cctv_idx]);
            update(dir + 2, cctv[cctv_idx]);
        }
        else if (type == 3)       
        {
            update(dir, cctv[cctv_idx]);
            update(dir + 1, cctv[cctv_idx]);
        }
        else if (type == 4)       
        {
            update(dir, cctv[cctv_idx]);
            update(dir + 1, cctv[cctv_idx]);
            update(dir + 2, cctv[cctv_idx]);
        }
        else if (type == 5)       
        {
            update(dir, cctv[cctv_idx]);
            update(dir + 1, cctv[cctv_idx]);
            update(dir + 2, cctv[cctv_idx]);
            update(dir + 3, cctv[cctv_idx]);
        }
 
        DFS(cctv_idx + 1);
        board_cpy(board, backup);
    }
}
 
int main()
{
    cin >> N >> M;
    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < M; ++c)
        {
            cin >> board[r][c];
            if (board[r][c] != 0 && board[r][c] != 6)
            {
                cctv[cctv_size].r = r;
                cctv[cctv_size].c = c;
                cctv[cctv_size].type = board[r][c];
                ++cctv_size;
            }
        }
    }

    DFS(0);
    cout << result << endl;
    return 0;
}

	/*#include <iostream>
	#include <vector>

	#define FOR(i, n) for(int i = 0; i < n; i++)
	using namespace std;

	int N, M, zeroCnt = 0;
	int board[9][9];
	bool visited[9][9];
	int dxdy[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	vector<pair<int, int>> camSet[6];


	int dfs(int x, int y, int dir)
	{
		int dx = x + dxdy[dir][0];
		int dy = y + dxdy[dir][1];
		if(dx < 0 || dy < 0 || dx >= N || dy >= M || board[dx][dy] == 6) return 0;
		if(!visited[dx][dy] && !board[dx][dy])
			return dfs(dx, dy, dir) + 1;
		else
			return dfs(dx, dy, dir);
	}
	void visit(int x, int y, int dir)
	{
		int dx = x + dxdy[dir][0];
		int dy = y + dxdy[dir][1];
		if(dx < 0 || dy < 0 || dx >= N || dy >= M || board[dx][dy] == 6) return;
		visited[dx][dy] = true;
		// cout << x << "/"<< y << endl;
		visit(dx, dy, dir);
	}

	int main()
	{
		cin >> N >> M;

		FOR(i, N)
		{
			FOR(j, M)
			{
				int x; cin >> x;
				if(x > 0 && x != 6)
				{
					camSet[x].push_back({i, j});
					board[i][j] = x;
				}
				else
				{
					board[i][j] = x;
					if(!x) zeroCnt++;
				}
			}
		}
		// cout << "ZERO : " << zeroCnt << endl;
		for(int i = 5; i >= 1; i--)
		{
			FOR(j, camSet[i].size())
			{
				int idx = 0, cmp = 0;
				int x = camSet[i][j].first;
				int y = camSet[i][j].second;
				if(i == 5)
				{
					int cnt = 0;
					for(int k = 0; k < 4; k++)
					{
						visited[x][y] = true;
						cnt += dfs(x, y, k);
						visit(x, y, k);
					}
					zeroCnt -= cnt;
				}
				else if(i == 4)
				{
					for(int t = 0; t < 4; t++)
					{
						int cnt = 0;
						for(int k = t; k < t + 3; k++)
						{
							int tmp = k%4;
							cnt += dfs(x, y, tmp);
						}
						if(cmp < cnt)
						{
							cmp = cnt;
							idx = t;
						}
					}

					for(int k = idx; k < idx + 3; k++){
						int tmp = k%4;
						visited[x][y] = true;
						visit(x, y, tmp);
					}
					zeroCnt -= cmp;
				}
				else if(i == 3)
				{
					for(int t = 0; t < 4; t++)
					{
						int cnt = 0;
						for(int k = t; k < t + 2; k++)
						{
							int idx = k%4;
							cnt += dfs(x, y, idx);
						}
						if(cmp < cnt)
						{
							cmp = cnt;
							idx = t;
						}
					}

					for(int k = idx; k < idx + 2; k++){
						int tmp = k%4;
						visited[x][y] = true;
						visit(x, y, tmp);
					}
					zeroCnt -= cmp;
				}
				else if(i == 2)
				{
					for(int t = 0; t < 2; t++)
					{
						int cnt = 0;
						cnt += dfs(x, y, t);
						cnt += dfs(x, y, t+2);
						if(cmp < cnt)
						{
							cmp = cnt;
							idx = t;
						}
					}
					visited[x][y] = true;
					visit(x, y, idx);
					visit(x, y, idx + 2);
					zeroCnt -= cmp;
				}
				else
				{
					for(int t = 0; t < 4; t++)
					{
						int tmp = dfs(x, y, t);
						if(cmp < tmp)
						{
							cmp = tmp;
							idx = t;
						}
					}
					// cout << "CMP : " << cmp << " IDX : " << idx << endl;
					visit(x, y, idx);
					zeroCnt -= cmp;
				}
				// cout << "CMP : " << cmp << " IDX : " << idx << endl;
			}
		}
		cout << zeroCnt << endl;
		return 0;
	}*/