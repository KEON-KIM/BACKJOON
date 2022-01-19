// #10216
// @Reference jaehoon0124 <https://jaehoon0124welcome.tistory.com/195>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

#define NETSIZE 3001
#define MAX 5001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"

using namespace std;

int T, N, result;
int board[MAX][MAX]; // vistied;
vector<pair<pair<int, int>, int>> network;

void masking(int x, int y, int r, int idx)
{
	bool flag = false;
	for(int i = x - r; i <= x + r; i++)
	{
		for(int j = y - r; j <= y + r; j++){
			if(i >= MAX || i < 0 || j >= MAX || j < 0 ) continue;
			if(board[i][j]){
				idx = min(idx, board[i][j]);
				flag = true;
			}
			board[i][j] = idx;
		}
	}

	if(flag) result--;
}

int main()
{
	fastio;
	cin >> T;

	FOR(i, T){
		memset(board, 0, sizeof(board));
		network.clear();

		cin >> N;
		FOR(j, N)
		{
			int x, y, r;
			cin >> x >> y >> r;
			network.push_back(make_pair(make_pair(x, y), r));
		}
		sort(network.begin(), network.end());
		result = network.size();
		FOR(j, N)
		{
			int x = network[j].first.first;
			int y = network[j].first.second;
			int r = network[j].second;

			masking(x, y, r, j+1);
		}

		cout << result << endl;
	}

	return 0;
}

/*
ANSWER : 
int T, N, x[MAX], y[MAX], R[MAX], par[MAX];
int dist(int i, int j) {
    return(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

bool able(int i, int j) {
    if (dist(i, j) > (R[i] + R[j]) * (R[i] + R[j]))return false;
    else return true;
}
 
int find(int x) {return par[x] == x ? x : par[x] = find(par[x]);}
 
int main() {
    fastio;
    cin >> T;
    FOR(t, T) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> x[i] >> y[i] >> R[i];
        }
        for (int i = 1; i <= N; i++) par[i] = i;
        for (int i = 1; i <= N - 1; i++) 
            for (int j = i + 1; j <= N; j++) 
                if (able(i, j) && find(i) != find(j)) 
                    par[find(j)] = find(i);
        
        int ans = 0;
        for (int i = 1; i <= N; i++) 
            ans += (par[i] == i);
        
        cout << ans << endl;
    }
}*/
