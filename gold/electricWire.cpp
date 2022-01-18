//#2565
//@Reference yabmoons <https://yabmoons.tistory.com/572>
#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define MAX 110

using namespace std;

 
int N;
int DP[MAX];
pair<int, int> wire[MAX];

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> wire[i].first >> wire[i].second;
   
}

void solution()
{
    int cur_wire = 0;
    sort(wire + 1, wire + N + 1);
    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
        for (int j = 1; j < i; j++)
            if(wire[i].second > wire[j].second){
                DP[i] = max(DP[i], DP[j] + 1);
                cout << DP[i] << endl;
            }

          
        cur_wire = max(cur_wire, DP[i]);
    }

    cout << N - cur_wire << endl;
}
 
int main(void)
{
 	input();
 	solution();
 
    return 0;
}

/*
6
1 8
2 9
4 4
5 2
6 1
7 5

5
1 4
2 1
3 5
4 2
5 3

*/