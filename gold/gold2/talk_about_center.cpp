//#1655
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MOD 1001
#define MAX 1000002
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;

using namespace std;

int main()
{
	fastio;
	int N, input;
	priority_queue<int> asc_pQue;
	priority_queue<int, vector<int>, greater<int>> desc_pQue;

	cin >> N;
	FOR(i, N)
	{
		cin >> input;
		if(asc_pQue.size() == desc_pQue.size())
			asc_pQue.push(input);
		
		else
			desc_pQue.push(input);

		if(!asc_pQue.empty() && !desc_pQue.empty() && asc_pQue.top() > desc_pQue.top())
		{
			int max_val = asc_pQue.top();
			asc_pQue.pop();
			int min_val = desc_pQue.top();
			desc_pQue.pop();

			desc_pQue.push(max_val);
			asc_pQue.push(min_val);
		}
		cout << asc_pQue.top() << endl;
	}

	return 0;
}