// #14890
// @Reference yabmoons <https://yabmoons.tistory.com/49>
#include<iostream>
#include<cmath>
 
#define MAX 101
using namespace std;
 
int N, L;
int MAP[MAX][MAX];
int MAP2[MAX][MAX];
void Input()
{
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            MAP2[j][i] = MAP[i][j];
        }
    }
}

bool isCheck(int A[][MAX], int x, int y)
{
    int Standard = A[x][y + 1];
    for (int j = y + 1; j < y + 1 + L; j++)
        if (A[x][j] != Standard) return false;
    
    return true;
}
 
int Make_Road(int A[][MAX])
{
    int Total_Road = 0;
    for (int i = 0; i < N; i++)
    {
        bool Can_Road = true;
        int Before_Road = 1;
        for (int j = 0; j < N - 1; j++)
        {
            if (A[i][j] == A[i][j + 1]) Before_Road++;
            else if (A[i][j] == A[i][j + 1] + 1)        
            {
                if (isCheck(A, i, j))
                {
                    j = j + L - 1;
                    Before_Road = 0;
                }
                else
                {
                    Can_Road = false;
                    break;
                }
            }
            else if (A[i][j] + 1 == A[i][j + 1]) 
            {
                if (Before_Road >= L)
                    Before_Road = 1;
                
                else
                {
                    Can_Road = false;
                    break;
                }
            }
            else if (abs(A[i][j] - A[i][j + 1]) >= 2)
            {
                Can_Road = false;
                break;
            }
        }
 
        if (Can_Road == true)
            Total_Road++;
        
    }
    return Total_Road;
}
 
void Solution()
{
    int A = Make_Road(MAP);
    int B = Make_Road(MAP2);
 
    cout << A + B << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    Solve();
    return 0;
}