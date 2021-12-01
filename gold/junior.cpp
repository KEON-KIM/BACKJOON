#include<iostream>
#include<cstring>

using namespace std;

int n;
long long arr[101], cache[20][101];

long long solution(int total, int index)
{
	if(index == n-2)
		return (total == arr[n-1]);
	
	if(total > 20 || total < 0) return 0;

	long long &result = cache[total][index];
	if(result != -1)
		return result;

	result = 0;
	return result += solution(total+arr[index], index +1) + solution(total-arr[index], index +1);

}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	memset(cache, -1, sizeof(cache));

	cout << solution(arr[0],0) << endl;

	return 0;
}