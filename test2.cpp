#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<stack>

using namespace std;

void printmat(vector<vector<int>> &mat)
{
	cout << "|";
	for(vector<int> temp : mat)
	{
		for(int n : temp)
		{
			cout << n << "|";
		}
		cout << endl;
	}
	cout << endl;
}
void printv(vector<int> &v)
{
	cout << "|";
	for(int i : v)
	{
		cout << i << "|";
	}
	cout << endl;
}
bool visiting(vector<int> visit)
{
	int count = 0;
	for(int i = 0; i < visit.size(); i++)
	{
		if(visit[i] == 1) count++;
	}
	if(count == visit.size()) return 1;
	else return 0;
}
// queue<int> sorted(queue<int> que)
// {

// }
// vector<int> DFS(vector<vector<int>> node, int start, int count)
// {
// 	sort(node.begin(), node.end());
// 	vector<int> answer;
// 	stack<int> stack;
// 	vector<int> visit(count, 0);
// 	visit[start-1] = 1;

// 	answer.push_back(start);

// 	while(!visiting(visit))
// 	{
// 		for(int i = 0; i < node.size(); i++)
// 		{
// 			if(start == node[i][0]  && visit[node[i][1]-1] != 1 )
// 			{
// 				stack.push(node[i][1]);
// 				visit[node[i][1]-1] = 1;

// 				break;
// 			}
// 			else if(start == node[i][1] && visit[node[i][0]-1] != 1)
// 			{
// 				stack.push(node[i][0]);
// 				visit[node[i][0]-1] = 1;

// 				break;
// 			}
// 		}
// 		if(stack.size() != 0 ) // 가장작은 수의 노드 찾기 
// 		{			
// 			start = stack.top();
// 			stack.pop();
// 			answer.push_back(start);
// 		}
// 	}
// 	return answer;
// }
bool getin(vector<int> ans, int a)
{
	for(int i = 0; i < ans.size(); i++)
		if(ans[i] == a) return 1;
	
	return 0;
}

vector<int> DFS(vector<vector<int>> node, int start)
{
	sort(node.begin(), node.end());
	vector<int> answer;
	stack<int> stack;
	vector<int> visit(node.size(), 0);

	answer.push_back(start);

	while(!visiting(visit))
	{
		for(int i = 0; i < node.size(); i++)
		{
			if(start == node[i][0]  && visit[i] != 1)
			{
				stack.push(node[i][1]);
				visit[i] = 1;

				break;
			}
			else if(start == node[i][1]  && visit[i] != 1 )
			{
				stack.push(node[i][0]);
				visit[i] = 1;

				break;
			}
		}
		if(stack.size() != 0) // 가장작은 수의 노드 찾기 
		{			
			start = stack.top();
			stack.pop();
			if(!getin(answer, start))
			{
				answer.push_back(start);
			}
		}
	}
	return answer;
}

vector<int> BFS(vector<vector<int>> node, int start)
{
	sort(node.begin(), node.end());
	vector<int> answer;
	// priority_queue<int, vector<int>, greater<int>> pq;
	queue<int> pq;
	vector<int> visit(node.size(), 0);
	answer.push_back(start);

	while(!visiting(visit))
	{
		for(int i = 0; i < node.size(); i++)
		{
			if(start == node[i][0]  && visit[i] != 1 )
			{
				pq.push(node[i][1]);
				visit[i] = 1;
			}
			else if(start == node[i][1] && visit[i] != 1)
			{
				pq.push(node[i][0]);
				visit[i] = 1;
			}
		}
		if(pq.size() != 0) // 가장작은 수의 노드 찾기 
		{			start = pq.front();
			pq.pop();
			answer.push_back(start);
		}
	}

	return answer;
}
// int DFS(vector<vector<int>> node)
// {

// }

int main()
{
	int N,M,V;

	cin >> N >> M >> V;
	int a,b;
	vector<vector<int>> node;
	vector<int> ans;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		vector<int> temp ={a,b};

		node.push_back(temp);
	}

	ans = DFS(node, V);
	printv(ans);
	cout <<"|";
	ans = BFS(node, V);
	printv(ans);
	cout <<"|";

}