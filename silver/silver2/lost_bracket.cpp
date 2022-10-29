//#1541
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

#define MAX 1000002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int solution(string str)
{
	int result = 0;

	string buff;
	istringstream iss(str);
	while(getline(iss, buff, '+'))
		result += stoi(buff);
	return result;
}
int main()
{
	string input;
	cin >> input;

	int cnt = 0;
	int result = 0;

	string buff;
	istringstream iss(input);
	while(getline(iss, buff, '-'))
	{
		if(!cnt)
			result += solution(buff);
		else 
			result -= solution(buff);
		cnt++;
	}
	cout << result;

	return 0;
}