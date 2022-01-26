#include<iostream>
#include<vector>

#define MAX 1000001
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
#define endl '\n';
#define FOR(i, k, n) for(int i = k; i < n; i++)

using namespace std;
typedef long long ll;

int T;
ll DP[MAX];
vector<ll> board(MAX+1, 1);

void prime(int n)
{
	FOR(i, 2, n)
		for(int j = 1; i * j <= n; j++)
			board[i*j] += i;
	
	FOR(i, 1, n)
		DP[i] = DP[i-1] + board[i];	
}

int main()
{
	DP[0] = 0;
	cin >> T;
	prime(MAX);

	FOR(i, 0, T)
	{
		int N;
		scanf("%d", &N);
		printf("%lld\n", DP[N]);
	}

	return 0;
}
/*
void divisor(int n){
	for(int i = 1; i * i <= n; i++)
		if(!(n%i))
			board[n] += (i == n/i)? i : (i+(n/i));
}

void prime(int n)
{
	board[1] = 1;
	FOR(i, 2, n+1)
		if(!board[i])
			for(int j = 2; j * i <= n; j++)
				if(!board[i*j])
					divisor(j*i);
}

void print()
{
	for(int i = 1; i < 11; i++)
		cout << board[i] << " ";
	cout << endl;
}
int main()
{
	cin >> T;
	FOR(i, 0, T)
	{
		int N;
		ll result = 0;
		cin >> N;
		prime(N);

		FOR(i, 1, N+1)
			if(!board[i]) // prime
				result += i + 1;
			else
				result += board[i];

		cout << result << endl;
		print();
	}
	return 0;
}*/