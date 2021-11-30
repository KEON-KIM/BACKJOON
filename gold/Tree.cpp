//#1068
#include <iostream>
#include <cstring>
#include <queue>

#define MAX 51

using namespace std;

int n, k, root, result = 0;
int Tree[MAX] = {-1, };

void delete_node(int key) // bfs
{
	queue<int> Que;
	int cursor;

	Tree[key] = -1;
	Que.push(key);

	while(!Que.empty())
	{
		cursor = Que.front();
		Que.pop();

		for(int i = 0; i < n; i++)
			if(cursor == Tree[i])
			{
				Que.push(i);
				Tree[i] = -1;
			}
		
	}
}

void find_leaf() // bfs;
{
	queue<int> Que;
	Que.push(root);

	int node;
	bool exist;
	while(!Que.empty())
	{
		exist = false;
		node = Que.front();
		Que.pop();

		for(int i = 0; i < n; i++)
		{
			if(node == Tree[i]){
				Que.push(i);
				exist = true;
			}
		}
		if(!exist) result++; 
	}
}

int main()
{
	memset(Tree, -1, sizeof(Tree));
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> Tree[i];
		if(Tree[i] < 0) root = i;
	}

	cin >> k;
	delete_node(k);
	if(k != root) 
		find_leaf();
	cout << result << endl;
	return 0;
}