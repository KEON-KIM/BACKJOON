#include <iostream>
#include <vector>

#define MAX 51
#define INF 25001
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, M, K;
int InputBoard[MAX][MAX];
int result = INF;
bool visited[6];
struct triple
{
    int x, y, z;
    triple(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
};
vector<triple> info;
vector<vector<int>> inputBoard;
void rotate(int r, int c, int s, vector<vector<int>> &board)
{
    int startX = r-s, startY = c-s;
    int endX = r+s, endY = c+s;
    int h = endX - startX + 1;
    int w = endY - startY + 1;
    int tmpBoard[MAX][MAX];
    //copy
    FOR(i, h)
        FOR(j, w)
            tmpBoard[i][j] = board[startX+i-1][startY+j-1];

    // int tmp = tmpBoard[1][1];
    // int x = 2, y = 1;
    int x = 1, y = 1;
    while(x != h && y != w)
    {
        int tmp = tmpBoard[x][y];
        for(int i = x+1; i <= h; i++)
            tmpBoard[i-1][x] = tmpBoard[i][x];
        
        for(int i = y+1; i <= w; i++)
            tmpBoard[h][i-1] = tmpBoard[h][i];

        for(int i = h-1; i > x-1; i--)
            tmpBoard[i+1][w] = tmpBoard[i][w];

        for(int i = w-1; i > y-1; i--)
            tmpBoard[y][i+1] = tmpBoard[y][i];

        tmpBoard[x][y+1] = tmp;
        h--; w--; x++; y++;
        // break;
    }

    h = (r+s) - (r-s) + 1;
    w = (c+s) - (c-s) + 1;

    FOR(i, h)
        FOR(j, w)
            board[startX+i-1][startY+j-1] = tmpBoard[i][j];
}

void dfs(int idx, int dep, vector<vector<int>> board)
{
    // cout << "dep : " << dep << endl;
    rotate(info[idx].x, info[idx].y, info[idx].z, board);
    if(dep == K) 
    {
        //print();
        // cout << "AFTER" << endl;
        // FOR(i, N)
        // {
        //     FOR(j, M)
        //         cout << board[i][j] << " ";
        //     cout << endl;
        // }
        FOR(i, N)
        {
            int cmp = 0;
            FOR(j, M)
                cmp += board[i][j];
            result = min(result, cmp);
        }
        return;
    }
    for(int i = 0; i < info.size(); i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(i,dep+1, board);
            visited[i] = false;
        }
    }
}

void Init()
{
	FOR(i, MAX){
		vector<int> tmp;
		FOR(j, MAX)
			tmp.push_back(0);
		inputBoard.push_back(tmp);
	}
}

int main()
{
	Init();
    cin >> N >> M >> K;
    FOR(i, N)
    	FOR(j, M)
    		cin >> inputBoard[i][j];
    int r, c, s;
    FOR(i, K)
    {
        cin >> r >> c >> s;
        info.push_back(triple(r, c, s));
    }

    for(int i = 0; i < info.size(); i++){
        // cout << "==== ORIGIN ====" << endl;
        // FOR(i, N)
        // {
        //     FOR(j, M)
        //         cout << inputBoard[i][j] << " ";
        //     cout << endl;
        // }
        visited[i] = true;
        dfs(i, 1,  inputBoard);
        visited[i] = false;
    }

    cout << result << endl;
    // int result = INF;
    // FOR(i, N)
    // {
    //  int cmp = 0;
    //  FOR(j, M)
    //      cmp += board[i][j];
    //  result = min(result, cmp);
    // }
    // cout << result << endl;
    return 0;
}