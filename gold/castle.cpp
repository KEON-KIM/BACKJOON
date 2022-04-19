//2234
#include <iostream>
#include <bitset>
#include <queue>

#define MAX 52
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef pair<int, int> pii;

int N, M, maxi = -1, maxIdx = 0;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dxdy[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

vector<vector<pii>> answer;
void bfs(int idx, int startX, int startY)
{
    queue<pii> Que;
    Que.push({startX, startY});
    answer[idx].push_back({startX, startY});
    visited[startX][startY] = true;

    while(!Que.empty())
    {
        int x = Que.front().first;
        int y = Que.front().second;
        bitset<4> b(board[x][y]);
        Que.pop();

        FOR(i, 4)
        {
            if(!b[i])
            {
                int dx = x + dxdy[i][0];
                int dy = y + dxdy[i][1];

                if(dx < 0 || dy < 0 || dx >= N || dy >= M || visited[dx][dy]) continue;
                visited[dx][dy] = true;
                Que.push({dx, dy});
                answer[idx].push_back({dx, dy});
            }
        }

        board[x][y] = idx;
    }
    int size = answer[idx].size();  
    if(maxi < size)
    {
        maxi = size;
        maxIdx = idx;
    }
}
void print()
{
    FOR(i, N){
        FOR(j, M)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
int Solution()
{
    int maxCnt = -1;
    FOR(i, answer.size())
        FOR(j, answer[i].size())
        {
            int x = answer[i][j].first;
            int y = answer[i][j].second;

            FOR(k, 4)
            {
                int dx = x + dxdy[k][0];
                int dy = y + dxdy[k][1]; 
                if(dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
                if(board[dx][dy] != i)
                {
                    int left = answer[board[dx][dy]].size();
                    int right = answer[i].size();
                    maxCnt = max(maxCnt, left + right);
                }
            }
        }

    return maxCnt;
}

int main()
{
    cin >> M >> N;
    FOR(i, N)
        FOR(j, M)
            cin >> board[i][j];

    int cnt = 0;
    FOR(i, N)
        FOR(j, M)
            if(!visited[i][j])
            {
                vector<pii> tmp;
                answer.push_back(tmp);
                bfs(cnt, i, j);
                cnt++;
            }

    cout << cnt << endl;
    cout << maxi << endl;
    cout << Solution() << endl;

    
    return 0;
}