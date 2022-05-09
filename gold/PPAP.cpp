#include <iostream>
#include <string>
#include <stack>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

stack<int> P;
int main(void)
{
	string str;
	cin >> str;

	FOR(i, str.length())
	{
		if (str[i] == 'P')
		{
			P.push(1);
		}
		else
		{
			if (P.size() >= 2 && str[i + 1] == 'P')
			{
				P.pop();
				i++;	
			}
			else
			{
				cout << "NP" << endl;
				return 0;
			}
		}
		
	}

	if (P.size() == 1)
		cout << "PPAP" << endl;
	
	else
		cout << "NP" << endl;
	

	return 0;
}