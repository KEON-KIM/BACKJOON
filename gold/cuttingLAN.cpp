//#1654
#include<iostream>

#define MAX 10001
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long ll;

int K, N;
ll board[MAX];
ll mid, high, low = 1, result = 0;

int main()
{	
	cin >> K >> N;

	FOR(i, K){
		cin >> board[i];
		high = max(high, board[i]);
	}
	
	while(low <= high)
	{
		mid = (low + high) / 2;

		int cnt = 0;
		FOR(i, K)
			cnt += board[i] / mid;

		if(cnt >= N){
			low = mid + 1;
			result = max(result, mid);
		} 

		else 
			high = mid - 1;
	}

	cout << result << endl;

	return 0;
}