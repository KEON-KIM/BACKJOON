//#11053
#include <iostream>
#include <vector>

using namespace std;
int N, dp[1001];
vector<int> vec;

int main()
{
	cin >> N;
	int input, dp_max, answer = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> input;
		vec.push_back(input);
		dp_max = 0;
		// print();

		for(int j = 0; j < vec.size(); j++)
			if(vec[i] > vec[j])
				if(dp_max < dp[j]) dp_max = dp[j];
		dp[i] = dp_max + 1;
		answer = max(answer, dp[i]);
	}

	cout << answer << endl;

	return 0;
}