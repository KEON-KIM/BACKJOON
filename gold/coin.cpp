// #9084
#include <iostream>

#define MAX 10001
#define COIN 21

using namespace std;

int main()
{
    int n, m;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        int coin[COIN] = {0,};
        for (int j = 1; j <= m; j++)
            cin >> coin[j];
      
        int dest;
 		int board[MAX] = {1};
        cin >> dest;

        for (int j = 1; j <= m; j++) 
            for (int k = coin[j]; k <= dest; k++) 
                board[k] += board[k - coin[j]];
            
        
        cout <<  board[dest] << endl;
    }
 
    return 0;
}