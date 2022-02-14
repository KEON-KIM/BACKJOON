//#3107
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define ADD_SIZE 8
using namespace std;

char IPv6[8][4];
vector<string> cache;
void Print()
{
	FOR(i, 8){
		FOR(j, 4)
			cout << IPv6[i][j];
		if(i < ADD_SIZE-1)
			cout << ":";
	}
}

void Init()
{
	FOR(i, 8)
		FOR(j, 4)
			IPv6[i][j] = '0';
}

void Input()
{
	string input;
	cin >> input;
	string tmp = "";
	FOR(i, input.length()){
		if(input[i] == ':'){
			if(i + 1 < input.length() && input[i+1] == ':'){
				cache.push_back(tmp);
				tmp = "";
				i++;
			}
			cache.push_back(tmp);
			tmp = "";
			continue;
		}
		tmp+=input[i];
	}
	cache.push_back(tmp);

	if(cache[0] == "")
		cache.erase(cache.begin()+1);
	else if(cache[cache.size()-1] == "")
		cache.erase(cache.end()-1);
}
void Solution()
{
	for(int i = 0, idx = 0; i < cache.size() && idx < ADD_SIZE; i++, idx++)
	{
		if(!cache[i].length())
			idx += (ADD_SIZE - cache.size());
		else
		{
			int k = 3;
			for(int j = cache[i].length()-1; j >= 0; j--)
			{
				IPv6[idx][k] = cache[i][j];
				k--;
			}
		}
	}
}

int main()
{
	Init();
	Input();
	Solution();
	Print();
	return 0;
}