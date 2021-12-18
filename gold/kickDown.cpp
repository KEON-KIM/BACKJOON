// #1195
// @Reference pjh612 <https://velog.io/@pjh612/%EB%B0%B1%EC%A4%80-1195%EB%B2%88-%ED%82%A5%EB%8B%A4%EC%9A%B4>
#include<iostream>
#include<cstring>

using namespace std;
int result;
void solution(string str1, string str2)
{
	int str1_size = str1.length();
	int str2_size = str2.length();
	result = str1_size + str2_size;

	for(int i = 0; i < str1_size; i++)
	{
		bool flag = false;
		for(int j = 0; j <= i; j++)
		{
			if(str2[j] == '2' && str1[str1_size - i + j] == '2')
			{
				flag = true;
				break;
			}
		}
		if(!flag) result = min(result, str1_size + str2_size - i);
	}

	for(int i = 0; i < str1_size; i++)
	{
		bool flag = false;
		for(int j = 0; j <= i; j++)
		{
			if(str2[str2_size-1 - i + j] == '2' && str1[j] == '2')
			{
				flag = true;
				break;
			}
		}
		if(!flag) result = min(result, str1_size + str2_size-1 - i);
	}

	for(int i = 0; i < str2_size - str1_size; i++)
	{
		bool flag = false;
		for(int j = 0; j < str1_size; j++)
		{
			if(str2[i + j] == '2' && str1[j] == '2')
			{
				flag = true;
				break;
			}
		}
		if(!flag) result = min(result, str2_size);
	}

	cout << result << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s1, s2;
	cin >> s1 >> s2;

	if(s1.size() > s2.size())
		solution(s2, s1);
	
	else
		solution(s1, s2);

	return 0;
}


// int main()
// {
// 	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// 	string s1, s2;
// 	cin >> s1 >> s2;

// 	if (s1.length() > s2.length())
// 	{
// 		swap(s1, s2);
// 	}
// 	int ans = s1.length()+s2.length();
// 	for (int i = 0; i < s1.length(); i++)
// 	{
// 		int s1_len = s1.length();
// 		bool flag = false;
// 		for (int j = 0; j <= i; j++)
// 		{
// 			if (s2[j] =='2' && s1[s1_len - 1 - i+ j] == '2')
// 			{
// 				flag = true;
// 				break;
// 			}
// 		}
// 		if (!flag)
// 			ans = min(ans, (int)s1.length() + (int)s2.length() - 1 - i);
// 	}
// 	for (int i = 0; i < s1.length(); i++)
// 	{

// 		int s2_len = s2.length();
// 		bool flag = false;
// 		for (int j = 0;j<=i;j++)
// 		{
// 			if (s2[s2_len -1 -i+j] == '2' &&  s1[j]=='2')
// 			{
// 				flag = true;
// 				break;
// 			}
// 		}
// 		if (!flag)
// 			ans = min(ans, (int)s1.length() + (int)s2.length() - 1 - i);
// 	}

// 	for (int i = 0; i<s2.length()- s1.length(); i++)
// 	{
// 		bool flag = false;
// 		for (int j = 0; j < s1.length(); j++)
// 		{
// 			if (s1[j]=='2' && s2[i+j] == '2')
// 			{
// 				flag = true;
// 				break;
// 			}
// 		}
// 		if (!flag)
// 			ans = min(ans,(int)s2.length());
// 	}
// 	cout << ans;
// }