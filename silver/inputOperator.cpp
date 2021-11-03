//#14888

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, answer, v[100], op[4];
int minResult = 999999999;
int maxResult = -999999999;


void dfs(int value, int index)
{
	if(index < N)
	{
		
		if(op[0] > 0)
		{
			op[0]--;
			dfs(value+v[index], index+1);
			op[0]++;
		} 
		if(op[1] > 0)
		{
			op[1]--;
			dfs(value - v[index], index+1);
			op[1]++;
		}
		if(op[2] > 0)
		{
			op[2]--;
			dfs(value*v[index], index+1);
			op[2]++;
		}
		if(op[3] > 0){
			op[3]--;
			dfs(value/v[index], index+1);
			op[3]++;
		}
	}
	else
	{
		if(maxResult < value)
			maxResult = value;
		if(minResult > value)
			minResult = value;
	}
	
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}

	for(int i = 0; i < 4; i++){
		cin >> op[i];
	}
	dfs(v[0], 1);

	cout << maxResult << endl;
	cout << minResult << endl;

	return 0;
}