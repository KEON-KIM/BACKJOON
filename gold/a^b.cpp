//#10827
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

string a;
int b;

string bigSum(string a, string b)
{
	int size = max(a.length(), b.length());
	int round = 0;
	string result = "";
	for(int i = 0; i < size; i++)
	{
		int tmp;
		if(i > b.length()-1) 
			tmp = (a[i] - '0');
		else
			tmp = (a[i] - '0') + (b[i] - '0');

		result.push_back((tmp + round)%10 + '0');
		round = tmp/10;
	}
	if(round > 0)
		result.push_back(round + '0');

	return result;
}

string bigMulti(string a, string b)
{
	vector<string> hap;
	for(int i = a.length()-1; i >= 0; i--)
	{
		int round = 0;
		string str = "";
		for(int k = 0; k < (a.length()-1) - i; k++)
			str.push_back('0');
		
		for(int j = b.length()-1; j >= 0; j--)
		{
			int tmp = (a[i] - '0') * (b[j] - '0');
			str.push_back((tmp + round)%10 + '0');
			round = tmp/10;
		}
		if(round > 0)
			str.push_back(round + '0');

		hap.push_back(str);
	}

	string result = hap[0];
	for(int i = 1; i < hap.size(); i++){
		cout << "RESULT :" << result << endl;
		cout << "HAP : " << hap[i] << endl;
		result = bigSum(result, hap[i]);
	}

	reverse(result.begin(), result.end());
	return result;
}
int findPoint(string a)
{
	int point;
	int size = a.length();

	for(int i = 0; i < size; i++)
		if(a[i] == '.')
			point = size - i - 1;
		
	

	return point;
}

string bigPow(string a, int b)
{
	int point = -1;
	point = findPoint(a);
	cout << "POINT : " << point << endl;
	string result = "";
	string res = "";
	for(int i = 0; i < a.length(); i++){
		if(a[i] != '.') {
			result.push_back(a[i]);
			res.push_back(a[i]);
		}
	}
	
	for(int i = 1; i < b; i++){
		cout << "INDEX : "<< i << endl;
		result = bigMulti(result, res);
		point *= point;
	}
	string str = "";
	for(int i = 0; i < a.length(); i++)
	{
		if(i == point)
			str.push_back('.');
		str.push_back(a[i]);
	}
	return str;
}

int main()
{
	// cin >> a >> b;
	string answer;
	answer = bigSum("000", "0000");

	cout << answer << endl;
	return 0;
}