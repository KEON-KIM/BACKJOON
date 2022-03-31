// 1423
#include<iostream>
#include<queue>
#include<algorithm>

#define CMAX 51

using namespace std;

int L, D, result = 0;
int char_info[CMAX], str_info[CMAX];

void print()
{
	for(int i = 1; i <= L; i++)
		cout << char_info[i] <<" ";
	cout << endl;
}

struct char_upbringing
{
	int str, x, y;
	char_upbringing(int strength, int a, int b)
	{
		str = strength;
		x = a;
		y = b;
	}

	bool operator>=(char_upbringing &ref1, char_upbringing &ref2)
	{
		return ref1>ref2;	
	}
	bool operator<(char_upbringing &ref1, char_upbringing &ref2)
	{
		return ref1<ref2;	
	}
};

int main()
{
	priority_queue<char_upbringing> pq;
	cin >> L;
	for(int i = 1; i <= L; i++)
		cin >> char_info[i];

	for(int i = 1; i <= L; i++)
		cin >> str_info[i];
	
	for(int i = 1; i <= L; i++)
		for(int j = i+1; j <= L; j++)
			pq.push(char_upbringing(str_info[j] - str_info[i], i, j));

	cin >> D;
	cout << "SIZE : " << pq.size() << endl;
	while(!pq.empty() && D > 0)
	{
		int a = pq.top().x;
		int b = pq.top().y;
		for(int i = a; i < b; i++)
		{
			if(char_info[i])
			{
				for(int j = 0; j < b - i; j++)
				{
					if(D - (b - i) >= 0){
						D -= b - i;
						char_info[i]--;
						char_info[b]++;
					}
					else break;
				}
			}
		}
		pq.pop();
		// if(pq.top().first < 0) {
		// 	pq.pop();
		// 	continue;
		// }
		// int k = pq.top().second;
		// cout << "K : " << k << endl;
		// for(int i = k-1; i > 0; i--)
		// {
		// 	print();
		// 	int size = char_info[i];
		// 	for(int j = 0; j < size; j++){
		// 		if(D - (k - i) >= 0){
		// 			D -= k - i;
		// 			char_info[i]--;
		// 			char_info[k]++;
		// 			cout << D << endl;
		// 		}
		// 		else break;
		// 	}
		// }
		// pq.pop();
	}
	for(int i = 1; i <= L; i++)
		result += (char_info[i] * str_info[i]);

	cout << result << endl;
	return 0;
}