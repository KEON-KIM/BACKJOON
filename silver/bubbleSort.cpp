#include <iostream>

using namespace std;

int N;
int arr[1001];

void change(int index)
{
	int tmp;
	tmp = arr[index];
	arr[index] = arr[index+1];
	arr[index+1] = tmp;
}

int main()
{
	cin >> N;
	int tmp;
	//input
	for(int i = 0;  i < N; i++)
		cin >> arr[i];
	cout << "!" << endl;
	for(int i = N-1; i >= 0; i--)
		for(int j = 0; j < i; j++)	
			if(arr[j] > arr[j+1])change(j);
			
	//print
	for(int i = 0; i < N; i++)
		cout << arr[i] <<" ";
	cout << endl;

	return 0;
}