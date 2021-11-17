#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string result;
string start;
int N, M;

string make_str(string str, int n, int reverse)
{
	string tmp = "";
	if(reverse)
		for(int i = n; i >= 0; i--)
			tmp += str[i];
	else
		for(int i = 0; i <= n; i++)
			tmp += str[i];

	return tmp;
}

int res(string str, int n)
{
	// str = make_str(str, n);
	cout << "TEST : " << str << "|" << n << endl; 
	if( n == N ){
		// cout << "FUCK : " << str << " | " << n <<" | " << N << endl;
		if(str == result) return 1;
		else return 0;
	}
	else if(str[str.size()-1] == 'B'){
		str.erase(str.end()-1);
		reverse(str.begin(), str.end());
		return res(str, n-1);
	}
	else{
		str.erase(str.end()-1);
		return res(str, n-1);
	}
}

int main()
{
	cin >> result;
	cin >> start;
	N = result.size()-1;
	M = start.size()-1;

	cout << res(start, M) << endl;

	return 0;
}