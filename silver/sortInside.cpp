#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int a; cin >> a;
	string str = to_string(a);
	sort(str.begin(), str.end(), greater<char>());

	cout << str << endl;
	return 0;
}