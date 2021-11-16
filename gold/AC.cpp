//#5430
#include<string>
#include<iostream>
#include<vector>

#define MAX 100001
using namespace std;

int N, M;
vector<vector<int>> board;
vector<string> todo;

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		vector<int> tmp;
		string cmd, str;

		cin >> cmd;
		cin >> M;
		cin >> str;
		todo.push_back(cmd);
		// make array
		int idx = 0;
		for(int i = 0; i < M; i++)
		{
			string str_arr = "";
			for(int j = idx; j < str.size(); j++)
			{
				if(str[j] == ']' || str[j] == ','){
					idx = j+1;
					break;
				}
				else if (str[j] - '0' > -1 && str[j] - '0' < 10)
					str_arr += str[j];
			}
			tmp.push_back(stoi(str_arr));
		}
		board.push_back(tmp);
	}
	//print
	// for(int i = 0; i < N; i++)
	// {
	// 	for(int value : board[i])
	// 		cout << value << " ";
	// 	cout << endl;
	// }

	for(int i = 0; i < N; i++)
	{
		// int rev_cur = board[i].size() > 1 ? board[i].size() - 1 : 0;
		int rev_cur = board[i].size();
		int ori_cur = 0;
		bool reverse = false;

		for(int j = 0; j < todo[i].size(); j++)
		{
			if (todo[i][j] == 'R')
				reverse = !reverse;
			
			else
			{
				if(reverse) rev_cur--;
				else ori_cur++;
			}
		}
		//print result
		if(reverse)
		{
			if(rev_cur >= ori_cur){
				cout << "[";
				if(rev_cur != ori_cur)
					for(int j = rev_cur-1; j >= ori_cur; j--){
						if (j == ori_cur) cout << board[i][j];
						else cout << board[i][j] << ",";
					}
				cout <<"]"<< endl;
			}
			// else if (rev_cur >= ori_cur && rev_cur == 0) cout << "[]" << endl;
			else
				cout << "error" << endl;
		}

		else{
			// cout << ori_cur << " | " << rev_cur << endl;
			if(ori_cur <= rev_cur ){
				cout << "[";
				if(ori_cur != rev_cur)
					for(int j = ori_cur; j < rev_cur; j++){
						if(j == rev_cur -1)cout << board[i][j];
						else cout << board[i][j] << ",";
					}
				cout <<"]"<< endl;
			}

			// else if (rev_cur <= ori_cur && ori_cur == 0) cout << "[]" << endl;
			else
				cout << "error" << endl;
		}
	}

	return 0;
}