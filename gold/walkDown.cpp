// #2096
#include <iostream>

#define INF 987654321
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int N;
pair<int, int> board[3]; // <min, max>
int dx[3][3] = {{0, 1, 0}, {-1, 0, 1}, {-1, 0, 0}};

void swap(pair<int, int>* a)
{
	FOR(i, 3)
	{
		board[i].first = a[i].first;
		board[i].second = a[i].second;
	}
}

int main()
{
	cin >> N;
	int a, b, c;
	cin >> a >> b >> c;
	int input[3] = {a, b, c};
	FOR(i, 3)
	{
		board[i].first = input[i];
		board[i].second = input[i];
		// cout << board[i].first << "/" << board[i].second << endl;
	}
				
	FOR(i, N - 1)
	{
		FOR(i, 3)
			cin >> input[i];
		pair<int, int> tmp[3];
		FOR(j, 3)
		{
			int mini = INF, maxi = 0;
			if(j == 1)
			{
				FOR(k, 3)
				{
					int x = j + dx[j][k];
					// cout <<x << " " << input[j] << endl;
					mini = min(mini, input[j] + board[x].first);
					maxi = max(maxi, input[j] + board[x].second);
				}
			}
			else
			{
				FOR(k, 2)
				{
					int x = j + dx[j][k];
					// cout << x << " " << input[j] << endl;
					mini = min(mini, input[j] + board[x].first);
					maxi = max(maxi, input[j] + board[x].second);
				}
			}
			// cout << "MINI : " << mini << " MAXI : " << maxi << endl;
			tmp[j].first = mini;
			tmp[j].second = maxi;
		}
		
		swap(tmp);
		// FOR(j, 3){
		// 	if(!j) cout << "(";
		// 	cout << board[j].first << " / " << board[j].second;
		// 	if(j != 2) cout << ") || (";
		// 	if(j == 2) cout << ")";
		// }
	}

	int mini = INF, maxi = 0;
	FOR(i, 3)
	{
		mini = min(mini, board[i].first);
		maxi = max(maxi, board[i].second);
	}

	cout << maxi << " " << mini << endl;
}