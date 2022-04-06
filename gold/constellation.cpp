#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 101
#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef pair<double, double> pdd;
typedef pair<double, pair<int, int>> pdii;

int N;
double result = 0;
double parent[MAX];
pdd input[MAX];
vector<pdii> board;

int Find(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}
 
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
 
    if (x != y) parent[y] = x;
}
 
bool SameParent(int x, int y)
{
    x = Find(x);
    y = Find(y);
 
    if (x == y) return true;
    else return false;
}
 
void Solution()
{
	FOR(i, N)
    {
        parent[i] = i;
    }
 
    FOR(i, board.size())
    {
        if (!SameParent(board[i].second.first, board[i].second.second))
        {
        	cout << result << endl;
            Union(board[i].second.first, board[i].second.second);
            result = result + board[i].first;
        }
    }
}

int main()
{
	cin >> N;
	FOR(i, N)
	{
		cin >> input[i].first;
		cin >> input[i].second;
	}

	FOR(i, N)
		for(int j = i; j < N; j++)
		{
			if(i == j) continue;
			board.push_back({round(sqrt(pow((input[i].first - input[j].first), 2)
											 + pow((input[i].second - input[j].second), 2)) * 100 )  / 100, {i,j}});
		}
	sort(board.begin(), board.end());
	Solution();

	cout << result << endl;
	return 0;
}