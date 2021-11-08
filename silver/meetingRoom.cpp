//#

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N; 
vector<pair<int, int>> timeboard;

int main()
{
	int a, b, endTime, answer = 1;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> a >> b;
		timeboard.push_back(make_pair(b, a));
	}

	sort(timeboard.begin(), timeboard.end());

	endTime = timeboard[0].first;
	for(int i = 1; i < N; i++)
	{
		if(timeboard[i].second >= endTime){
			answer++;
			endTime = timeboard[i].first;
		}
	}

	cout << answer << endl;

	return 0;

}

