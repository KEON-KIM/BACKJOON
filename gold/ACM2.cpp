#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int T, N, K, D; 
int TIME[1001], prevN[1001];
vector<int> nextN[1001];

void Input()
{
	int X, Y;

	memset(TIME, 0, sizeof(TIME));
	memset(prevN, 0, sizeof(prevN));
	memset(nextN, 0, sizeof(nextN));

	cin >> N >> K;

	for(int i = 1; i <= N; i++)
		cin >> TIME[i];
	
	for(int i = 0; i < K; i++)
	{
		cin >> X >> Y;
		nextN[X].push_back(Y);
		prevN[Y]++;
	}
	
	cin >> D;
}

void solution() // Topological Sorting
{
	long long result[1001] = {0,};
	queue<int> Que;

	for(int i = 1; i <= N; i++)
		if(!prevN[i]) Que.push(i);

	while(prevN[D] > 0)
	{
		int cmp = Que.front();
		Que.pop();

		for(int next : nextN[cmp])
		{
			result[next] = result[next] > TIME[cmp] + result[cmp]? result[next] : TIME[cmp] + result[cmp] ;
			if(--prevN[next] == 0)Que.push(next);
		}
	}
	cout << result[D] + TIME[D] << endl;
}	

int main()
{
	cin >> T;

	for(int i = 0 ; i < T; i++)
	{
		Input();
		solution();
	}

	return 0;
}