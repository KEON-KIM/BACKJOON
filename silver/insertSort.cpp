#include<iostream>

using namespace std;

int N;
int arr[1001];

int main()
{
	int k, i, j;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 1; i < N; i++)
	{
		k = arr[i];
		for(j = i-1; j >= 0 && arr[j] > k; j--)
			arr[j+1] = arr[j];
		

		arr[j+1] = k;
	}

	for(int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}