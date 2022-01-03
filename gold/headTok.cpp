// #1241
#include<iostream>
#define MAX 1000001
#define endl '\n'

using namespace std;
int N, board[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int arr[N];

	for(int i = 0; i < N; i++){
		cin >> arr[i];
		board[arr[i]]++;
	}

	for(int i = 0; i < N; i++)
	{
		int result = 0;
		for(int j = 1; j*j <= arr[i]; j++)
		{
			if(arr[i]%j == 0)
			{
				result += board[j];
				cout << "i index : " << i <<"/" << arr[i] << " j Index : "<< j  <<endl;
				if(j!=arr[i]/j) result += board[arr[i]/j];
			}
		}
		cout << result-1 << endl;
	}

	return 0;
}



