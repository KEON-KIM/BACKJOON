// #2110
// @Reference mygumi <https://mygumi.tistory.com/301>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX 200001

using namespace std;
typedef long long ll;

int N, C;
ll home[MAX], result = 0;
void Search()
{
	int s = 1;
	int e = home[N-1] - home[0];
	int dis = 0;

	while(s <= e)
	{
		int mid = (s + e) / 2;
		int start = home[0];
		int count = 1;

		for(int i = 1; i < N; i++){
			dis = home[i] - start;
			if(mid <= dis)
			{
				count++;
				start = home[i];
			}
		}

		if(count >= C)
		{
			result = mid;
			s = mid+1;
		}
		else
			e = mid-1;
	}
}

int main()
{
	cin >> N >> C;
	int addr, E = -1;

	for(int i = 0; i < N; i++)
		cin >> home[i];
	sort(home, home+N);

	Search();

	cout << result << endl;
	return 0;
}