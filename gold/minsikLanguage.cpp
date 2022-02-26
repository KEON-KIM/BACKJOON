//#1599
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 51
#define AMAX 21
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N;
string board[MAX];
char cmp[AMAX] = {'a', 'b', 'k', 'd', 'e', 'g', 'h', 'i', 'l', 'm', 'n', ' ', 'o', 'p', 'r', 's', 't', 'u', 'w', 'y'};

int findIdx(char s)
{
	FOR(i, AMAX)
		if(cmp[i] == s)
			return i;
	return -1;	
}
bool bigger(string str1, string str2)
{
	int l = 0, r = 0;
	while(l < str1.length() && r < str2.length())
	{
		int left_Idx, right_Indx;
		left_Idx = findIdx(str1[l]);
		right_Indx = findIdx(str2[r]);
		if(str1[l] == 'n' && str1[l+1] == 'g')
		{
			left_Idx = 11;
			l++;
		}
		if(str2[r] == 'n' && str2[r+1] == 'g')
		{
			right_Indx = 11;
			r++;
		}
		if(left_Idx != right_Indx)
			return left_Idx < right_Indx;
		l++;
		r++;
	}
	return str1.length() < str2.length();
}

int main()	
{
	cin >> N;

	FOR(i, N)
	{
		cin >> board[i];
	}

	sort(board, board+N, bigger);
	FOR(i, N) cout << board[i] << endl;

	return 0;
}