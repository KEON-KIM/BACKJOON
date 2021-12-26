#include <iostream>
#include <string>

#define FAIL 9
using namespace std;

// 100+1+
int N;
const int road[10][2] = {
	{5, 1}, // 0
	{2, FAIL}, //1
	{3, FAIL}, // 2
	{3, 4}, // 3
	{5, 7}, // 4
	{FAIL, 6}, // 5
	{5, 1}, // 6
	{8, 7}, // 7
	{3, 6}, // 8
	{FAIL, FAIL}
};



bool solution(string str)
{
	int state = 0;
	for(size_t i = 0; i < str.size(); i++)
	{
		char ch = str[i] - '0';
		state = road[state][ch];
	}

	return (state == 4 || state == 6 || state == 7);
}

int main()
{
	cin >> N;
	string input;
	for(int i = 0; i < N; i++){
		bool ans;
		cin >> input;
		cout << (solution(input)? "YES" : "NO") << endl;
	}
	return 0;
}