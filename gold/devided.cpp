// #2228 : Dynamic Programming 
// @ Reference jaimemin <https://jaimemin.tistory.com/588>
#include<iostream>
#include<vector>

#define MAX 101

using namespace std;

const int MININF = -987654321;
const int MAX_SIZE = MAX;
int arr[MAX], cache[MAX][MAX/2][2];

int n, m, result;


void INIT()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < 2; k++)
				cache[i][j][k] = MININF;
}

int solution(int curIndex, int rangeNum, int selected)
{
	if(rangeNum == m)
		return 0;
	if(curIndex == n)
	{
		if(rangeNum == m-1 && selected)
			return 0;
		else
			return -32768 * n;
	}

	int &result = cache[curIndex][rangeNum][selected];
	if(result != MININF)
		return result;

	if(!selected)
		return result = max(solution(curIndex+1, rangeNum, false), arr[curIndex] + solution(curIndex+1, rangeNum, true));

	else
		return result = max(solution(curIndex+1, rangeNum+1, false), arr[curIndex] + solution(curIndex+1, rangeNum, true));
}

int main()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> arr[i];


	INIT();
	cout << solution(0,0,false) << endl;

	return 0;
}