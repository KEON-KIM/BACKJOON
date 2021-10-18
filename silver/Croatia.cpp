#include<iostream>
#include<string>
using namespace std;

int result = 0;

bool word_check(string::iterator iter, string::iterator &cursor)
{
	string first[8] = {"c-", "c=", "dz=", "d-", "lj", "nj", "s=", "z="};
	string ans = "";
	ans += *iter;
	ans += *++iter;
	while(ans.size() <= 3)
	{
		for(int i = 0; i < 8; i++){
			if(ans == first[i]) {
				cursor = iter;
				return true;
			}
		}
		ans += *++iter;
	}
	return false; // end();
}
int main()
{
	string str;
	cin >> str;

	string::iterator iter;
	string::iterator cursor;
	iter = str.begin();
	while(iter != str.end())
	{
		if(word_check(iter, cursor)) {result++; iter = cursor;}
		else result ++;
		iter++;
	}
	cout << result << endl;

	return 0;
}