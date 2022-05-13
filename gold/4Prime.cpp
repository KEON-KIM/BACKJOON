// #1153
// @Reference <https://sgc109.tistory.com/206>
#include <iostream>
#define pb push_back
#define MAX 1000003
using namespace std;

int N;
int isPrime[MAX];
int main() {
    cin >> N;
    for(int i = 2; i * i <= N; i++){
        if(isPrime[i]) continue;
        for(int j = i * i ; j <= N; j += i){
            isPrime[j] = 1;
        }
    }
    if(N & 1){
        if(N < 9)
        {
            cout << -1;
            return 0;
        }
        cout << "2 3 ";
        N -= 5;
    }
    else {
        if(N < 8)
        {
            cout << -1;
            return 0;
        }
        cout << "2 2 ";
        N -= 4;
    }
    for(int i = 2; i < N; i++)
    {
        if(!isPrime[i] && !isPrime[N - i])
        {
            cout << i << " " << N - i;
            return 0;
        }
    }
    return 0;
}


/*#include <iostream>
#include <vector>

#define MAX 1000002
#define FOR(i, n) for(int i = 2; i <= n; i++)
using namespace std;

int N;
bool flag = false;
bool prime[MAX];
bool is4Prime[MAX][4];
vector<int> primes;
vector<int> answer;

bool dfs(int value, int depth)
{
	if(depth < 1) return false;
	if(depth == 1 && is4Prime[value][depth]) 
	{
		if(flag) answer.push_back(value);
		return true;
	}
	
	for(int i = primes.size()-1; i >= 0; i--)
	{
		if(!prime[i])
		{
			if(dfs(value - primes[i], depth - 1)){
				if(flag)
					answer.push_back(primes[i]);
				return true;
			}
		}
	}

	return false;
}
int main()
{
	cin >> N;
	FOR(i, N)
		if(!prime[i])
		{
			primes.push_back(i);
			FOR(j, N/i)
				prime[i*j] = true;
		}
			
	prime[1] = true;
	FOR(i, N)
	{

		for(int j = 1; j <= 4; j++)
		{
			if(i == N && j == 4) flag = true;
			if(j == 1){
				if(!prime[i]){
					 is4Prime[i][j] = true;
				}
			}
			
			else
			{
				if(dfs(i, j)) 
					is4Prime[i][j] = true;	
			}
		}
	}

	for(int i = 0; i < 4; i++)
		cout << answer[i] << " ";
	cout << endl;

	return 0;
}*/