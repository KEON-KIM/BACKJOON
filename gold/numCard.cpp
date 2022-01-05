// #2591
#include <iostream>
#include <string>

using namespace std;

string str;
int dp[41][3];
void solution()
{
    cin >> str;
    int len = str.size();
    int prev = (str[0] - '0') * 10;

    dp[1][1] = 1;
 
    for (int i = 2; i <= len; i++) {
        int v = str[i - 1] - '0';
        if (v == 0) {
            if (prev + v <= 34) {
                dp[i][2] = dp[i - 1][1];  
            }
            continue;
        }
 
        if (prev + v <= 34) {
            dp[i][1] = dp[i - 1][2] + dp[i - 1][1];
            dp[i][2] = dp[i - 1][1];
        } else {
            dp[i][1] = dp[i - 1][1] + dp[i - 1][2];
        }
        prev = v * 10;
    }
    cout << dp[len][1] + dp[len][2] << endl;
}


int main()
{
	solution();
	return 0;
}