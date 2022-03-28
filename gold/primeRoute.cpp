#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

#define MAX 10000
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T, N, M;
int result;
bool board[MAX];
bool visited[MAX];
vector<int> prime;
bool Compare(int a, int b)
{
	int cmp = 0;
	for(int i = 3; i >= 0; i--)
	{
		if((int)(a/ pow(10, i)) ==(int)(b/ pow(10, i))) cmp++;
		a-= ((int)(a/ pow(10, i)) * pow(10, i));
		b-= ((int)(b/ pow(10, i)) * pow(10, i));
	}

	if(cmp == 3) return true;
	return false;
}

void Init()
{
	board[0] = true;
	board[1] = true;
	for(int i = 2; i < sqrt(MAX); i++)
		for(int j = 2; i * j < MAX; j++)
			if(!board[i*j])
				board[i*j] = true;
	
}

int main()
{
	Init(); // check prime number
	FOR(i, MAX)
		if(!board[i] && i >= 1000) 
			prime.push_back(i);

	cin >> T;	
	FOR(i, T)
	{
		cin >> N >> M;
		result = -1;
		memset(visited, false, sizeof(visited));
		queue<pair<int, int>> Que; // num, cnt
		Que.push({N, 0});
		// cout << "==============" << endl;
		while(!Que.empty())
		{
			int num = Que.front().first;
			int cnt = Que.front().second;
			Que.pop();

			// cout << num <<"/"<<cnt << endl;
			if(num == M) {
				result = cnt;
				break;
			}

			for(int i = 0; i < prime.size(); i++)
			{
				if(visited[prime[i]]) continue;
				if(Compare(num, prime[i]))
				{
					Que.push({prime[i], cnt+1});
					visited[prime[i]] = true;
				}
			}
		}

		if(result == -1)
			cout << "Impossible" << endl;
		else cout << result << endl;
	}	
	return 0;
}