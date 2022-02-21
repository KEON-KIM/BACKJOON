//#2224
//@Reference ongveloper <https://ongveloper.tistory.com/330>
#include<iostream>
#include<string>
#include<queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define MAX (122 - 65) + 1
#define MIN_DATA 65
#define MAX_DATA 122

using namespace std;

int N, count = 0;
bool board[MAX][MAX];
// bool visited[MAX][MAX];

/*void Print()
{
	queue<int> Que;

	Que.push(0);
	visited[0][0] = true;

	while(!Que.empty())
	{
		int idx = Que.front();
		Que.pop();
		FOR(i, MAX){
			if(board[idx][i] && !visited[idx][i] && i != idx){
				cout << (char)(idx + MIN_DATA) << " => " << (char)(i + MIN_DATA) << endl;
				visited[idx][i] = true;
				Que.push(i);
			}
		}
	}

	cout << "====== PRINT ====== " << endl;
	FOR(i, MAX){
		FOR(j, MAX){
			if(board[i][j] && i != j){
				cout << (char)(i + MIN_DATA) << " => " << (char)(j + MIN_DATA) << endl;
			}
			// cout << board[i][j] << " "; 
		}
		// cout << endl;
	}
}*/

void Print()
{
	FOR(i, MAX)
		FOR(j, MAX)
			if(board[i][j])
				cout << (char)(i + MIN_DATA) << " => " << (char)(j + MIN_DATA) << endl;
}

void Floyd()
{
	FOR(k, MAX)
		FOR(i, MAX)
			FOR(j, MAX)
			{
				if(board[i][j] || i == j) continue;
				board[i][j] = board[i][k] && board[k][j];
				if(board[i][j]) count++;
			}				
}
void Input()
{
	cin.ignore();
	string input;
	FOR(i, N){
		getline(cin, input);
		string tmp = "";
		for(char i : input)
			if(i >= MIN_DATA && i <= MAX_DATA)
				tmp += i;

		if(tmp[0] == tmp[1]) continue;
		if(board[tmp[0] - MIN_DATA][tmp[1] - MIN_DATA]) continue;
		count++;
		board[tmp[0] - MIN_DATA][tmp[1] - MIN_DATA] = true;
	}
}

int main()
{
	fastio;
	cin >> N;
	
	Input();
	Floyd();
	cout << count << endl;
	Print();
		
	return 0;
}