// #2023 
// @Reference jaimemin <https://jaimemin.tistory.com/879>
#include<iostream>

#define endl '\n'
using namespace std;

int N;

bool isPrime(int n)
{
	int i = 2;
	if(n == 1 || n == 0) return false;
	for(int i = 2; i * i <= n; i++)
		if(n%i == 0) return false;
	
	return true;
}

void cal(int num, int len)
{
    if (len == N)
    {
         cout << num << "\n";
         return;
	}

    for (int i = 1; i <= 9; i += 2) // 짝수는 Prime이 될 수 없다. 홀 수만 체크.
    {
         if (isPrime(num * 10 + i))
             cal(num * 10 + i, len + 1);
    }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	// memset(DP, 1, sizeof(DP));
	cal(2,1); // 2로 시작하는 소수
	cal(3,1); // ''
	cal(5,1);
	cal(7,1);

	// for(int i = minimum; i < maximum; i++)
	// 	if(DP[i] && Special(i)) cout << i << endl;

	return 0;
}