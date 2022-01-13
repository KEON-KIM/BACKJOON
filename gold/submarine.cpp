// #2671
// @Reference Kim Nanyoung <nanyoungKim.tistory.com/m/170>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define MAX 500

using namespace std;
string input;

int main()
{
	cin >> input;
	map<string, vector<string>> umap;
	// 0 : curChar = 0 /  1 : curchar = 1
	umap["init"] = {"0", "1"};
	umap["0"] = {"X", "01"};
	umap["1"] = {"10", "X"};
	umap["01"] = {"0", "1"};
	umap["10"] = {"100", "X"};
	umap["100"] = {"100~", "100~1"};
	umap["100~"] = {"100~", "100~1"};
	umap["100~1"] = {"0", "100~1~"};
	umap["100~1~"] = {"10 || 0", "100~1~"};
	umap["10 || 0"] = {"100", "01"};

	string state = "init"; // start

	// for(int i = 0; i < str.length(); i++)
	FOR(i, input.length())
	{
		int nextChar = input[i] - '0';
		state = umap[state][nextChar];
		if(state == "X") break;		
	}

	if(state == "100~1" || state == "01" || state == "100~1~") cout << "SUBMARINE" << endl;
	else cout << "NOISE" << endl;

	return 0;
}