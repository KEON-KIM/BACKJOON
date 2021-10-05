#include<vector>
#include<string>
#include<iostream>

using namespace std;

int dp[123] = {0,};

int main()
{
	int max = 0;
	int maxIndex = 0;
	string str;
	getline(cin, str);

	for(char c : str)
	{
		if((int)c >= 97 && (int)c <= 122)
			dp[(int)c - 32] += 1;
		else if ((int)c >= 65 &&(int)c <= 90)
			dp[(int)c] += 1;
	}

	for(int i = 65; i < 91; i++)
	{
		if(max < dp[i]) 
		{
			maxIndex = i;
			max = dp[i];
		}
	}

	for(int i = 65; i < 91; i++)if(max == dp[i] && i != maxIndex)maxIndex = 63;
	
	cout << (char)maxIndex << endl;

	return 0;
}