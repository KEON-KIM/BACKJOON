// #2467
#include<iostream>

#define MAX 100001
#define MAX_DATA 1000000000

using namespace std;

int n, board[MAX];
  

struct Answer
{	
	int hap;
	pair<int, int> ans;

	Answer(int a, pair<int, int> b)
	{
		hap = a;
		ans = b;
	}
	bool operator<(Answer answer) const{ 
        return hap < answer.hap;
    }
};
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> board[i];
	Answer answer = Answer(MAX_DATA*2, make_pair(-MAX, MAX)); 
	int left = 0, right = n-1;
	int sumation = 0;
	while(left < right)
	{
		sumation = board[left] + board[right];
		if(abs(sumation) < abs(answer.hap))
			answer = Answer(sumation, make_pair(board[left], board[right]));
		
		if(sumation < 0)
			left++;
		else if (sumation > 0)
			right--;
		else
			break;
	}
	cout << answer.ans.first << " " << answer.ans.second << endl;
	return 0;
}