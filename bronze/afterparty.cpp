#include<iostream>

using namespace std;

int L, P; 
int people[10];

int main()
{
	cin >> L >> P;
	for(int i = 0; i < 5; i++)
		cin >> people[i];

	for(int i = 0; i < 5; i++)
		cout << (people[i] - (L*P)) << " ";
	
	return 0;
}