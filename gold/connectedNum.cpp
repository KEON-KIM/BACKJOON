#include<iostream>
#include<string>

#define MAX 100001
using namespace std;

string N;
int K, visited[MAX];
typedef long long ll;
int main()
{
	string rest = "";
	cin >> N >> K;

	int cnt = 1, tmp = 0;
	rest += N;
	// if(!(stoll(rest)%K))
	// {
	// 	cout << cnt << endl;
	// 	return 0;
	// }

	while(!visited[tmp])
	{
		rest = to_string(tmp) + N;
		visited[tmp] = true;
		tmp = (stoll(rest) % K); 

		if(!tmp){
			cout << cnt << endl;
			return 0;
		}
		cnt++;
	}

	cout << -1 << endl;
	return 0;
}