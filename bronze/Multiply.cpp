#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
#define PADDING 8;

string sumFunc(string a, string b)
{
	int carry = 0;
	string answer = "";
	if(a.size() > b.size())
		b.insert(b.begin(), a.size() - b.length(), '0');
	
	else if (a.size() < b.size())
		a.insert(a.begin(), b.size() - a.length(), '0');


	for(int i = b.size()-1, j = a.size()-1; i >= 0 && j >= 0; i--, j--)
	{
		int temp = (a[i] - '0') + (b[j] - '0') + carry;
		carry = temp/10;
		answer.push_back((char)(temp%10 + 48));
	}
	if(carry > 0) answer.push_back((char)(carry+48));

	reverse(answer.begin(), answer.end());

	return answer;
}

string multiply(vector<string> a, vector<string> b)
{
	vector<string> temp;
	int padding = PADDING;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b.size(); j++)
		{
			string str = to_string(stoll(a[i]) * stoll(b[j]));
			str.insert(str.end(), (padding * i) + (padding * j) , '0');
			cout << "a[i] : "<< a[i] << " * "<< " b[i] : " << b[j] << " = " << str << endl;
			temp.push_back(str);
		}
	}
	// SUM
	for(int i = 1; i < temp.size(); i++){
		temp[0] = sumFunc(temp[0],temp[i]);
	}

	return temp[0];
}

pair<vector<string>, vector<string>> init(string a, string b)
{	
	int Amok, Bmok;
	int count = PADDING;
	
	if( a.size()%count !=0) Amok =  a.size()/count+1;
	else Amok = a.size()/count;

	if( b.size()%count !=0) Bmok =  b.size()/count+1;
	else Bmok = a.size()/count;

	vector<string>  A_stirng(Amok), B_string(Bmok);

	for(int i = Amok-1, start = a.size(); i >= 0; i--, start-=count){
		// cout << start << endl;
		if(start-count < 0){
			// cout <<0 <<"," << start <<endl;
			cout << "A string : " << a.substr(0, count) << endl;
			A_stirng[i] = a.substr(0, count);
		}
		else{
			// cout <<start-count <<"," << start <<endl;
			cout << "A_string[i] : " << a.substr(start-count, count) << endl;
			A_stirng[i] = a.substr(start-count, count);
		}
	}
	
	for(int i = Bmok-1, start = b.size(); i >= 0; i--, start-=count){
		if(start-count < 0)
			B_string[i] =(b.substr(0, count));
		else
			B_string[i] = (b.substr(start-count, count));
	}
	

	return make_pair(A_stirng, B_string);
}
string solutionBig(int N, int M)
{
	string a, b;
	string answer ="0";
	cin >> a >> b;
	if (a.size() != N || b.size() != M || N == 0 || M ==0 ) return answer;
	else
	{
		pair<vector<string>, vector<string>> strSet = init(a, b);
		answer = multiply(strSet.first, strSet.second);

		return answer;
	}
	
	
}
long long solution(int N, int M)
{
	string a, b;
	cin >> a >> b;
	if (a.size() != N || b.size() != M || N == 0 || M ==0 ) return 0;

	else	
		return stoll(a) * stoll(b) ;
}

int main()
{
	int N, M;

	cin >> N >> M;
	if(N > 8 || M > 8)
		cout << solutionBig(N,M) << endl;
	
	else
		cout << solution(N,M) << endl;

	return 0;
}