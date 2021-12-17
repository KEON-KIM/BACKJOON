// #1747
#include<iostream>
#include<cstring>

#define MAX 1000001
#define PALIN 1003001
using namespace std;

int N;
int DP[MAX];
bool palinedrome(int n)
{
	string str = to_string(n);
	int i = 0, j = str.size()-1;
	while(i < j)
	{
		if(str[i] != str[j])
			return false;
		i++; j--;
	}
	return true;
}

int main()
{
	cin >> N;
	memset(DP, 1, sizeof(DP));


	for(int i = 2; i < MAX; i++)
	{
		if(i == MAX -1) cout << PALIN << endl;
		if(DP[i])
		{
			int j = 2;
			while(j * i < MAX)
			{
				DP[j*i] = 0;
				j++;
			}
		}
		if(DP[i] && i >= N && palinedrome(i))
		{
			cout << i << endl;
			break;
		} 
	}

	return 0;
}