// #1915
#include <iostream>
#include <string>
#include <cmath>

#define MAX 1001
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, M, result = 0;
int board[MAX][MAX];

void print()
{
	FOR(i, N)
	{
		FOR(j, M)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	cin >> N >> M;
	FOR(i, N)
	{
		string input;
		cin >> input;
		FOR(j, M)
			board[i][j] = input[j] - '0';
	}
	FOR(i, N)
	{
		FOR(j, M)
		{
			if(board[i][j])
			{
				bool flag = true;
				int t = board[i][j];
				while(flag)
				{
					if(i+t > N || j + t > M ) break;
					for(int m = i; m < i + t; m++)
					{
						for(int n = j; n < j + t; n++)
						{
							if(!board[m][n])
							{
								flag = false;
								break;
							}
							board[m][n] = t;
						}
						if(!flag) break;
					}
					if(!flag) break;
					result = max(result, t);
					t++;
				}
			}
		}
	}

	// print();
	cout << pow(result, 2);
	return 0;
}