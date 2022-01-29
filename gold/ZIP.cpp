//#1662
//@Reference jaimemin <https://jaimemin.tistory.com/1264>
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
const int MAX = 50;

string input;
int visited[MAX];
int solution(int start, int end)
{
	int result = 0;

	for (int i = start; i < end; i++)
	{
		if (input[i] == '(')
		{
			int K = input[i - 1] - '0';
			
			result += K * solution(i + 1, visited[i]) - 1;
			i = visited[i];

			continue;
		}

		result++;
	}

	return result;
}

int main()
{
	fastio;
	cin >> input;
	
	stack<int> paren;	
	for (int i = 0; i < input.length(); i++) 
	{
		if (input[i] == '(')
			paren.push(i);
		
		else if (input[i] == ')')
		{
			visited[paren.top()] = i;
			paren.pop();
		}
	}
	
	cout << solution(0, input.length()) << "\n";
	
	return 0;
}
// vector<string> board;
/*int result = 0;
int main()
{
	stack<string> funcKey; 
	stack<int> valueKey;
	stack<char> paren;
	
	string input;
	cin >> input;

	string tmp = "";
	for(int i = 0; i < input.length(); i++)
	{
		if(input[i] == '(' || input[i] == ')')
		{
			if(input[i] == '(')
			{
				funcKey.push(tmp);
				paren.push('(');
			}

			else
			{
				paren.pop();
				if(tmp != "")
					valueKey.push((tmp.length()));
				if(!paren.empty())
				{
					string str = funcKey.top();
					int key = str[str.length()-1] - '0';
					
					int value = valueKey.top();
					valueKey.pop();

					str.erase(str.end()-1);
					valueKey.push(str.length()+(value*key));
					funcKey.pop();
				}
				else
				{
					while(!valueKey.empty())
					{
						result += valueKey.top();
						cout << valueKey.top() << endl;
						valueKey.pop();
					}
					string str = funcKey.top();
					int key = str[str.length()-1] - '0';
					str.erase(str.end()-1);
					result *= key;
					result += str.length();
					funcKey.pop();
				}
			}
			tmp = "";
		}
		else
			tmp += input[i];
		
	}

	
	result += tmp.length();
	cout << result << endl;
	return 0;
}*/
/*string solution(string str)
{

}
int main()
{

	string input;
	cin >> input;
	stack<string> funcKey; 
	stack<int> valueKey;

	string tmp = "";
	for(int i = 0; i < input.length(); i++)
	{
		if(input[i] == '(' || input[i] == ')')
		{
			if(input[i] == '(')
			{
				funcKey.push(tmp);
				paren.push('(');
			}

			else
			{

			}
			tmp = "";
		}
		else
			tmp += input[i];
	}
	return 0;
}*/

