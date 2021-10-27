//#1914
//@Reference gkalstn000 <https://gkalstn000.github.io/2021/01/29/%ED%95%98%EB%85%B8%EC%9D%B4%EC%9D%98-%ED%83%91/>

#include<iostream>
#include<cmath>
#include<string>

#define endl '\n'

using namespace std;

void hanoi(int n, int from, int pass, int to)
{
	if(n == 1)
		cout << from <<" "<< to << endl;
	
	else
	{
		hanoi(n-1, from, to, pass);
		cout << from << " " << to << endl;
		hanoi(n-1, pass, from, to);
	}
}
int main()
{
	int N;
	cin >> N;
	string answer = to_string(pow(2,N));
	answer = answer.substr(0,answer.find('.'));
	answer[answer.size()-1] -= 1;

	if(N > 20)
		cout << answer << endl;
	
	else{		
		cout << answer << endl;
		hanoi(N, 1,2,3);
	}

	return 0;
}