// #5639
#include <iostream>
#include <cstring>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
using namespace std;

int tree[10001];
void dfs(int start, int end) {
	if (start >= end) {
		return;
	}
	if (start == end - 1) { // child node
		cout << tree[start] << endl;
		return;
	}
	int idx = start + 1;
	while (idx < end) { // left, right arrange
		if (tree[start] < tree[idx])
			break;
		idx++;
	}
	
	dfs(start+1, idx); // left node
	dfs(idx, end); // right node

	cout << tree[start] << endl; // root node
}

int main() {
	fastio;
	int num;
	int inputIdx = 0;
	while (cin >> num) 
		tree[inputIdx++] = num;

	dfs(0,inputIdx);



	return 0;
}