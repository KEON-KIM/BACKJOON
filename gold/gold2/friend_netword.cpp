//#4195
//@Reference chanhuiseok <https://chanhuiseok.github.io/posts/baek-21/>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

#define MAX 200002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, M;
int parents[MAX], values[MAX];
int finds(int x)
{
	if(parents[x] == x) return x;
	return parents[x] = finds(parents[x]);
}
void unions(int a, int b)
{
	a = finds(a);
	b = finds(b);
	if(a != b)
	{
		if(values[a] < values[b]) swap(a, b);
		values[a] += values[b];
		parents[b] = a;
	}
}
int main()
{
	cin >> N;
	FOR(n, N)
	{
		map<string, int> index_map;
		string input[2];
		int idx = 0;
		FOR(i, MAX)
		{
			values[i] = 1;
			parents[i] = i;
		}

		cin >> M;
		FOR(m, M)
		{
			cin >> input[0] >> input[1];
			FOR(i, 2)
				if(!index_map[input[i]])
					index_map[input[i]] = ++idx;

			unions(index_map[input[0]], index_map[input[1]]);
			int p1 = finds(index_map[input[0]]);
			int p2 = finds(index_map[input[1]]);
			cout << max(values[p1], values[p2]) << endl;
		}
	}
	return 0;
}