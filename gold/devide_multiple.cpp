#include<iostream>
#include<set>

#define MAX 102
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef unsigned long long ll;

int N;
bool flag = false;
ll input, board[MAX], answer[MAX];
set<ll> dictionary;

void print()
{
	FOR(i, N)
		cout << answer[i] << " ";
	cout << endl;
}

int dfs(ll n, int dep)
{
	ll devide = n/3;
	ll mutiple = n*2;
	if(dep == N){
		flag = true;
		return 1;
	} 
	
	if(dictionary.find(devide) != dictionary.end() && !(n%3)){
		answer[dep] = devide;
		return dfs(devide, dep+1);
	}
	if(dictionary.find(mutiple) != dictionary.end()){
		answer[dep] = mutiple;
		return dfs(mutiple, dep+1);
	}

	return 0;
}

int main()
{
	cin >> N;
	ll input;
	FOR(i, N)
	{
		cin >> input;
		dictionary.insert(input);
		board[i] = input;
	}

	FOR(i, N){
		answer[0] = board[i];
		ll devide = board[i]/3;
		ll mutiple = board[i]*2;
		if(dictionary.find(devide) != dictionary.end() && !(board[i]%3)){
			answer[1] = devide;
			if(dfs(devide, 2)){
				print();
				return 0;
			}
		}
		if(dictionary.find(mutiple) != dictionary.end()){
			answer[1] = mutiple;
			if(dfs(mutiple, 2)){
				print();
				return 0;
			}
		}
	}
	
	return 0;
}