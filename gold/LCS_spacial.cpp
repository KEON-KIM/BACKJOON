#include<iostream>
#include<string>

#define MAX 1001

int DP[MAX][MAX];

using namespace std;

int main()
{
	string str1, str2, answer = "";
	cin >> str1;
	cin >> str2;

	int N = str1.size(), k =0;
	int M = str2.size();
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			if(str1[i-1] == str2[j-1])
				DP[i][j] = DP[i-1][j-1] + 1;
			else
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}
	}
	//print DP
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= N; j++)
		{
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
	int i = str1.size();
	int j = str2.size();
	while(i >= 1 && j >= 1)
	{
		if(DP[i][j] == DP[i][j-1])
			j--;
		else if (DP[i][j] == DP[i-1][j])
			i--;
		else
		{
			answer += (str1[i-1]);
			i--;j--;
		}
	}
	cout << answer.size() << endl;
	for(int i = answer.size()-1; i > -1; i--)
		cout << answer[i];
	cout << endl;
	// for(int i = 0; i < N; i++)
	// {
	// 	answer = "";
	// 	for(int j = 0; j < N; j++)
	// 	{
	// 		if(DP[i][j] != DP[i][j+1])
	// 			answer += str1[j+1];
	// 	}
	// 	if(answer.size() == DP[N][N]) break;
	// }

	// cout << DP[N][N] << endl;
	// cout << answer << endl;
	return 0;
}