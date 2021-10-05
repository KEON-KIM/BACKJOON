#include <queue>
#include <string>
#include <iostream>

using namespace std;

int solution(int N, int K)
{
	queue<int> que;
	int cnt[100001], depth = 0;
	que.push(N);
    
	while(!que.empty())
	{
		N = que.front();
		que.pop();

		if( N == K )break;

		if( N + 1 <= 100000 && cnt[N+1] == 0){
			que.push(N+1);
			cnt[N+1] = cnt[N]+1;
		}

		if (N - 1 >= 0 && cnt[N-1] == 0){
			que.push(N-1);
			cnt[N-1] = cnt[N]+1;
		}

		if (N * 2 <= 100000 && cnt[N*2] == 0){
			que.push(N*2);
			cnt[N*2] = cnt[N]+1;
		}
	}
	return cnt[N];
}

int main()
{
	int N, K;
	cin >> N >> K;
	cout << solution(N,K);
	return 0;
}