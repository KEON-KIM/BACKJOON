// #1918
// @Reference donggoolosori <https://donggoolosori.github.io/2020/10/19/boj-1918/>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string s;
    stack<char> op;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            cout << s[i];
        }
        else
        {
            if (s[i] == '(')
                op.push(s[i]);
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!op.empty() && (op.top() == '*' || op.top() == '/'))
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
        }
    }
    while (!op.empty())
    {
        cout << op.top();
        op.pop();
    }

    return 0;
}

/*#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

string input;
int findForm(int idx, string str)
{
	stack<char> St;
	St.push(str[idx]);
	while(!St.empty())
	{
		idx++;
		if(str[idx] == '(')
			St.push(str[idx]);
		if(str[idx] == ')')
			St.pop();
	}
	return idx;
}

void makeString(string &ans, string tmp, queue<char> &pm, queue<char> &md)
{
	ans += tmp;
	while(!md.empty()) 
	{
		ans += md.front();
		md.pop();
	}
	while(!pm.empty()) 
	{
		ans += pm.front();
		pm.pop();
	}
}

string Solution(string str)
{
	string ans = "";
	string tmp = "";
	queue<char> pm;
	queue<char> md;
	FOR(i, str.length())
	{
		if(str[i] == '(')
		{
			int endP = findForm(i, str);
			for(int k = i + 1; k < endP; k++)
			{
				tmp += str[k];
			}
			ans += Solution(tmp);
			i = endP+1;
			tmp = "";
		}
		if(str[i] == '+' || str[i] == '-')
		{
			if(!pm.empty() || !md.empty())
				makeString(ans, tmp, pm, md);
			else
				ans += tmp;
			
			tmp = "";
			pm.push(str[i]);
		}
		else if(str[i] == '*' || str[i] == '/')
		{
			if(!md.empty())
			{
				ans += tmp;
				while(!md.empty()) 
				{
					ans += md.front();
					md.pop();
				}
			}
			else
				ans += tmp;
			tmp = "";
			md.push(str[i]);
		}

		else
			tmp += str[i];
	}
	makeString(ans, tmp, pm, md);
	return ans;
}	

int main()
{
	cin >> input;
	cout << Solution(input);
	return 0;
}*/