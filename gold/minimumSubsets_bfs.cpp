#include<iostream>
#include<queue>
#define INF 987654321
using namespace std;

int arr[1001], n, sumTotal = 0, answer;
queue<pair<int, int>> Que;

void bfs()
{
	int index, sum;

	while(!Que.empty())
	{
		 index = Que.front().first;
		 sum = Que.front().second;
		 Que.pop();

		 answer = min(answer, abs(sum - (sumTotal - sum)));
		 
		 if( n <= index || sum * 2  > sumTotal) continue;
		 if(sum*2 == sumTotal){
		 	answer = 0;
		 	return;
		 }
		 else
		 {
		 	Que.push(make_pair(index+1, sum+arr[index]));
		 	Que.push(make_pair(index +1, sum));
		 }
	}
}
int main()
{
	cin >> n;
	answer = INF;

	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sumTotal += arr[i];
	}
	Que.push(make_pair(0, 0));

	bfs();

	cout << answer << endl;

	return 0;
}