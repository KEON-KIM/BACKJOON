// #1339
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

#define MAX 26+1
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RFOR(i, n) for(int i = n; i >= 0; i--)
using namespace std;

typedef long long ll;
int N;
int scores[MAX][9];
int visited[MAX];

ll result = 0;
int main()
{
	cin >> N;
	string input;
	FOR(i, N)
	{
		cin >> input;
		reverse(input.begin(), input.end());
		FOR(k , input.size())
			scores[input[k]-'A' + 1][k+1]++;
	}

	RFOR(t, 9) // 9 ~ 0 
	{
		int maxi = -1, maxIdx = 0;
		for(int i = 1; i < MAX; i++) // 1 ~ 10 / start to A.
		{
			int cmp = 0;
			if(visited[i]) continue;
			for(int j = 1; j < 9; j++) // 1 ~ 8
				cmp += scores[i][j] * pow(10, j-1) * t;
			if(cmp > maxi)
			{
				maxi = cmp;
				maxIdx = i;
			}
		}
		visited[maxIdx] = t;
		result += maxi;
	}

	cout << result  << endl;


	return 0;
}