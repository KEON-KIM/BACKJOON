
#include <iostream>
#include <queue>
#include <string>
using namespace std;
 
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
 
int n, m;
int map[1000][1000];
bool visit[1000][1000][2];
 
queue<pair<pair<int, int>, pair<int, int>>> q;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> n >> m;
 
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
 
        for (int j = 0; j < m; j++)	
        {
            map[i][j] = str[j] - '0';
        }
    }
 
    q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
 
    int min = -1;
    visit[0][0][0] = true;
 
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second.first;
        int dist = q.front().second.second;
 
        q.pop();
        if (x == n - 1 && y == m - 1)
        {
        	cout << "WHAT?1" << endl;
            min = dist;
            break;
        }
 
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)
            {	
        		cout << "WHAT?2" << endl;
                if (map[next_x][next_y] == 1 && time == 0)
                {
                    visit[next_x][next_y][time + 1] = true;
                    q.push(make_pair(make_pair(next_x, next_y), make_pair(time + 1, dist + 1)));
                }
                else if (map[next_x][next_y] == 0 && visit[next_x][next_y][time] == false)
                {
                    visit[next_x][next_y][time] = true;
                    q.push(make_pair(make_pair(next_x, next_y), make_pair(time, dist + 1)));
                }
            }
        }
    }
 
    cout << min << "\n";
 
    return 0;
}