#include <iostream>

#define MAX 500001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M;
int parents[MAX];
int find(int a)
{
	if(parents[a] == a)
		return a;
	else
		return parents[a] = find(parents[a]);
}

bool union_node(int a, int b)
{
	a = find(a);
	b = find(b);

	if(a == b) return true;
	else
	{		
		parents[a] = b;
		return false;
	}
}

int main()
{
	cin >> N >> M;
	FOR(i, N)
		parents[i] = i;
	
	int a, b, res = 0;
	FOR(i, M)
	{
		cin >> a >> b;
		if(union_node(a, b)) {res = i+1; break;}
	}
	cout << res << endl;
	return 0;
}