//#1759
#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

#define MAX 16
#define endl "\n"

using namespace std;

int N, M;
vector<pair<char, pair<int, int>>> str;
// char consonant[5] = {'a', 'e', 'i', 'o', 'u'};
string vowel ="aeiou";



void make_pass(int vowel, int cons, int index, string cache)
{
	if(cache.size() == N && vowel > 0 && cons > 1){
		cout << cache << endl;
		return;
	}
	else if(cache.size() > N) return;

	else
	{
		for(int i = index; i < M; i++)
		{
			cache += str[i].first;
			vowel += str[i].second.first;
			cons += str[i].second.second;
			make_pass(vowel, cons, i+1, cache);
			cache.erase(cache.end() - 1);
			vowel -= str[i].second.first;
			cons -= str[i].second.second;
		}
	}
}

int main()
{
	cin >> N >> M;
	// priority_queue<char> PQ;
	string cache = "";
	// string :: iterator iter;
	char input;

	for(int i =0; i < M; i++){
		cin >> input;
		int iter = vowel.find(input);
		if(iter < 0) 
			str.push_back(make_pair(input,make_pair(0,1)));
		else
			str.push_back(make_pair(input,make_pair(1,0)));
	}

	sort(str.begin(), str.end());

	make_pass(0, 0, 0, cache);
	// for(int i = 0; i < str.size(); i++)
	// {
	// 	cout << str[i].first << "|" << str[i].second<< endl;
	// }

	// for(int i = 0; i <= M - N; i++)	


	return 0;
}