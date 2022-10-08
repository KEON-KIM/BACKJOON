#include <algorithm>
#include <iostream>
#include <string>
#include <map>

#define INF 987654321
#define MOD 1000000007
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;
ll pow(int n, int k)
{
	ll result = n;
	cout << n << "/" << k << endl;
	while(--k)
		result = (result%MOD * n%MOD)%MOD;

	return result;
}
int solution(string str, int k)
{
	ll result = 0;
	int cursor = 0;
	map<char, int> map;
	FOR(i, str.length() - k + 1)
	{
		cout << "============= RESUTL : " << result << endl;
 		ll sum = 0;
		if(i == 0)
			for(int j = i; j < i + k; j++)
				map[str[j]]++;
		else
		{
			cout << str[i - 1] << "/" << str[i+k-1] << endl;
			map[str[i-1]]--; // 이전 값 삭제
			map[str[i+k-1]]++; // 다음 값 추가
		}
		for(auto it : map) // map 순회
		{ 
			if(!it.second) continue;
			cout << it.first << "/" << it.second<<endl;
			sum = (sum%MOD + pow(it.first - 'a' + 1, it.second)%MOD)%MOD;
		}
		result = max(result, sum);
	}
	return result;
}
int main()
{
	int k 
		// = 3;
		= 5;
	string str 
		// = "dcccd";
		= "aazazzzdazzkazk";

	cout << solution(str, k);
	return 0;
}