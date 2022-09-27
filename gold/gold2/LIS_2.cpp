//#12015
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 1000001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int N, board[MAX];
vector<int> result;
int lower_bound(vector<int> &arr, int key)
{
    int l = 0;
    int r = arr.size()-1;

    while(r > l)
    {
        int mid = (r + l)/2;
        if(key > arr[mid])
            l = mid+1;
        else
        	r = mid;
    }
    return r;
}
 
int main()
{
	fastio;
    cin >> N;

    FOR(i, N)
        cin >> board[i];
    
    int cnt = 1;
    result.push_back(board[0]);
    FOR(i, N)
    {
        if(result.back() < board[i])
        {
            result.push_back(board[i]);
            cnt++;
        }
        else
        {
            int idx = lower_bound(result, board[i]);
            result[idx] = board[i];
        }
    }
    
    cout << cnt;
    
    return 0;
}