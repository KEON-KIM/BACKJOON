#include<iostream>

using namespace std;

bool visit[15] ={false,};
int depth[15] = {0,};
int N, result = 0;

bool isEnter(int cur, int bef, int dep)
{
	int cmp;
	for(int i = 0; i < N; i++)
	{
		if(visit[i])
		{
			cmp = dep - depth[i];
			// cout << "CMP : " << cmp << " depth["<< i <<  "] : " << depth[i] << " CUR :" << cur << endl;
			// cout << "BEFORE : " << bef << " CURENT : " << cur << endl;
			if(cur == bef - cmp || cur == bef + cmp){return false;}
		}
	}
	return true;
}
void dfs(int x, int dep)
{
	for(int i = 0; i < N; i++)
	{
		// if(i == x-1 || i == x+1)continue;
		if (!visit[i] && isEnter(i,x,dep))
		{				
			cout << " @@@CURRENT " << i << " BEFORE : " << x  << " DEPTH : " << dep<< endl; 
			visit[i] = true;
			depth[i] = dep+1;
			dfs(i, dep+1);
			visit[i] = false;
		}	
	}
	if(dep == N-1) result++;
	else return;
	// cout << "EXIT : " << exit << endl;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		visit[i] = true;depth[i] = 1;
		dfs(i, 1);
		visit[i] = false;
		cout << "============================ : " << result << endl;
	}
	int v[10] ={false, };
	if(v[8]) cout << "?" << endl;

	cout << result << endl;

	return 0;

}