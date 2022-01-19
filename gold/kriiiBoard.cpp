//#11058
#include<iostream>
#define MAX 101
using namespace std;

typedef long long ll;
int N;
ll DP[MAX];

int main()
{
	cin >> N;
	for(int i = 0; i < MAX; i++)
		DP[i] = i;

	for(int i = 1; i < MAX; i++)
		for(int j = i+3, cnt = 2; j < MAX; j++, cnt++)
			DP[j] = max(DP[j], DP[i] * cnt);
	

	cout << DP[N] << endl;
	return 0;
}