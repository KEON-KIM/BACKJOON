// #5582
#include<string>
#include<iostream>
#include<cmath>

#define MAX 4001

using namespace std;

string str1, str2;
int board[MAX][MAX], result = 0;
// 완전탐색
// void solution()
// {
// 	for(int i = 0; i < str1.size(); i++)
// 	{
// 		for(int j = 0; j < str2.size(); j++)
// 		{
// 			if(str1[i] == str2[j])
// 			{
// 				int k = 0, count = 0;
// 				while(str1[i+k] == str2[j+k]){
// 					if(str1[i+k] == '\0') break;
// 					k++; 
// 					count++;
// 				}
// 				result = max(count, result);
// 			}
// 		}
// 	}
// }
void print()
{
	for(int i = 0; i < str2.size(); i++)
	{
		for(int j = 0; j < str1.size(); j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void solution()
{
	int size_1 = str1.size(), size_2 = str2.size();

	for(int i = 1; i <= size_1; i++)
	{
		for(int j = 1; j <= size_2; j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				board[i][j] = board[i-1][j-1] + 1;
				result = max(board[i][j], result);
			}
		}
	}
}

int main()
{
	cin >> str1 >> str2;

	solution();

	cout << result << endl;
	return 0;
}