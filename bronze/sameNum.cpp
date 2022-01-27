#include<iostream>

using namespace std;
typedef long long ll;

int N;
void solution(int n)
{
	ll answer = 0;
	
	for(int i = 1; i < n; i++)
		answer += (n*i) + i;

	cout << answer << endl;
}

int main()
{
	cin >> N;

	solution(N);
	return 0;
}