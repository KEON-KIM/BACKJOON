// #1253
// @Reference imnotabear <https://imnotabear.tistory.com/382>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 2001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N;
int board[MAX];
int main() {
    cin>>N;
    int result = 0, val;
    FOR(i, N)
        cin>>board[i];

    sort(board, board+N);
    FOR(i, N){
        val = board[i]; 
        int l = 0, r = N-1, sum;
        while(l < r)
        {
            sum = board[l] + board[r];
            if(sum == val){ 
                if(l != i && r != i){
                    result++;
                    break;
                }
                else if(l == i) l++;
                else if(r == i) r--;
            }
            else if(sum < val) l++;
            else r--;
        }
    }

    cout << result;
    return 0;
}