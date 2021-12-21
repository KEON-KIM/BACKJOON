// #1360
// @Reference <gumeum> https://gumeum.tistory.com/29

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N;
vector<pair<string,int>> ans; // cache, sec;
string solution(int sec)
{
    for(int i = ans.size()-1; i >= 0; i--)
        if(sec > ans[i].second) 
        	return ans[i].first;
    
    return "";
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int sec;
        string cmd, value;
        cin >> cmd >> value >> sec;
        if(cmd == "type") 
        {
            string cache;
            if(ans.size()) cache = ans.back().first + value;
            else cache = value; 
            ans.push_back(make_pair(cache, sec));
        }
        else
            ans.push_back(make_pair(solution(sec-atoi(value.c_str())),sec));   
    }

    cout << ans.back().first << endl;
}
// int N;
// struct COMMAND
// {
// 	string cmd, param1, param2, after_cache, current_cache;
// 	COMMAND(string command, string parameter1, string parameter2, string current, string execute)
// 	{
// 		cmd = command;
// 		param1 = parameter1;
// 		param2 = parameter2;
// 		after_cache = execute;
// 		current_cache = current;
// 	}
// };
// int main()
// {
// 	vector<COMMAND> cmdline;
// 	string cmd, param1, param2, after_cache = "", current_cache = "";
// 	cin >> N;
// 	for(int i = 0; i < N; i++)
// 	{
// 		cin >> cmd >> param1 >> param2;
// 		if(cmd == "type"){
// 			after_cache += param1;
// 			cmdline.push_back(COMMAND(cmd, param1, param2, current_cache, after_cache));
// 			current_cache = after_cache;
// 		}
// 		else
// 		{
// 			bool isfind = false;
// 			int cur = 0;
// 			for(int i = 0; i < cmdline.size(); i++)
// 			{
// 				if(stoi(param2)-stoi(param1) == stoi(cmdline[i].param2))
// 				{
// 					isfind = true;
// 					current_cache = after_cache;
// 					after_cache = cmdline[i].current_cache;
// 					cmdline.push_back(COMMAND(cmd, param1, param2, current_cache, after_cache));
// 					break;
// 				}

// 			}
// 			while(!isfind && cur != cmdline.size())
// 			{
// 				if(stoi(param2) - stoi(param1) < stoi(cmdline[cur].param2))
// 				{
// 					isfind = true;
// 					current_cache = after_cache;
// 					after_cache = cmdline[cur].current_cache;
// 					cmdline.push_back(COMMAND(cmd, param1, param2, current_cache, after_cache));
// 				}
// 				cur++;
// 			}
// 		}	
// 	}
// 	cout << after_cache << endl;

// 	return 0;
// }
