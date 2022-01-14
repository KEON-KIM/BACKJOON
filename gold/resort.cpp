// #13302
#include<iostream>
#include<cstring>

#define MAX 102
#define INF 1000000
using namespace std;

int N, M;
int board[MAX][MAX];
bool visited[MAX];

int dfs(int day, int coupon)
{

	int &ret = board[day][coupon];

	if(day >= N+1) return 0;
	if(ret != -1) return ret;
	if(visited[day])
		ret = dfs(day+1, coupon);

	else{
		ret = INF;
		ret = min(ret, dfs(day+1, coupon) + 10000);
		ret = min(ret, dfs(day+3, coupon+1) + 25000);
		ret = min(ret, dfs(day+5, coupon+2) + 37000);

		if(coupon >=3)
			ret = min(ret, dfs(day+1, coupon-3));
	}
	

	return ret;
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int date;
		cin >> date;
		visited[date] = true;
	}

	memset(board, -1, sizeof(board));
	cout << dfs(1, 0) << endl;

	return 0;
}
	/*int before = 0;

	board[0].insert(make_pair(0,0));
	for(int i = 1; i <= N; i++)
	{
		if(!visited[i])
		{
			for(pair<int, int> p : board[before])
			{
				int money = p.first;
				int coupon = p.second;

				if(coupon >= 3){
					board[i].insert(make_pair(money, coupon-3));
					continue;
				}

				board[i].insert(make_pair(money+10000, coupon));
				board[i+2].insert(make_pair(money+25000, coupon+1));	
				board[i+4].insert(make_pair(money+37000, coupon+2));
			}

			before = i;
		}
	}
	*/