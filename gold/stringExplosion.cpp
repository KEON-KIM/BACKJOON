// #15684
// @Reference jaimemin <https://jaimemin.tistory.com/823>
#include <iostream>
#include <string>

#define MAX 1000001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

char result[MAX];
string input, boom;
int main()
{
	cin >> input >> boom;

	int idx = 0;
	FOR(i, input.length())
	{
		result[idx++] = input[i];

		if(result[idx-1] == boom[boom.length()-1])
		{
			if(idx - boom.length() < 0)
				continue;

			bool isDetect = true;
			FOR(j, boom.length())
			{
				if(result[idx - j - 1] != boom[boom.length() - j - 1])
				{
					isDetect = false;
					break;
				}
			}

			if(isDetect)
				idx -= boom.length();
		}
	}

	if(!idx)
		cout << "FRULA" << endl;

	else
		FOR(i, idx)
			cout << result[i];

	return 0;
}
/*#include <iostream>
#include <string>

using namespace std;

string str;
int main()
{
	string boom;
	cin >> str >> boom;
	string :: iterator it;

	int idx = str.find(boom);
	while(idx != string::npos)
	{
		int size = str.size();
		string tmp = "";
		for(int i = 0; i < idx; i++)
			tmp += str[i];
		
		for(int i = idx+boom.size(); i < size; i++)
			tmp += str[i];

		str = tmp;
		idx = str.find(boom);
	}

	if(!str.size()) str = "FRULA";
	cout << str << endl;

	return 0;
}*/