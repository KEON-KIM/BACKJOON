//#6416
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<cstring>

#define MAX 10001
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
using namespace std;


int idx = 0, node = 0;
int history[MAX];
bool visited[MAX];
vector<int> U, V;
vector<int> board[MAX];

void bfs(int root, int node)
{
	int cnt = 0;
	queue<int> Que;
	Que.push(root);
	visited[root] = true;

	if(!root)
	{
		cout << "Case "<< idx << " is not a tree." << endl;
		return ;
	}

	while(!Que.empty())
	{
		int cur = Que.front();
		Que.pop();

		for(int i = 0; i < board[cur].size(); i++)
		{
			int next = board[cur][i];
			if(visited[next])
			{
				cout << "Case "<< idx << " is not a tree." << endl;
				return;
			}
			Que.push(board[cur][i]);
			visited[next] = true;
		}
		cnt++;
	}

	if (node == cnt)
		cout << "Case "<< idx << " is a tree." << endl;
	else
		cout << "Case "<< idx << " is not a tree." << endl;
}

int isRoot()
{
	for(int i = 0; i < U.size(); i++)
	{
		bool flag = true;
		int root = U[i];

		for(int j = 0; j < V.size(); j++)
			if(root == V[j]) flag = false;
		
		if(flag) return root;	
	}

	return 0;
}

void CLEAR()
{
	for(int i = 0; i < U.size(); i++)
			if(board[U[i]].size())
				board[U[i]].clear();
	U.clear();V.clear();
	memset(visited, false, sizeof(visited));
	node = 0;
}

int main(){
	fastio;
	int u, v;
	while(true)
	{ 
		idx++;
		CLEAR();

		cin >> u >> v;
		if(u < 0 && v < 0) break;
		else if(u == 0 && v == 0) cout << "Case "<< idx << " is a tree." << endl;
		else
		{
			V.push_back(v);
			board[u].push_back(v);
			U.push_back(u);
			node++;
			while(1)
			{
				cin >> u >> v;
				if(u == 0 && v == 0)
				{
					int root = isRoot();
					bfs(root, node+1);
					break;
				}
				else
				{
					V.push_back(v);
					board[u].push_back(v);
					U.push_back(u);
					node++;
				}
			}
		}
	}

	return 0;
}

