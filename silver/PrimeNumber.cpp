// #1978
#include<iostream>

using namespace std;

bool prime(int cmp)
{
	if(cmp == 1) return false;
	else if(cmp == 2) return true;
	else{
		for(int i = 2; i < cmp; i++)
			if(!(cmp%i)) return false; 
		return true;
	}
}

int main()
{
	int N,cmp, answer = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> cmp;
		if(prime(cmp)) answer ++;
	}

	cout << answer << endl;
	return 0;
}
