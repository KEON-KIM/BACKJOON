// #2421
// @Reference boomrabbit <https://boomrabbit.tistory.com/126>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#define MAX 1001
#define PMAX 1000001
#define FOR(i, n) for(int i = 1; i <= n; i++)

using namespace std;

int N, result = 0;
int board[MAX][MAX];
bool prime[PMAX];
vector<int> indexVector;

void Eratosthenes()
{
	prime[1] = 1;
	for(int i = 2; i <= sqrt(PMAX); i++)
	{
		for(int j = 2; j * i <= PMAX; j++)
		{
			if(!prime[j*i])
				prime[j*i] = true;
		}
	}
	prime[11] = 1;
}

int isPrime(int x, int y)
{
    return !prime[stoi(to_string(x)+to_string(y))];
}

int dfs(int x, int y)
{
    if( x < 1 || y < 1) return 0;
    int &ret = board[x][y];
    if(ret) return ret;

    ret = 0;
    ret = max(ret, max(dfs(x-1,y), dfs(x,y-1)));
    ret += isPrime(x,y);

    return ret;
}


int main()
{
	cin >> N;
	Eratosthenes();
	result = dfs(N, N);

	cout << result;
	

	return 0;
}


/*	FOR(i, N)
	{
		FOR(j, N)
		{
			if(!prime[stoi(to_string(i)+to_string(j))])
			{
				int maxCnt = 0;
				for(int h = i-1; h > 0; h --){
					if(board[h][j]){
						maxCnt = max(maxCnt, board[h][j]);
						break;
					}
				}
				for(int w = j-1; w > 0; w--){
					if(board[i][w]){
						maxCnt = max(maxCnt, board[i][w]);
						break;
					}
				}

				board[i][j] = maxCnt + 1;
				cout << i << "/" << j << endl;
				result = max(result, board[i][j]);
			}
		}
	}
*/