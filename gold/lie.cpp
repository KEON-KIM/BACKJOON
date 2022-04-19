//#1043
#include <iostream>
#include <queue>
#include <vector>

#define MAX 52
#define FOR(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int N, M, T;

bool knowns[MAX]; // 알고 있는 사람들
bool visited[MAX]; // 방문할 수 있는 파티?
int parties[MAX][MAX]; // 실제 파티에 참석하는 사람들 정보
vector<int> participate[MAX]; // 참석자 별 참석하는 파티들

queue<int> Que; 
void print()
{
    FOR(i, M)
    {
        cout << visited[i] << " ";
    }cout << endl;
}
int solution()
{
    int result = 0;
    while(!Que.empty())
    {
        int idx = Que.front();
        Que.pop();

        for(int nextParty : participate[idx]) // 참석하는 파티들
        {
            if(!visited[nextParty])
            {
                FOR(n, N) // 해당 파티에 참석한 사람들 인덱스
                {
                    if(!knowns[parties[nextParty][n]]){
                        knowns[parties[nextParty][n]] = true;
                        Que.push(parties[nextParty][n]);
                    }
                }
                visited[nextParty] = true;
                result++;
            }
        }
    }

    return M - result;
}
int main()
{
    cin >> N >> M >> T;

    FOR(i, T){
        int input;
        cin >> input;
        knowns[input] = true;
        Que.push(input);
    }

    FOR(i, M)
    {
        int cnt;
        cin >> cnt;

        FOR(j, cnt)
        {
            cin >> parties[i][j];
            participate[parties[i][j]].push_back(i);
        }
    }

    cout << solution() << endl;
    return 0;
}
