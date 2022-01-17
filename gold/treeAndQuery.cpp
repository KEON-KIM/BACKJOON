#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

#define MAX 100001
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define endl '\n'

using namespace std;

int N, R, Q, result = 0;
bool visited[MAX];
pair<int, vector<int>> Tree[MAX]; // parent : child

void print()
{
	cout << "===========" << endl;
	for(int i = 1; i <= N; i++){
		cout <<"CURRENT : "<< i <<  " PARENT : " << Tree[i].first << "CHILDE : ";
		for(int j = 0; j < Tree[i].second.size(); j++){
			cout << Tree[i].second[j]<<" ";
		}
		cout << endl;
	}
}

void solution(int root)
{
	int result = 1;
	queue<int> Que;
	Que.push(root);
	visited[root] = true;
	while(!Que.empty())
	{
		int ch = Que.front();
		Que.pop();

		for(int i = 0; i < Tree[ch].second.size(); i++){
			if(visited[Tree[ch].second[i]]) continue;
			if(Tree[ch].first != Tree[ch].second[i]){
				Que.push(Tree[ch].second[i]);
				visited[Tree[ch].second[i]] = true;;
				result++;
			}
		}
	}

	cout << result << endl;
}

void make_Tree(int parent, int child)
{
	Tree[child].first = parent;
	visited[child] = true;

	for(int i = 0; i < Tree[child].second.size(); i++)
		if(!visited[Tree[child].second[i]])
			make_Tree(child, Tree[child].second[i]);
		
	
}

int main()
{
	fastio;
	cin >> N >> R >> Q;
	visited[R] = true;

	for(int i = 0; i < N-1; i++)
	{
		int u, v;
		cin >> u >> v;
		Tree[i].first = 0;
		Tree[u].second.push_back(v);
		Tree[v].second.push_back(u);
	}

	Tree[R].first = -1;
	make_Tree(-1, R);

	int q;
	for(int i = 0; i < Q; i++){
		int q;
		memset(visited, false, sizeof(visited));
		// result = 0;
		cin >> q;
		solution(q);
		// make_Tree(Tree[q].first, q);
		// cout << result << endl;
	}


	return 0;
}