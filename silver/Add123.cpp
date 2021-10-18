// #9095
#include<iostream>
#include<vector>
using namespace std;

int T;
vector<int> answer;
int fac(int n)
{
	int result = n;
	while(n-->1)
		result *= n;
	if (!result) return 1;
	else return result;
}
int main()
{
	cin >> T;

	int n;
	for(int i = 0, count = 0; i < T; i++, count=0)
	{
		cin >> n;
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= n; k++)
				for(int l = 0; l <= n; l++)
					if(j * 3 + k * 2 + l == n)count+= (fac(j+k+l)) / (fac(j) * fac(k) * fac(l));
			
		answer.push_back(count);
	}
	for(int i : answer) cout << i << endl;


	return 0;
}