#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int K;
bool visited[11][501];
bool isBadword(string badword, string buf)
{
	int cnt = 0;
	int bad_size = badword.length();
	int buf_size = buf.length();

	if(buf_size != bad_size) return false;
	FOR(i, buf.length())
	{
		if(buf[i] == '.' || buf[i] == badword[i]) cnt++;
		else break;
	}

	if(cnt == bad_size) return true;
	return false;
}
bool dfs(vector<string> dic, string buf, int s_idx, int e_idx)
{
	for(int i = s_idx; i <  buf.length(); i++)
	{
		if(buf[i] == '.')
		{
			for(int k = 2; k <= K; k++)
			{
				string tmp;
				tmp.assign(k-1, '.');
				string next = buf.substr(0, i) + tmp + buf.substr(i, e_idx - i);
				cout << next << endl;
				if(dfs(dic, next, i + k, e_idx + k)) //continue;
					return true;
			}
		}
	}

	FOR(i, dic.size())
		if(isBadword(dic[i], buf))
			return true;
		
	return false;
}

string solution(int k, vector<string> dic, string chat)
{
	string answer = "";
	K = k;
	string buf;
	istringstream iss(chat);
	while(getline(iss, buf, ' '))
	{
		int s = buf.length();
		if(dfs(dic, buf, 0, buf.length()))
			buf.assign(buf.size(), '#');
		answer += buf + ' ';
	}
	answer.pop_back();
	return answer;
}
int main()
{
	vector<string> dic
		= {"slang", "badword"};
		// = {"abcde", "cdefg", "efgij"};
	string chat
		 = "badword ab.cd bad.ord .word sl.. bad.word";
		 // = ".. ab. cdefgh .gi. .z.";
	cout << solution(2, dic, chat);
	return 0;
}