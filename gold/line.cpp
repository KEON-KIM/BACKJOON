#include<iostream>
#include<vector>
#include<string>

using namespace std;


int N, M; 

int main()
{
	cin >> N >> M;
	int  a, b;
	vector<int> next[N+1];
	int prev[N+1];
	string answer ="";

	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
	}

	
	// for(int i = 1; i <= N; i++) cout << node[i] << " ";
	return 0;
}