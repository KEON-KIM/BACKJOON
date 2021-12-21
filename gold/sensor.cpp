// # 2212
#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 10005
using namespace std;

int N, K, result = 0;
vector<int> nboard(MAX), kboard(MAX);

int main()
{
	cin >> N >> K;
	for(int i = 0; i < N; i++)
		cin >> nboard[i];
	sort(nboard.begin(), nboard.begin()+N);
	for(int i = 0; i < N-1; i++){
		result += abs(nboard[i] - nboard[i+1]);
		kboard[i] = abs(nboard[i] - nboard[i+1]);
	}

	sort(kboard.begin(), kboard.begin()+N, greater<int>());

	for(int i = 0; i < K-1; i++)
		result -= kboard[i];

	cout << result << endl;
	return 0;
}