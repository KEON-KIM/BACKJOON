#include<iostream>


using namespace std;
int arr[1001];
int N;

void swap(int index1, int index2)
{
	int tmp;
	tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

int main()
{
	//input
	int key;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	//solution
	for(int i = 0; i < N-1; i++)
	{
		key = i;
		for(int j = i; j < N; j++)
			if(arr[j] < arr[key]) key = j;

		if(i != key) swap(i, key);
		
	}

	//print
	for(int i = 0; i< N; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}