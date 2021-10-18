#include<iostream>
#include<cstring>

#define MAX 1000001

using namespace std;

int N, M;
int Eratosthenes[1000001];

int main()
{
	memset(Eratosthenes, 1, sizeof(int) * MAX);
	cin >> N >> M;
	Eratosthenes[1] = 0;

	for(int i = 2; i <= M; i++)
	{
		for(int j = 2; j <= M; j++)
		{
			if(i * j > MAX - 1) break;
			if(!Eratosthenes[i]) continue;
			else Eratosthenes[i*j] = 0;
		}
	}
	for(int i = N; i <= M; i++) if(Eratosthenes[i]) cout << i << '\n';

	return 0;
}