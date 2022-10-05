#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;

int N;//candles[MAX];
int solution(vector<int> candles)
{
	sort(candles.begin(), candles.end(), greater<int>());

	int cnt = 0;
	for(int i : candles)
	{
		if(candles[0] == i) cnt++;
		else break;
	}
	return cnt;
}
int main()
{
	vector<int> candles = {4, 4, 1, 3};
	cout << solution(candles);

	return 0;
}