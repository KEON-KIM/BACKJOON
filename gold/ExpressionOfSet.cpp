//#1717
// @Reference bbwwpark <https://blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=kks227&logNo=220791837179&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=false&from=menu>
// mapocodingpark <https://mapocodingpark.blogspot.com/2020/02/BOJ-1717.html> 
#include<iostream>

#define MAX 1000010
#define endl '\n'

using namespace std;

int N, M;
int graph[MAX];


int find_root(int a)
{
	if(graph[a] < 0) return a;
	int root = find_root(graph[a]);
	graph[a] = root;
	return root;
}
void Union(int a, int b)
{
	a = find_root(a);
	b = find_root(b);
	if(a == b) return;
	graph[a] = b;
}
int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int a, b, order;

	//input
	cin >> N >> M;
	for(int i = 0; i <= N; i++)
		graph[i] = -1;
	
	for(int i = 0; i < M; i++)
	{
		cin >> order >> a >> b;
		if(!order)
			Union(a, b);
		
		else
		{
			if(find_root(a) != find_root(b))
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}

	return 0;
}
