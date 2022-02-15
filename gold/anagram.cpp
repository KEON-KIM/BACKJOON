#include<iostream>
#include<cstring>
#include<algorithm>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)n
#define endl '\n'

using namespace std;
int N, len;
string input;

void swap(char& c1, char& c2)
{
	char c = c1;
	c1 = c2;
	c2 = c;
}

void dfs(string str, int idx) {
	if (idx == len - 1) {
		cout << str << endl;
		return;
	}

	for (int i = idx; i < len; i++) {
		if (i != idx && str[i] == str[idx])
			continue;
		if(str[i] != str[idx])
			swap(str[i], str[idx]);
		
		dfs(str, idx + 1);
	}
}


int main()
{
	cin >> N;
	FOR(i, N){
		cin >> input;

		sort(input.begin(), input.end());
		len = input.length();
		dfs(input, 0);
	}

	return 0;
}