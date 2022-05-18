// #16472 
#include <iostream>
#include <cstring>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N;
bool alpha[26];
string input;
int main()
{
	int maxi = 1;
	cin >> N;
	cin >> input;
	FOR(i, input.size() - maxi)
	{
		int ptr = i + 1;
		int val = 1, len = 1;
		alpha[input[i] - 'a'] = true;
		while(val <= N && ptr < input.size())
		{
			if(!alpha[input[ptr] - 'a'])
			{	
				alpha[input[ptr] - 'a'] = true;
				val++;
			}
			else
			{
				len++;
				ptr++;
			}
		}
		if(maxi < len){maxi = len;}
		memset(alpha, false, sizeof(alpha));
	}

	cout << maxi << endl;
	return 0;
}