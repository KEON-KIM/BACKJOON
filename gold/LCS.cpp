#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string str1, str2, answer = "";
int result = 0;

void LCS(string :: iterator iter1, string :: iterator iter2)
{
	while(iter1 != str1.end())
	{
		string :: iterator tmp = iter2;
		while(iter2 != str2.end())
		{
			if(*iter1 == *iter2){
				answer += *iter1;
				result = (result < answer.size())? answer.size(): result;
				LCS(iter1 + 1, iter2 + 1);
			} 
			iter2++;
		}
		iter2 = tmp;
		iter1++;
	}
	if(answer.size() > 0) answer.erase(answer.end() - 1);
}
int main()
{
	cin >> str1;
	cin >> str2;

	string :: iterator iter;
	string :: iterator iter2;
	iter = str1.begin();
	iter2 = str2.begin();

	while(iter != str1.end())
	{
		LCS(iter, iter2);
		iter++;	
	}

	cout << result << endl;

	return 0;
}