// #1863
#include <iostream>
#include <stack>

#define endl '\n'
#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N;
stack<int> S;
int main()
{
	int idx, height, result = 0;
	cin >> N;
	FOR(i, N){
		cin >> idx >> height;
		if(S.empty() || S.top() < height)
			S.push(height);
		
		else 
		{
			while(!S.empty() && S.top() > height)
			{
				S.pop();
				result++;
			}
			if(S.empty() || S.top() < height)
				S.push(height);
		}
	}
	while(!S.empty())
	{
		if(S.top())
			result++;
		S.pop();
	}

	cout << result << endl;
	
	return 0;
}
