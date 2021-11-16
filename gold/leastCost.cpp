//#1916 < Dijkstr Algorithm Problem>

#include<iostream>
#include<queue>
#include<vector>

#define endl "\n"
#define MAX 100010
#define INF 987654321

using namespace std;

int Dist[MAX]; // distance
int N, M;
vector<pair<int, int>> Vertex[MAX]; // dest, cost


void Dijikstra(int Start)
{
	priority_queue<pair<int,int>> PQ;
	PQ.push(make_pair(0, Start)); // Cost, Cursor

	while(!PQ.empty())
	{
		int Cost = -PQ.top().first;
		int Cursor = PQ.top().second;
		cout << Cost << " | "<< Cursor << endl;
		PQ.pop();
		if(Dist[Cursor] < Cost) continue;

		for(int i = 0; i < Vertex[Cursor].size(); i++)
		{
			int next_ = Vertex[Cursor][i].first;
			int cost_ = Cost + Vertex[Cursor][i].second;
			if(Dist[next_] > cost_)
			{
				Dist[next_] = cost_;
				PQ.push(make_pair(-cost_, next_));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N;
	cin >> M;

	int a, b, c;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		Vertex[a].push_back(make_pair(b,c)); // dest, cost
	}
	// Dist init
	
	for(int i = 1; i <= N; i++) Dist[i] = INF; 

	cin >> a >> b;
	Dijikstra(a);	

	//print
	cout << Dist[b] << endl;


	return 0;
}