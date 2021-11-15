// #1027
// @Reference seongjuk <https://seongjuk.tistory.com/entry/BOJ-%EB%B0%B1%EC%A4%80-1027%EB%B2%88-%EA%B3%A0%EC%B8%B5-%EA%B1%B4%EB%AC%BC>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

int N, result = 0;
ll CITY[52];

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> CITY[i];

	for(int i = 1; i <= N; i++)
	{
		ll left = i - 1;
		ll right = i + 1;

		int cnt = 0;
		// left
		for(int j = i-1; j > 0; j--)
		{
			if( j == i - 1) {
				cnt ++;
				continue;
			}
			ll dist1 = i - j;
			ll height1 = CITY[i] - CITY[j];
			ll dist2 = i - left;
			ll height2 = CITY[i] - CITY[left];
			if(dist2 * height1 < dist1 * height2)
			{
				left = j;
				cnt++;
			}
		}
		// left
		for(int j = i+1; j <= N; j++)
		{
			if( j == i + 1) {
				cnt ++;
				continue;
			}
			ll dist1 = i - j;
			ll height1 = CITY[i] - CITY[j];
			ll dist2 = i - right;
			ll height2 = CITY[i] - CITY[right];
			if(dist2 * height1 > dist1 * height2)
			{
				right = j;
				cnt++;
			}
		}
		result = max(cnt, result);
	}
	cout << result << endl;

	return 0;
}