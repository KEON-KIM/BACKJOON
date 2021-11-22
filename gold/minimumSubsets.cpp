// O(n^2) <- Can't use this Algorithms.
#include<iostream>

using namespace std;

int arr[1000], n;

int findMin(int index, int SUM, int sumTotal)
{
	if(!index)
		return abs((sumTotal - SUM) - SUM); // Calculation difference between two subsets
	
	return min(findMin(index - 1, SUM + arr[index - 1], sumTotal), 
		findMin(index - 1, SUM, sumTotal));	
}

int findMinGroup()
{
	int sumTotal = 0;
	for(int i = 0; i < n; i++)
		sumTotal += arr[i];

	return findMin(n, 0, sumTotal);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "minimum difference between two sets is : " << findMinGroup() << endl; 
	return 0;
}