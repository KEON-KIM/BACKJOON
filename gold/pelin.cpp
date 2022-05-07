//#1695
//@Reference stillchobo <https://stillchobo.tistory.com/105>
#include <iostream>

#define MAX 5002
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N;
int board[MAX];
int dp[MAX][MAX];
int pelin(int a, int b)
{
    if(dp[a][b] != -1) return dp[a][b];
    if(a >= b)
    {
        dp[a][b] = 0;
        return dp[a][b];
    }
    
    if(board[a] == board[b]) dp[a][b] = pelin(a+1, b-1);
    else dp[a][b] = min(pelin(a, b-1), pelin(a+1, b)) + 1;
    
    return dp[a][b];
}

int main()
{
    cin >> N;
    FOR(i, N)
    {
        cin >> board[i];
        FOR(j, N)
            dp[i][j] = -1;   //Init;
    }
    
    FOR(i, N-1)
        for(int j = i+1; j < N; j++)
            pelin(i, j);
        
    cout << dp[0][N-1];

    return 0;
}