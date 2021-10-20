//#1753 < Dijkstr Algorithm Problem>
//@yabmoons Reference <https://yabmoons.tistory.com/376>
#include<iostream>
#include<queue>
#include<vector>

#define endl "\n"
#define MAX 20001
#define INF 987654321

using namespace std;

int Dist[MAX];
int V, E, Start;
vector<pair<int, int>> Vertex[MAX];

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> V >> E;
	cin >> Start;
	int a, b, c;
	for(int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		Vertex[a].push_back(make_pair(b,c));
	}
	// Dist init
	for(int i = 1; i <= V; i++) Dist[i] = INF; 

	priority_queue<pair<int,int>> PQ;
	PQ.push(make_pair(0, Start));
	Dist[Start] = 0;
	cout << Dist[1] << endl;
	while(!PQ.empty())
	{
		int Cost = -PQ.top().first;
		int Cursor = PQ.top().second;
		PQ.pop();

		for(int i = 0; i < Vertex[Cursor].size(); i++)
		{
			int next_ = Vertex[Cursor][i].first;
			int cost_ = Vertex[Cursor][i].second;

			if(Dist[next_] > Cost + cost_)
			{
				Dist[next_] = cost_+ Cost;
				PQ.push(make_pair(-Dist[next_], next_));
			}
		}
	}
	//print
	for(int i = 1; i <= V; i++)
	{
		if(Dist[i] == INF) cout << "INF" << endl;
		else cout << Dist[i] << endl;
	}

	return 0;
}