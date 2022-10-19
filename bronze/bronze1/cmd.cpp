#include <iostream>
#include <string>
#include <set>

#define MAX 51
#define alpha 26
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int N;
set<char> alphabet[MAX];
int main()
{
	cin >> N;
	string answer = "";
	FOR(i, N)
	{
		string input;
		cin >> input;
		FOR(s, input.length())
		{
			alphabet[s].insert(input[s]);
		}
	}
	FOR(i, MAX)
	{
		if(alphabet[i].size() > 1)
			answer += '?';
		else if(alphabet[i].size() > 0)
			answer += *alphabet[i].begin();
	}
	cout << answer;
	return 0;
}