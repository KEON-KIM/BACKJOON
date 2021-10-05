#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

pair<int, int> solution(int n)
{
	vector<pair<int, int>> temp = {{1,0}, {0,1} };
	for(int i = 2; i <= n; i++)
		temp.push_back(make_pair(temp[i-1].first+temp[i-2].first, temp[i-1].second+temp[i-2].second));
	

	return  temp[n];
}
int main()
{
	int N;
	cin >> N;
	int cache[N];
	vector<pair<int, int>> answerSet;

	for(int i = 0; i < N; i++)
	{
		cin >> cache[i];
		answerSet.push_back(solution(cache[i]));
	}

	for(pair<int, int> temp : answerSet)
		cout << temp.first << ' ' << temp.second << endl;
	
	
	return 0;
}