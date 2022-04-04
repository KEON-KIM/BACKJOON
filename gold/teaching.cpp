#include <iostream>
#include <cstring>

#define MAX 51
#define ALPHA 26
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N, K, result = 0;
int visited;
int word[MAX];

void dfs(int dep, int idx, int visit)
{

	if(dep == K)
	{
		int cnt = 0;
		FOR(i, N)
			if((word[i] & visit) == word[i]) cnt++;

		result = max(result, cnt);
		return;
	}

	for(int i = idx; i < ALPHA; i++)
	{
		if((visit & (1 << i)) == 0)
		{
			visit |= (1 << i);
			dfs(dep + 1, i, visit);
			visit &= ~(1 << i);
		}
	}

}
int main()
{
	cin >> N >> K;
	FOR(i, N)
	{
		string input;
		cin >> input;

        int num = 0;
		for(char chr : input)
		{
            num |= 1 << (chr - 'a');
        }
        word[i] = num;
	}

	if(K < 5) cout << 0; 
    else if (K == ALPHA) cout << N;
    else
    {    
        visited |= 1 << ('a'-'a');
        visited |= 1 << ('n'-'a');
        visited |= 1 << ('t'-'a');
        visited |= 1 << ('i'-'a');
        visited |= 1 << ('c'-'a');
        
        dfs(5, 0, visited);
        cout << result;
    }

	return 0;
}