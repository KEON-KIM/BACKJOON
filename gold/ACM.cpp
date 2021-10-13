#include<iostream>
#define MAX 100000;

using namespace std;

int T, N, K, D, result = 0, S = 0;

int DP[1001][1001];
int TIME[1001];

void INIT()
{
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			DP[i][j] = 0;
}

void printM()
{
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++)
			cout << DP[i][j] << "|";
		cout << endl;
	}
}
void print()
{
	for(int i = 1; i <= N ; i++)
		cout << TIME[i] << "|";
	cout << endl;
}

void Input()
{
	result = 0;
	int X, Y, W;

	cin >> N >> K;
	INIT();
	//INIT

	for(int i = 1; i <= N; i++)
		cin >> TIME[i];
	
	//Print
	// print();

	for(int i = 0; i < K; i++)
	{
		cin >> X >> Y;
		if(X < Y){
			if(S > X||!S) S = X;
			DP[X][Y] = TIME[Y];
		}
		else
		{
			if(S < X||!S) S = X;
			DP[Y][X] = TIME[Y];
		}
	}
	//print DP Matrix;
	cin >> D;
}

void solution() // Floyd Warshall
{
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			for(int via = 1; via <= N; via++)if(i!=j && DP[via][j] > 0)
				DP[i][j] = DP[i][via] + DP[via][j] > DP[i][j] ? DP[i][via] + DP[via][j] : DP[i][j];
	if(S > D)
		result = DP[D][S] + TIME[S];
	else
		result = DP[S][D] + TIME[S];
	cout << result <<endl;
}

int main()
{
	cin >> T;

	for(int i = 0 ; i < T; i++)
	{
		Input();
		solution();
	}

	return 0;
}