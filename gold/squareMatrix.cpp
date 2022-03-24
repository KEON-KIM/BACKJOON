// #10830
// @Reference cocoon1787 <https://cocoon1787.tistory.com/293>
#include<iostream>
#include<algorithm>
#include<vector>

#define MOD 1000
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

ll N, B;
ll A[5][5];
ll temp[5][5];
ll ans[5][5];

void Print()
{
	FOR(i, N)
	{
		FOR(j, N)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}

void Matrix_multi(ll X[5][5], ll Y[5][5])
{
	FOR(i, N)
		FOR(j, N)
		{
			temp[i][j] = 0; 
			FOR(k, N)
				temp[i][j] += (X[i][k] * Y[k][j]);

			temp[i][j] %= MOD;
		}

	FOR(i, N)
		FOR(j, N)
			X[i][j] = temp[i][j];
}

int main()
{
	cin >> N >> B;

	FOR(i, N)
	{
		FOR(j, N)
			cin >> A[i][j];
		ans[i][i] = 1; 
	}

	while (B > 0)
	{
		if (B % 2 == 1)
		{
			Matrix_multi(ans, A);
		}

		Matrix_multi(A, A);
		B /= 2;
	}

	Print(); // A를 B번 곱한 결과

}
/*#include <iostream>
#include <set>

#define MAX 5
#define MOD 1000
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, M;
bool finded[MAX][MAX];
int board[MAX][MAX];
int answer[MAX][MAX];
set<int> visited[MAX][MAX];

bool flag = false;
void print()
{
	FOR(i, N){
		FOR(j, N)
			cout << answer[i][j] << " ";
		cout << endl;
	}
}

bool Find(int idx)
{
	FOR(i, N)
		if(!finded[idx][i])
			return false;

	return true;
}

void dfs(int n, int idx)
{
	if( n == 1 ) return;
	// if(Find(idx))
	// {
	// 	cout << "FUCK" << endl;
	// 	FOR(i, N)
	// 	{
	// 		answer[idx][i] = visited[idx][i].count(((M - n)%visited[idx][i].size())-1);
	// 	}
	// 	return;
	// }
	int rows[MAX];
	FOR(i, N)
		rows[i] = answer[idx][i];

	FOR(i, N)
	{
		int res = 0;
		FOR(j, N)
			res += rows[j] * board[j][i];

		// if(finded[idx][i]){ // find
		// 	cout << visited[idx][i].size()<<endl;
		// 	answer[idx][i] = visited[idx][i].count(((M - n )% visited[idx][i].size())-1);
		// }
		// else
		// {
		res%=MOD;
		answer[idx][i] = res;

			// if(visited[idx][i].find(res) != visited[idx][i].end())
			// {
			// 	cout << "IDX : " << n << "res : " << res << endl;
			// 	finded[idx][i] = true;
			// 	// int dia = M - n; // cycle size
			// 	answer[idx][i] = visited[idx][i].count(((M -n)% visited[idx][i].size())-1);
			// }
			// visited[idx][i].insert(res);
		// }
	}

	dfs(n-1, idx);
}

int main()
{
	cin >> N >> M;
	FOR(i, N)
		FOR(j, N){
			cin >> board[i][j];
			answer[i][j] = board[i][j];
		}

	FOR(i, N)
		dfs(M, i);
	

	print();
	return 0;
}*/