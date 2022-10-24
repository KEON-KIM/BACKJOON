//#2109
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 10002
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, visited[MAX];
struct Data
{
	int x, y;
	Data(int a, int b)
	{
		x = a;
		y = b;
	}
};
struct cmp
{
	bool operator()(const Data &lhs, const Data &rhs)
	{
		if(lhs.x == rhs.x) return lhs.y > rhs.y;
		else return lhs.x < rhs.x;
	}
};
int main()
{
	fastio;
	cin >> N;
	vector<Data> tmp;
	int price, date, maxi = -1;
	memset(visited, -1, sizeof(visited));
	priority_queue<Data, vector<Data>, cmp> pQue;
	FOR(i, N)
	{
		cin >> price >> date;
		maxi = max(maxi, date);
		pQue.push(Data(price, date));
	}

	while(!pQue.empty())
	{
		int d = pQue.top().y;
		int p = pQue.top().x;
		pQue.pop();
		if(visited[d] < p) visited[d] = p;
		else
		{			
			for(int i = d-1; i >= 1; i--)
			{
				if(visited[i] < p)
				{
					visited[i] = p;
					break;
				}
			}
		}
	}
	int result = 0;
	FOR(i, maxi)
	{
		if(visited[i] != -1)
			result += visited[i];
	}cout << result;
	return 0;
}

/*13
45 1
15 2
10 3
10 5
5 5
3 5
2 5
60 6
40 6
10 8
20 8
30 8
40 8
*/