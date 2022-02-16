#include <iostream>

#define W 9
#define H 5
#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T, Min, ret;
int dxdy[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
char board[H][W];
 
void DFS(char cur[H][W], int depth) {
    int cnt = 0;
    FOR(i, H)
     	FOR(j, W)
            if (cur[i][j] == 'o') 
            	cnt++;

    if (Min > cnt) {
        Min = cnt;
        ret = depth;
    }
 
    FOR(i, H){
        FOR(j, W){
            if(cur[i][j] == 'o') {
                FOR(dir, 4){
                    int dx = i + dxdy[dir][0], dy = j + dxdy[dir][1];
                    int ddx = dx + dxdy[dir][0], ddy = dy + dxdy[dir][1];
                    if (dx < 0 || ddx < 0 || dx >= H || ddx >= H || dy < 0 || ddy < 0 || dy >= W || ddy >= W) continue;
                    if (cur[dx][dy] == 'o' && cur[ddx][ddy] == '.') {
                        cur[i][j] = '.';
                        cur[dx][dy] = '.';
                        cur[ddx][ddy] = 'o';
                        DFS(cur, depth + 1);
                        cur[i][j] = 'o';
                        cur[dx][dy] = 'o';
                        cur[ddx][ddy] = '.';
                    }
                }
            }
        }
    }
}
 
int main() {
    cin >> T;
    FOR(t, T) {
        Min = INF, ret = -1;
        FOR(i, H)
            FOR(j, W)
                cin >> board[i][j];
 
        DFS(board, 0);
        cout << Min << " " << ret << '\n';
    }
    return 0;
}
