//#17073
#include<iostream>
#include<vector>

#define MAX 500002
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, result = 0;
double W;

vector<int> board[MAX];
int main()
{
    fastio;
    cout.precision(11);
    
    cin >> N >> W;
    FOR(i, N-1){
        int x, y;
        cin >> x >> y;
        board[x].push_back(y);
        board[y].push_back(x);
    }
    for(int i = 2; i <= N; i++)
        if(board[i].size() == 1)
            result ++;

    cout << W/result << endl;
    return 0;
}

/*#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 500001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
vector<int> board[MAX];
bool visit[MAX];

int N, result = 0;
double W;

void bfs(int start)
{
	queue<int> Que;
	visit[start] = true;
	Que.push(start);

	while (!Que.empty()) {
		int idx = Que.front();
		bool flag = false;
		Que.pop();

		for (int i = 0; i < board[idx].size(); i++) {
			int next = board[idx][i];
			if (visit[next]) continue;
			visit[next] = true;
			Que.push(next);
			flag = true;
		}

		if (!flag)	result++;
	}
}
int main() {
	fastio;
	cout.precision(11);
	cin >> N >> W;
	FOR(i, N-1){
		int x, y;
		cin >> x >> y;
		board[x].push_back(y);
		board[y].push_back(x);
	}

	bfs(1);

	cout << W / result << endl;;

	return 0;
}*/