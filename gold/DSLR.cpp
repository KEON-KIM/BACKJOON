// #9019
// @Reference donggoolosori <https://donggoolosori.github.io/2020/10/05/boj-9019/>
#include<iostream>
#include<cstring>
#include<queue>

#define MOD 10000
using namespace std;

int N, visited[MOD];
int input, answer;

string bfs()
{
	int D, S, L, R, cur;
	string op;

	queue<pair<int, string>> Que;
	Que.push(make_pair(input, ""));
	visited[input] = 1;
	
	while(!Que.empty())
	{
		cur = Que.front().first;
		op = Que.front().second;

		Que.pop();

		if(cur == answer) break;
		else
		{

			D = (cur * 2 )%MOD;
			if(!visited[D]){ // D
				visited[D] = 1;
				Que.push(make_pair(D, op + 'D'));
			}
			S = cur - 1 < 0 ? 9999 : cur - 1;
			if(!visited[S]) //S
			{
				visited[S] = 1;
				Que.push(make_pair(S, op + 'S')); 
			}
			L = (cur % 1000) * 10 + (cur / 1000);
			if(!visited[L]) //L
			{
				visited[L] = 1;
				Que.push(make_pair(L, op + 'L'));
			}

			R = (cur % 10) * 1000 + (cur / 10);
			if(!visited[R])
			{
				visited[R] = 1;
				Que.push(make_pair(R, op + 'R'));
			}
		}
	}

	return op;
}

int main()
{
	cin >> N;
	
	string operate = "";

	for(int i = 0; i < N; i++){
		cin >> input >> answer;
		memset(visited, 0, sizeof(visited));
		cout << bfs() << endl;
	}

	return 0;
}