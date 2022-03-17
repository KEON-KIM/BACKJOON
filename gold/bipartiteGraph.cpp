	// #1707
	#include <iostream>
	#include <vector>
	#include <cstring>
	#include <queue>

	#define endl '\n'
	#define MAX 20001
	#define FOR(i, n) for(int i = 1; i <= n; i++)
	#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

	using namespace std;

	int T, N, M;
	vector<int> board[MAX];
	bool visited[MAX][2]; // [index][pass/color] / [0] - false : unpassed , true : passed
												// [1] - false : red, true : black
	bool bfs(int v)
	{
		queue<int> Que;
		Que.push(v);
		// visited[v][0] = true // Delete : To check that visited all vertex.
		// visited[v][1] = true; // Delete : in case of bool type, a color reversal occurs simply. 
											//namely, need not to do BFS

		while(!Que.empty())
		{
			int idx = Que.front();
			Que.pop();

			for(int i : board[idx])
			{

				if(visited[i][0])
				{
					if(visited[i][1] == visited[idx][1]) //if same color of before value to color of after value, return false
						return false;

					continue; // if vistied vertex, continue; 
				}
				visited[i][0] = true;
				visited[i][1] = !visited[idx][1];
				Que.push(i);
			}
		}

		return true;
	}

	void Clear() // Initialization
	{
		memset(visited, false, sizeof(visited));
		FOR(i, N)
			board[i].clear();
	}

	int main()
	{
		int t = 1;
		cin >> T;
		while(T--)
		{
			bool flag = true;
			cin >> N >> M;
			FOR(i, M)
			{
				int v, e; cin >> v >> e;
				board[v].push_back(e);
				board[e].push_back(v);
			}

			FOR(i, N) // checking bipartite graph at all vertex
				if(!visited[i][0] && !bfs(i)) // if don't arrive the start point when start BFS at a start point,  
				{								// result value of visted[i][0] will be maintained 0.
					flag = false;
					break;
				}

			if(flag)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;

			Clear();
		}


		return 0;
	}