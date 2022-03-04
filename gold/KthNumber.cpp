// #1300
// @Reference jaimemin <https://jaimemin.tistory.com/988>
#include <iostream>
#include <cmath>
using namespace std;

int N, K;
int main()
{
	cin >> N >> K;
	int low = 1, high = K;
    int result = -1;
    while (low <= high)
    {
        int cnt = 0;
        int mid = (low + high) / 2;

        for (int i = 1; i <= N; i++)
             cnt += min(mid / i, N); 

        if (cnt < K)
            low = mid + 1;
        else
        {
         	result = mid;
		    high = mid - 1;
        }
    }

    cout << result << endl;
	return 0;
}