// #5052
// @Reference twpower <https://twpower.github.io/187-trie-concept-and-basic-problem>
#include <iostream>
#include <cstring>
#include <vector>

#define MAX 11
#define NUMBER 10
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T, N;
char phoneNum[10001][MAX];

int ToIndex(char key)
{
	return key - '0';
}
struct Trie{
	bool is_terminal; // this represents end of string
	Trie* children[NUMBER];

	// Constructor
	Trie() : is_terminal(false){
		memset(children, 0, sizeof(children));
	}

	// Delete all children
	~Trie()
	{
		for(int i = 0; i < NUMBER; ++i){
			if(children[i])
				delete children[i];
		}
	}

	void insert(const char* key){
		if(*key == '\0')
			is_terminal = true;
		
		else
		{
			int index = ToIndex(*key);

			if(children[index] == 0)
				children[index] = new Trie();
			children[index]->insert(key + 1);
		}
	}

	bool find(const char* key){
		if(*key == '\0')
			return true;
		
		if(is_terminal) return false;
		int index = ToIndex(*key);
		return children[index]->find(key+1);
	}
};

int main()
{
	cin >> T;
	Trie Tree;

	FOR(t , T)
	{
		string res = "YES";
		Trie Tree;

		cin >> N;
		FOR(i, N)
		{
			cin >> phoneNum[i];
			Tree.insert(phoneNum[i]);
		}

		FOR(i, N)
		{
			if(!Tree.find(phoneNum[i])){
				res = "NO";
				break;
			}
		}
		
		cout << res << endl;
	}
	return 0;
}

