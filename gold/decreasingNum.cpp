//# 1038
#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1023
using namespace std;

int n, cnt = 0;
vector<vector<int>> DP(11);
void solution()
{
	for(int i = 0; i < DP.size(); i++){
		for(int j = i; j <= 9; j++)
		{
			if(!i){
				DP[i].push_back(j);
				cnt ++;
				if(cnt > n) return;
			}
			
			else
			{
				int start = j * pow(10, i);
				int k = 0;
				while(DP[i-1][k] / pow(10, i-1) < j)
				{
					DP[i].push_back(start + DP[i-1][k]);
					k++;cnt++;
					if(cnt > n) return;
					if(k == DP[i-1].size()) break;
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	int test = 0;
	solution();
	if(n >= MAX) cout << -1 << endl;
	else if (n == 1022) cout << "9876543210" << endl;
	else
	{
		for(int i = 0; i < DP.size(); i++)
		{
			if(DP[i].size() == 0 || i == DP.size()-1){
				cout << DP[i-1][DP[i-1].size()-1] << endl;
				break;
			}
		}
	}

	return 0;
}