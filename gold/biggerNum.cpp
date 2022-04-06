//#2812
#include <iostream>
#include <stack>
#include <string>

#define MAX 500001
#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, K;
int num[MAX];
string answer = "";

int main()
{
	string input;
	stack<int> st;
	cin >> N >> K;
	cin >> input;
	FOR(i, N){
		int num = input[i];
		if(!st.empty()){
			while(!st.empty() && st.top() < num && (N - K - st.size()) <= N - i - 1)
				st.pop();

			if(st.size() < N - K)
				st.push(num);
		}
		else
			st.push(num);
	}
	while(!st.empty())
	{
		answer += st.top();
		st.pop();
	}

	for(int i = answer.size()-1; i >= 0; i--)
		cout << answer[i];
	return 0;
}