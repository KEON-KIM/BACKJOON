//#2262
//@Reference jaimemin <https://jaimemin.tistory.com/1325>
#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(void)
{
	fastio;

	int N, result = 0;
	cin >> N;

	vector<int> v(N + 2, 0); 
	// Example
	// {0 | 1, 6, 2, 5, 3, 4 | 0 }
	for (int i = 1; i <= N; i++)
		cin >> v[i];


	for (int i = N; i > 1; i--)
	{
		int j = 1;
		while(j <= N){ // Find the bottom
			if (v[j] == i)
				break;
			j++;
		}
		
		result += v[j] - max(v[j - 1], v[j + 1]);//summation least value
		while(j <= N){
			v[j] = v[j + 1];
			j++;
		}
	}

	cout << result << endl;

	return 0;
}
