#include<iostream>
#define MAX 10001
#define FOR(i, n) for(int i = 1; i <= n; i++)

using namespace std;
int N, K;
int coin[101], board[MAX];

int main() {
    cin >> N >> K;
    FOR(i, N)
        cin >> coin[i];
    
    board[0] = 1;
    FOR(i, N)
        FOR(j, K)
            if(j >= coin[i])
                board[j] += board[j - coin[i]];
            
        
    cout << board[K] << endl;

    return 0;
}