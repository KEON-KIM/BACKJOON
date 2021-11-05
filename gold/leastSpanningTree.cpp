//#1197 - Krusckal Algorithm / Prim's Algorithm
//@Reference woga1999 <https://velog.io/@woga1999/BOJ-1197%EB%B2%88-%EC%B5%9C%EC%86%8C-%EC%8A%A4%ED%8C%A8%EB%8B%9D-%ED%8A%B8%EB%A6%AC-C>

#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 10010

using namespace std;

int V, E, answer = 0;
int board[MAX];
int ch[MAX];

struct Data{
	int v, e, c;
	Data(int ve, int end, int cost)
	{
		v = ve;
		e = end;
		c = cost;
	}
	bool operator<(Data &d) // Operator for Ascending value
	{
		return c < d.c;
	}
};
int Find(int v)
{
	if(v == board[v]) return v;
	else return board[v] = Find(board[v]);
}

void Union(int a, int b, int c)
{
	a = Find(a);
	b = Find(b);
	if(a != b) 
	{
		board[a] = b;
		answer += c;
	}
}
int main()
{
	int a, b, c;
	vector<Data> cache;

	//input
	cin >> V >> E;
	for(int i = 1; i <= V; i++)
		board[i] = i;
	for(int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		cache.push_back(Data(a,b,c));
	}
	sort(cache.begin(), cache.end()); // using Operator of Data struct
	for(int i = 0; i < cache.size(); i++)
		Union(cache[i].v, cache[i].e, cache[i].c);
	
	cout << answer << endl;

	return 0;
}
