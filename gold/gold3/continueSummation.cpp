#include <iostream>
#include <vector>
#include <cstring>

#define MAX 4000002

using namespace std;

int N;
vector<int> primes;
bool isPrime[MAX];
int main()
{
    cin >> N;
    //에라토스테네스의 체
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i*i <= N; i++)
    {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= N; j += i)
            isPrime[j] = false;
    }

    for (int i = 2; i <= N; i++)
    
        if (isPrime[i]) primes.push_back(i);
    
    int result = 0, sum = 0;
    int l = 0, r = 0;
    while (1) {
        if (sum >= N) 
            sum -= primes[l++];

        else if (r == primes.size()) 
            break;

        else 
            sum += primes[r++];
        
        if (sum == N) result++;
    }

    cout << result;
    return 0;
}