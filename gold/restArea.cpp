
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M, L;
vector<int> board;
int main() {
    fastio;
    int l, r, mid, result = 1000; // 최대 값
    cin >> N >> M >> L;

    board.push_back(0);
    board.push_back(L);
  
    FOR(i, N)
    {
    	int n;
    	cin >> n;
        board.push_back(n);
    }

    sort(board.begin(), board.end());

    l = 1;
    r = L - 1;
    while(l <= r) {
        int rest = 0; 
        mid = (l + r) / 2;
        FOR(i, board.size()){
        	if(!i) continue;
            int dist = board[i] - board[i - 1];
            int cnt = dist / mid;

            if(cnt > 0) 
            { 
                if(dist % mid == 0) rest += cnt - 1;
                else rest += cnt;
            }
        }

        if(rest > M) l = mid + 1;
        else 
        {
            r = mid - 1;
            result = min(result, mid);
        }
    }

    cout << result;

    return 0;
}