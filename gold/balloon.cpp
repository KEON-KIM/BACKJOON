//#11509
#include<iostream>

#define MAX 1000002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

int N, result = 0;
int arrows[MAX];
/*pair<int, bool> balloons[MAX];
int main()
{
	fastio;
	cin >> N;

	FOR(i, N)
		cin >> balloons[i].first;

	int cnt = 0;
	FOR(i, N){
		if(balloons[i].second) continue;
		if(cnt == N) break;

		int cur = balloons[i].first;
		result += 1;
		for(int j = i; j < N; j++){
			if(balloons[j].second || cur == 0) continue;
			if(cur == balloons[j].first){
				cur--;
				cnt++;
				balloons[j].second = true;
			}
		}
	}

	cout << result << endl;
	return 0;
}*/
int main()
{
	fastio;
	cin >> N;

	int height;
	FOR(i, N){
		cin >> height;
		if(!arrows[height+1])
		{
			arrows[height]++;
			result ++;
		}
		else
		{
			arrows[height+1]--;
			arrows[height]++;
		}
	}

	cout << result << endl;
	return 0;
}

