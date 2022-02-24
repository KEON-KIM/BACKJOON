//#2668
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

#define MAX 102

using namespace std;

int board[MAX], n;
vector<int> result;
// ve
void print()
{
	for(int i : result)
		cout << i << " ";
	cout << endl;
}

void bfs(int start){
	int visited[MAX];
	
	stack<pair<int, int>> S;
	stack<int> cache;
	int dest = start;
	bool isFind = false;

	S.push(make_pair(start, board[start]));
	cache.push(start);

	while(!S.empty())
	{
		int cur = S.top().first;
		int next = S.top().second;
		S.pop();

		// cout << "CURRENT : " <<cur <<"|"<< next <<"|"<<S.size()<<"|" << dest<< endl;
		if(visited[cur]) {
			cout << "VISI" << endl;
			continue; 
		}
		if(next == dest) {
			cout << "FUCK" << endl;
			cache.push(cur);
			isFind = true;
			continue;
		}

		else if(cur == next) {
			cout << "WHAT" << endl;
			result.push_back(cur);
			continue;
		}
		visited[cur] = 1;
		cache.push(cur);
		S.push(make_pair(next, board[next]));
	}

	if(isFind)
	{
		while(!cache.empty()){
			result.push_back(cache.top());
			cache.pop();
		}
	}

	// for(int i = 1; i <= n; i++)
	// 	S.push(make_pair(i, board[i]))
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> board[i];
		// if(i == board[i])
		// 	result.push_back(board[i]);	
		
	}
	for(int i = 1; i <= n; i++)
	{
		bfs(i);
	}
	// cout << result.size() << endl;
	print();

	return 0;
}