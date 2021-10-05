#include<vector>
#include<string>
#include<iostream>
#include<stack>

using namespace std;
int main()
{
	int V, E, S;
	int u,v,w;
	int MAX = 10;
	// stact<int> cache;

	cin >> V >> E;
	cin >> S;

	int dp[V+1][V+1] = { };
	vector<int> answer(V,MAX);
	vector<int> dic;

	for(int i = 0; i < V; i++)
		dp[i][i] = -1;

	for(int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		dp[u-1][v-1] = w;
	}


	for(int i = 0; i < V; i++)
	{
		if( dp[S-1][i] > 0)
		{
			dic.push_back(i);
			answer[i] = dp[S-1][i];
		}
		else if (dp[S-1][i] == -1)
		{
			answer[i] = -1;
		}
		else if (dp[S-1][i] == 0)
		{
			for(int j = 0; j < dic.size(); j++)
			{
				for(int k = 0; k < V; k++)
				{
					if(dp[dic[j]][k] > 0 && i == k)
					{
						answer[i] = (answer[i]<(dp[dic[j]][k] + dp[S-1][dic[j]]))? answer[i] : (dp[dic[j]][k] + dp[S-1][dic[j]]);
					}
				}
			}
			
		}
	}

	for(int i : answer)
	{
		if( i == MAX)
			cout << "INF" << endl;
		else if ( i == -1)
			cout << 0 << endl;
		else
			cout << i << endl;
	}

	return 0;
}