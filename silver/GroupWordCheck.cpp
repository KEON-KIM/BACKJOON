// #1316
#include<iostream>
#include<cstring>
#include<algorithm>
#define ALPHA 26


using namespace std;

int N, alpha[ALPHA];


bool word_check()
{
	for(int i : alpha)
		if(i > 1) return false;
	
	return true;
}
// bool zero_check()
// {
// 	for(int i : alpha)
// 		if(i != 0) return false;
// 	return true;
// }
void erasor(string str)
{
	memset(alpha, 0, ALPHA * sizeof(int));
	for(int i : str)
		alpha[i - 97]++;
}

int main()
{
	string str;
	int result = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> str;
		str.erase(unique(str.begin(), str.end()), str.end());
		erasor(str);
		if(word_check()) result++;
	}

	cout << result << endl;

	return 0;
}
