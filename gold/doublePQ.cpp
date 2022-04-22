// #7662
// @Reference jaimemin <https://jaimemin.tistory.com/997>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1000001
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int T, N;
bool visited[MAX];
typedef pair<int ,int> pii;
int main()
{
	cin >> T;
	FOR(i, T)
	{
		cin >> N;
		priority_queue<pii> pq1; // max
		priority_queue<pii, vector<pii>, greater<pii>> pq2; // min
		FOR(j, N)
		{
			char cmd; int info;
			cin >> cmd >> info;
			if(cmd == 'I')
			{
				pq1.push({info, j});
				pq2.push({info, j});
				visited[j] = true;
			}
			else
			{
				if(info > 0)
				{
					while(!pq1.empty() && !visited[pq1.top().second])
						pq1.pop();
					if(!pq1.empty())
					{
						visited[pq1.top().second] = false;
						pq1.pop();
					}
				}
				else
				{
					while(!pq2.empty() && !visited[pq2.top().second])
						pq2.pop();
					if(!pq2.empty())
					{
						visited[pq2.top().second] = false;
						pq2.pop();
					}
				}
			}
		}
		while(!pq1.empty() && !visited[pq1.top().second]) pq1.pop();
		while(!pq2.empty() && !visited[pq2.top().second]) pq2.pop();

		if(pq1.empty() && pq2.empty()) cout << "EMPTY" << endl;
		else cout << pq1.top().first << " " << pq2.top().first << endl;
	}

	return 0;
}