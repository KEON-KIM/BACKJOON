// #3020
#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 500004

using namespace std;

// int board[MAX];
int N, H;
int main()
{
	cin >> N >> H;
	vector<int> top(N/2), bottom(N/2);
	for(int i = 0; i < N/2; i++)
		cin >> bottom[i] >> top[i];

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int MIN = MAX, result = 1;

	for(int i = 1; i <= H; i++)
	{
		int crash = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) 
			- bottom.begin());
			
		crash += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

		if(MIN == crash)
			result ++;
		else if(MIN > crash)
		{
			MIN = crash;
			result = 1;
		}
	}

	cout << MIN << " " << result << endl;
	return 0;
}

// void solution() // 완탐 시간초과
// {
// 	int result = 0, MIN = MAX;
// 	for(int i = 1; i <= H; i++)
// 	{
// 		int crash = 0;
// 		for(int j = 1; j <= N; j++)
// 		{
// 			if(j%2)//ghf
// 			{
// 				if(i <= board[j])
// 					crash++;
// 			}
// 			else
// 			{
// 				if(i > H - board[j])
// 					crash++;
// 			}
// 		}
// 		if(crash <= MIN)
// 		{
// 			if(crash == MIN) result ++;
// 			else result = 1;
// 			MIN = crash;
// 		}
// 	}

// 	cout << MIN << " " << result << endl;
// }
// void print()
// {
// 	for(int i = 1; i <= H; i++)
// 		cout << board[i] << " ";
	
// 	cout << endl;
// }
// int main() // 시간초과
// {
// 	cin >> N >> H;
// 	int input, MIN = MAX, result = 0;
// 	for(int i = 1; i <= N; i++){
// 		cin >> input;
// 		if(i%2)
// 			for(int j = 1; j <= input; j++)
// 				board[j]++;
			
// 		else
// 			for(int j = H; j > H - input; j--)
// 				board[j]++;
// 	}

// 	for(int i = 1; i <= H; i++){
// 		if(board[i] <= MIN){
// 			if(board[i] == MIN) result++;
// 			else result = 1;
// 			MIN = board[i];
// 		}
// 	}

// 	cout << MIN << " " << result << endl;

// 	return 0;
// }
