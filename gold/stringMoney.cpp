// #17828 
// @Reference codechan25 <https://codechan25.tistory.com/11>
#include <iostream>
#include <algorithm>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
int N, M;
string result = "";
void Solution()
{
    FOR(i, N)
    {
        int temp = N - i - 1;
        if (M - temp > 26)
        {
            result += 'Z';
            M -= 26;
        }
        else
        {
            result += (M - temp + 64);
            M -= (M - temp);
        }
    }
    reverse(result.begin(), result.end());
}

int main(void)
{
	cin >> N >> M;
	if (N * 26 < M || M < N)
		cout << "!";
    
	else 
    {
        Solution();
        cout << result << endl;
    }
    
	return 0;
}