// #1796
// @Reference devbelly <https://devbelly.tistory.com/31>
#include <iostream>
#include <cstring>
#include <climits>

#define ALPHA 26
#define MAX 1001
#define FOR(i,n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

string input;
int size, board[ALPHA][MAX];
int minDist[ALPHA], maxDist[ALPHA]; // ALPHA - 1
bool exist[ALPHA];

int Distance(int a, int b, int c,int d) { // a (-> b -> c )-> d
    if (c == -1 || d == -1) return 0;
    
    int A = abs(a - c);
    int B = abs(c - d);
    int C = abs(d - b);

    return A + B + C;	
}

int Solution(int alpha, int pos) {
    int posl = minDist[alpha];
    int posr = maxDist[alpha];
    int& ret = board[alpha][pos];
    
    if (alpha==26) return 0;
    if (ret != -1) return ret;

    ret = INT_MAX/2;
    if (exist[alpha]) 
        FOR(i, size)
            ret = min(ret, Solution(alpha + 1, i) + min(Distance(pos, i, posl, posr), Distance(pos, i, posr, posl)));
    else ret = Solution(alpha + 1, pos);
    
    return ret;
}

int main() {
    fastio;
    cin >> input;
    size = input.length();
    memset(board, -1, sizeof(board));
    memset(minDist, 0x3f, sizeof(minDist));
    memset(maxDist, -1, sizeof(maxDist));

    FOR(i, 26) 
    	FOR(j, size) 
    	{
        	if (input[j] - 'a' == i) 
        	{
            	exist[i] = true;
            	minDist[i] = min(minDist[i], j);	
            	maxDist[i] = max(maxDist[i], j);
        	}
  		}
    
    int ret = Solution(0, 0);
    cout << ret + size << endl;

    return 0;
}

/*#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define MAX 25

using namespace std;

vector<int> board[MAX];
int result = 0, cursor = 0;

bool mindist(int& a, int& b)
{
 	return abs(cursor - a) > abs(cursor - b);
}
int main()
{
	int maxIdx = 0;
	int minIdx = MAX;
	string input;
	cin >> input;
	FOR(i, input.length())
	{
		maxIdx = max(maxIdx, input[i]-'a');
		minIdx = min(minIdx, input[i]-'a');
		board[input[i]-'a'].push_back(i);
	}

	if(maxIdx!=min)
	{
		for(int i = MAX-1; i >= 0; i--)
		{
			int size = board[i].size();
			if(size)
			{
				sort(board[i].begin(), board[i].end(), mindist);
				cursor = board[i][0];
			}
		}
	} 
	
	cursor = 0;
	for(int i = minIdx; i < MAX; i++)
	{
		int size = board[i].size();
		FOR(j, size)
		{
			result += abs(cursor - board[i][j]) + 1;
			cursor = board[i][j];
		}
	}

	cout << result << endl;
}
	return 0;*/