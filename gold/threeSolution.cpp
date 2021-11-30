// #2473 TwoPoints Algorithms
#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_SIZE 5001
#define MAX 1000000001

using namespace std;

struct Node
{
	long long x, y, z;
	Node(long long a, long long b, long long c)
	{
		x = a;
		y = b;
		z = c;
	}
};

long long board[MAX_SIZE], n;
Node node = Node(MAX, MAX, MAX);

int median(int a, int b, int c)
{
	int maxi = max(max(a,b),c);
	int mini = min(min(a,b),c);
	return a ^ b ^ c ^ maxi ^ mini;
}
void solution()
{
	long long minimum = node.x + node.y+ node.z;
	for(int i = 0; i < n; i++)
	{
		int j = i+1, k = n-1;
		while(1)
		{
			if(j >= k) break;
			long long sum = board[i] + board[j] + board[k];
			
			if(minimum > llabs(sum)){
				minimum = llabs(sum);
				node.x = board[i];
				node.y = board[j];
				node.z = board[k];
			}

			if(sum < 0)
				j++;
			else
				k--;
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> board[i];

	sort(board, board+n); // sort for using twopoints algorithm
 	solution();

 	// cout << min(min(node.x,node.y),node.z) << " " << median(node.x,node.y,node.z) << " " << max(max(node.x, node.y), node.z) << endl;
 	cout << node.x << " " << node.y << " " << node.z << endl;
	return 0;
}