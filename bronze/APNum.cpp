#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


bool solution(int N)
{
	string str = to_string(N);
	// sort(str.begin(), str.end());

	int cmp = 0;
	for(int i = 0; i< str.size()-1; i++)
	{
		if(cmp != str[i+1] - str[i] && i != 0) return false;
		cmp = str[i+1] - str[i];
	}

	return true;
	
}
int main()
{
	int N,count = 0 ;
	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		if(solution(i)) count++;
	}

	cout << count << endl;
	return 0;
}