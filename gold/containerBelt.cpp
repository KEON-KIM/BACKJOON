#include<iostream>
#include<queue>
#define MAX 201
using namespace std;

int N, K, cnt = 0;
int contain[MAX];
bool visited[MAX];
queue<int> robots;

void move(int left, int right)
{
	const int size = robots.size();
	for(int i = 0; i < size; i++)
	{
		int location = robots.front();
		int next = (location + 1)%(2*N);// < 2*N ? location + 1 : 0;
		robots.pop();
		cout << "NEXT : " << next << " / " << !visited[next]<<" " << contain[next] << endl;
		if(!visited[next] && contain[next])
		{
			visited[location] = false;
			visited[next] = true;
			contain[next]--;
			// cout << "ROBOTS LOCATION : " << next << endl;
			if(!contain[next]) cnt++;
		}

		if(next == right)
			visited[next] = false;

		else
			robots.push(next);
	}
}

void rotate(int left, int right)
{
	const int size = robots.size();
	for(int i = 0; i < size; i++)
	{
		int location = robots.front();
		// int next = (location + 1)%(2*N);//< 2*N ? location + 1 : 0;
		robots.pop();
		// visited[location] = false;
		// visited[next] = true;

		if(location == right)
			visited[location] = false;
		else
			robots.push(location);
	}
}
void print()
{
	for(int i = 0; i < 2 * N; i++)
		cout << contain[i] << " ";
	cout << endl;
	for(int i = 0; i < 2 * N; i++)
		cout << visited[i] << " ";
	cout << endl;
}
int main()
{
	int result = 0;
	cin >> N >> K;
	for(int i = 0; i < 2 * N; i++)
		cin >> contain[i];
	

	int left = 0, right = N-1;
	while(cnt < K)
	{
		left = left - 1 < 0 ? left = 2*N-1 : left - 1;
		right = right - 1 < 0 ? right = 2*N-1 : right - 1;
		rotate(left, right);
		move(left, right);

		if(contain[left]){
			contain[left]--;
			visited[left] = true;
			robots.push(left);
			
			if(!contain[left])
				cnt++;	
		}
		cout << "ROBOT : " << robots.size() << endl;
		print();

		// if(cnt >= K) break;
		result++;
	}

	cout << result << endl;
	return 0;
}