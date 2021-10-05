#include<iostream>

using namespace std;

bool visit[15] ={false,};
int depth[15] = {0,};
int N, result = 0;

bool dia(int before, int cur, int dep)
{
	for(int i = 0; i < N; i++)
	{
		if(visit[i])
		{
			if( cur == i + (dep - depth[i] ) || cur == i - (dep - depth[i]))
			{
				return false;
			}
		}
	}
	return true;
}

// index == before
void dfs(int index, int dep)
{
	// cout << "fuck" << endl;
	for(int i = 0; i < N; i++){
		if(!visit[i] && dia(index, i, dep+1))
		{
			visit[i] = true;
			depth[i] = dep+1;
			dfs(i, dep+1);
			visit[i] = false;
		}
	}
	if(dep > N-1) result++;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		visit[i] = true;
		depth[i] = 1;
		dfs(i, 1);
		visit[i] = false;
	}
	cout <<result<< endl;
	return 0;
}