#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<iostream>

using namespace std;

vector<string> board;
vector<char> cache;
int N,M;
int result;
// int count;

// vector<string> updateBoard(char a,  )
// {
// 	for(int i = 0; i < N; i++){
// 		for(int j = 0; j < M; j++){
// 			if(board[i][j] == a)
// 			 	board[i][j] = '0';	
// 		}
// 	}

// 	return board;
// }
vector<char>::iterator iter;
void direction(int x, int y)
{
	if (x >= N || x < 0 || y >= M || y < 0)return;//{result = count>result?count:result; return;} 
	iter = find(cache.begin(), cache.end(), board[x][y]);
	// cout << iter << endl;
	if(iter != cache.end()) return;//{result = count>result?count:result; return;}
	// cache.erase(find(cache.begin(), cache.end(), board[x][y])); 
	cache.push_back(board[x][y]);
	direction(x+1, y);direction(x-1, y);direction(x, y+1);direction(x, y-1); 
}

// void direction(int x, int y, int count)
// {
	// else if(board[x][y] == '0') {cache.push_back(count); return;}
	// board = updateBoard(board[x][y], board);count++;
	// cout << cache.size() << endl;
// }


int main()
{
	string str;
	// vector<int> cache;

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> str;
		board.push_back(str);
	}
	direction(0,0);
	// cout << *std::max_element(cache.begin(), cache.end()) << endl;

	cout << cache.size() << endl;

	return 0;
}

