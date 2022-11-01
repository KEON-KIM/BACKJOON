#include<iostream>
#include<vector>

#define endl '\n'
#define MAX 100001
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int N;
int cnt = 0;
int board[MAX];
vector<int> v;
vector<char> result;

int main()
{	
	fastio;
	cin >> N;
	FOR(i, N) cin >> board[i];

	FOR(i, N)
	{
		v.push_back(i+1);
		result.push_back('+');

		while (!v.empty() && v.back() == board[cnt])
		{
			v.pop_back();
			result.push_back('-');
			cnt++;
		}
	}

	if (!v.empty()) cout << "NO";
	else FOR(i, result.size()) cout << result[i] << endl;
		
	return 0;
}