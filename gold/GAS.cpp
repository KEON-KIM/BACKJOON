#include<iostream>

#define MAX 100000

using namespace std;


int N, l, r;
// long long money = 0;
string money;
int val[MAX], road[MAX];


void BIG_CAL(int money, int b)
{
	char carry;
	string tmp = to_string(b);
	string pad = string(money.size() - tmp.size(), '0') + tmp;

	for(int i = pad.size()-1; i >= 0; i--)
	{
		if(carry > '0')
		{
			int temp = (money[i] - '0') + (pad[i] - '0') + (carry - '0');
			carry = temp/10 + '0';
			money[i] = temp%10 + '0';
		}
		else
		{
			int temp = (money[i] - '0') + (pad[i] - '0');
			carry = temp/10 + '0';
			money[i] = temp%10 + '0';
		}
		
	}
}

void solution()
{
	int distance=0, value;
	money ="429395";
	BIG_CAL(45);
	for(int i = 0; i < N -1 ; i++)
	{
		if(i)
		{
			if(value > val[i])
			{
				money += distance * value;
				value = val[i];
				distance = 0;
			}
		}
		else
			value = val[i];
		distance += road[i];
	}
	money += distance * value;
}
// void input()
// {
// 	cin >> N;

// 	for(int i = 0; i < N-1; i++)
// 		cin >> road[i];
	
	
// 	for(int i = 0; i < N; i++)
// 		cin >> val[i];
	
// }
int main()
{
	// input();
	solution();

	cout << money << endl;
	return 0;
}