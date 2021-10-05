#include<vector>
#include<iostream>
#include<numeric>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	float max = 0.0;
	cin >> N;
	vector<float> data(N);
	for(int i =0 ; i< N; i++)
		cin >> data[i];
	sort(data.begin(), data.end(), greater<int>());
	max = data[0];
	for(int i = 0; i < N ; i++)
		data[i] = (data[i] / max)* 100; 
	// cout <<"MAX" << max<< endl;
	// for(int i : data) cout << i << endl;
	cout <<  accumulate( data.begin(), data.end(), 0.0)/ data.size()   << endl;

	return 0;
}

