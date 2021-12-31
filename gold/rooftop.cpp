//#6198
#include<iostream>
#include<stack>
#define MAX 80001

using namespace std;

long long N, building[MAX], bigger = 0, answer =0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<int , int>> S;

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> building[i];
		bigger = max(building[i], bigger);
	}

	S.push(make_pair(bigger,N));

	int cur = N-1;
	for(int i = N-1; i >= 0; i--)
	{
		while(!S.empty()){
			if(S.top().first >= building[cur]){
				answer += S.top().second - i - 1;
				break;
			}
			S.pop();
		}
		S.push(make_pair(building[cur], i));
		cur--;
	}

	cout << answer << endl;
	return 0;
}
	// {
	// 	for(int j = i+1; j < N; j++)
	// 	{
	// 		if(building[i] <= building[j]) break;
	// 		answer++;	
	// 	}
	// }
// }