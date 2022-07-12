#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int Question(map<string, int> &city, vector<int> &X, vector<int> &Y, string &input)
{
	int min_idx = -1;
	int min_dist = INF;
	int idx = city[input];
	FOR(i, X.size())
	{
		if(i == idx) continue;
		if(X[idx] == X[i])
		{
			if(min_dist > abs(Y[idx] - Y[i]))
			{
				min_dist = abs(Y[idx] - Y[i]);
				min_idx = i;
			}
		}
		else if(Y[idx] == Y[i])
		{
			if(min_dist > abs(X[idx] - X[i]))
			{
				min_dist = abs(X[idx] - X[i]);
				min_idx = i;
			}
		}
	}

	return min_idx;
}

int main()
{
	vector<int> X;
	vector<int> Y;
	vector<int> answer;
	vector<string> city;
	map<string, int> city_map;

	int n, input;
	string sinput;
	cin >> n;
	FOR(i, n)
	{
		cin >> sinput;
		city_map.insert({sinput, i});
		city.push_back(sinput);
	}
	cin >> n;
	FOR(i, n)
	{
		cin >> input;
		X.push_back(input);
	}
	cin >> n;
	FOR(i, n)
	{
		cin >> input;
		Y.push_back(input);
	}
	cin >> n;
	FOR(i, n)
	{
		cin >> sinput;
		answer.push_back(Question(city_map, X, Y, sinput));
	}

	// PRINT
	for(int i : answer){
		if(i == -1) cout << "NONE" << endl;
		else cout << city[i] << endl;
	}

	return 0;
}

// Input_1
/*3
fastcity
bigbanana
xyz
3
23
23
23
3
1
10
20
3
fastcity
bigbanana
xyz*/
// Input_2
/*5
green
red
blue
yellow
pink
5
100
200
300
400
500
5
100
200
300
400
500
5
green
red
blue
yellow
pink*/