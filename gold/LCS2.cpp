//#9251 
//@Reference melonicedlatte <http://melonicedlatte.com/algorithm/2018/03/15/181550.html>

#include<iostream>
#include<string>

#define MAX 1001

using namespace std;

int DP[MAX][MAX];

int main()
{
	string str, str2;
	cin >> str;
	cin >> str2;

	for(int i = 1; i < str.size()+1; i++)
		for(int j = 1; j < str2.size()+1; j++)
		{
			if(str[i-1] == str2[j-1]) DP[i][j] = DP[i-1][j-1]+1;
			else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}

	cout << DP[str.size()][str2.size()]<<endl;
	return 0;
}