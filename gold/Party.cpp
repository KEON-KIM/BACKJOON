#include <vector>
#include <iostream>
#define MAX 99999999

using namespace std;

int N,M,X, answer = -1;
// int answer = MAX;
// Floyd Warshall
int main()
{
	cin >> N >> M >> X;
	int DP[1001][1001];
	int a,b,c;
	// INIT, Reset to matrix for Dynamic Programming
	for(int i = 1; i < N+1; i++)
		for(int j = 1; j< N+1; j++)
			DP[i][j] = MAX;
		
	//Input node data(start, end, cost);
	for(int i = 1; i < M+1; i++)
	{
		cin >> a >> b >> c;
		DP[a][b] = c;
	}

	// Floyd Warshall Algorithm
	for(int via = 1; via <= N; via++) 
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				DP[i][j] = DP[i][via] + DP[via][j] < DP[i][j] ? DP[i][via] + DP[via][j]:DP[i][j]; // Update to cost


	for(int i = 1; i <= N; i++)
		if(i != X)answer = answer < DP[i][X] + DP[X][i] ? DP[i][X] + DP[X][i]: answer; // Find a Max answer;
// ======== Print ======
	// for(int i = 1; i <= N; i++)
	// {
	// 	for(int j = 1; j <= N; j++)
	// 		cout << DP[i][j] << "|";
	// 	cout << endl;
	// }
	cout << answer << endl;

	return 0;

//======== Example ======
// 5 10 1
// 1 2 2
// 1 3 8
// 1 4 3
// 2 4 7
// 2 5 3
// 3 1 1
// 4 1 1
// 4 3 2
// 4 5 1
// 5 4 4

}