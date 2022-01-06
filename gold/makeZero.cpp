//#7490
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, D = INF, before = 1;
bool solution(string cmd)
{
	int res = 0, idx = 0;
	int num[11] = {0, };
	char chr[11] = {0, };

	for(int i = 0; i < cmd.size(); i++){
		if(cmd[i] > 48){
			if(num[idx]){
				// cout << "NUM :" << num[idx] << endl;
				num[idx] = num[idx]*10 + (cmd[i] - '0');
			}
			else
				num[idx] = cmd[i] - '0';
		}
		else{
			if(cmd[i] < 43){
				// cout << "?" << endl;
				continue;
			}
			else{
				chr[idx] = cmd[i];
				idx++;
			}
		}
	}
	// cout <<"CMD : " <<  cmd << endl;
	// for(int i = 0; i <= idx; i++)
		// cout << num[i] << " ";
	// cout << endl;
	// cout << chr << endl;
	res = num[0];
	for(int i = 0; i < idx; i++)
	{
		if(chr[i] == '+')
			res += num[i+1];
		else if(chr[i] == '-')
			res -= num[i+1]; 
	}
	// cout << "RESULT : " << res << endl;
	if(!res) return true;

	return false;
}

void bfs(int n){
	queue<pair<int, string>> Que;
	Que.push(make_pair(1, "1"));
	// Que.push(make_pair(1 * 10 + 2, "1 2"));
	// Que.push(make_pair(3, "1+2"));
	// Que.push(make_pair(-1, "1-2"));
	while(!Que.empty())
	{
		int x = Que.front().first;
		string cmd = Que.front().second;
		int before = cmd[cmd.size()-1] - '0';
		Que.pop();

		// cout << "CMD : " << cmd << " X : " << x<< endl;
		if(before == N) {
			// if(!x && before == N)
			if(solution(cmd))
				cout << cmd << endl;
			continue;
		}
		if(before >= N) continue;

		Que.push(make_pair(0, cmd +" " + (char)((before+1)+'0') ));
		Que.push(make_pair(x+(before+1), cmd +"+" + (char)((before+1)+'0') ));
		Que.push(make_pair(x-(before+1), cmd +"-" + (char)((before+1)+'0') ));
	}
}

// string ans = "1";
// void dfs(int n, int depth)
// {
// 	if(!n || depth == D){
// 		D = depth;
// 		// cout << ans << endl;
// 		return;
// 	} 
// 	ans = ans + "+" + (char)((n+1)+'0');
// 	cout << ans << endl;
// 	dfs(n+(n+1), depth+1);
// 	ans.erase(ans.end()-2);
// 	ans = ans + "-" + (char)((n+1)+'0');
// 	cout << ans << endl;
// 	dfs(n-(n+1), depth+1);
// 	ans.erase(ans.end()-2);
// 	// ans = ans + " " + (char)((n+1)+'0');
// 	// cout << ans << endl;
// 	// dfs(n*10 + (n+1), depth+1);
// 	// ans.erase(ans.end()-2);

// }

int main()
{
	int  T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> N;
		bfs(1);
		cout << endl;
	}

	// cout << INF+10 << endl;
	return 0;
}