#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 1000001
string repeator(int res, int n)
{
	string tmp = "";
	bool visited[MAX] = {false, };

	cout << res << endl;
	visited[res%n] = true;
	while(true)
	{
		
		if( !res ) break; 
		else if(res >= n)
		{
			visited[res] = true;
			tmp += to_string((res/n));
			res %= n;

			if( !res || visited[res]) {
				return tmp;
			}
		}

		else
			tmp += '0';
		
		res *= 10;
	}	

	return "0";
}
vector<string> solution(int n)
{
	vector<string> answer;
	answer.resize(2);

	int res = 10;
	bool visited[MAX] = {false, };
	string tmp = "0.";
	string repeat = "";

	visited[1] = true;
	while(true)
	{
		if(!res || visited[res]) 
		{
			answer[1] = repeator(res, n);
			break;
		}
		else if(res >= n)
		{
			visited[res] = true;
			tmp += to_string((res/n));
			res %= n;
			if(!res || visited[res]) 
			{
				answer[1] = repeator(res, n);
				break;
			}
		}
		else
			tmp += '0';
		
		res *= 10;
		if(!res || visited[res]) 
		{
			answer[1] = repeator(res, n);
			break;
		}
	}	
	answer[0] = tmp;

	return answer;
}

int main()
{
	int n = 10;
	vector<string> answer = solution(n);
  
    cout.precision(25); 
	cout << answer[0] << " " << answer[1] << endl;
	cout << "-1 : " << 1/(float)n << endl;
	return 0;
}
/*#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 1000001
string repeator(int res, int n)
{
	string tmp = "";
	bool visited[MAX] = {false, };
	while(true)
	{
		res *= 10;
		if( !res || visited[res]) 
				return tmp;
		if(res >= n)
		{
			visited[res] = true;
			tmp += to_string((res/n));
			res %= n;
			if( !res || visited[res]) {
				return tmp;
			}
		}

		else
		{
			tmp += '0';
			if( !res || visited[res]) {
				return tmp;
			}
		}
	}	

	return "0";
}
vector<string> solution(int n)
{
	vector<string> answer;
	answer.resize(2);

	int res = 10;
	bool visited[MAX] = {false, };
	string tmp = "0.";
	string repeat = "";

	visited[1] = true;
	while(true)
	{
		if(res >= n)
		{
			visited[res] = true;
			tmp += to_string((res/n));
			res %= n;
			if(!res || visited[res]) 
			{
				answer[1] = repeator(res, n);
				break;
			}
		}
		else{
			tmp += '0';
			if(!res || visited[res]) 
			{
				answer[1] = repeator(res, n);
				break;
			}
		}
		res *= 10;
		if(!res || visited[res]) 
		{
			answer[1] = repeator(res, n);
			break;
		}
	}	
	answer[0] = tmp;

	return answer;
}

int main()
{
	int n = 123;
	vector<string> answer = solution(n);
  
    cout.precision(25); 
	cout << answer[0] << " " << answer[1] << endl;
	cout << "-1 : " << 1/(float)n << endl;
	return 0;
}*/