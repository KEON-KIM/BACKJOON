//#14226
#include<iostream>
#include<algorithm>
#define MAX 1001

using namespace std;

int N, DP[MAX];

int main()
{
	cin >> N;
	for(int i = 1 ; i < MAX; i++)
		DP[i] = i;

	for(int i = 2; i < MAX; i++)
	{
		for(int j = i*2; j < MAX; j*=2) // 자기 자신 반복 복제
		{
			DP[j] = min(DP[j], DP[j/2]+2);
			DP[j-1] = min(DP[j-1], DP[j]+1); // 소수 (PRIME) 값 찾기
		}
		for(int j = 2; i*j < MAX; j++) // 최조 자신 반복 복제
		{
			DP[i*j] = min(DP[i*j], DP[i]+j);
			DP[i*j-1] = min(DP[i*j-1], DP[i*j]+1); // 소수(PRIME) 값 찾기 
		}
	}
	cout << DP[N] << endl;
	return 0;
}