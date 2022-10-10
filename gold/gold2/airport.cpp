// #10775
#include <iostream>
#include <vector>

#define MAX 100002
#define FOR(i, n) for(int i = 1; i <= n; i++)

using namespace std;

typedef long long ll;

int G, P, parents[MAX] = {0, };
int find(int gate)
{
	if(gate == parents[gate])
		return gate;
	return parents[gate] = find(parents[gate]);
}

void unions(int u, int v)
{
	u = find(u);
	v = find(v);

	parents[u] = v;
}

int main()
{
	cin >> G >> P;
	int result = 0;
	vector<int> board;

	FOR(i, G) parents[i] = i; // Init
	FOR(i, P)
	{
		int input;
		cin >> input;
		board.push_back(input);
	}

	for(int i = 0; i < board.size(); i++)
	{
		int gate = board[i];
		int docking = find(gate);

		if(docking)
		{
			unions(docking, docking-1);
			++result;
		}
		else break;
	}

	cout << result;
	return 0;
}