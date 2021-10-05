#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int N,Num,count = 1, answer;
	cin >> N;
	answer = N;

	int first = N/10, second = N%10;
	Num = first + second;
	if (Num >= 10)
		N = (second*10) + Num%10;
	else
		N = second*10 + Num;

	while(answer != N)
	{
		first = N/10;
		second = N%10;
		Num = first + second;
		if (Num >= 10)
			N = (second*10) + Num % 10;
		else
			N = second	*10 + Num;
		count++;
	}
	cout << count << endl;
	return 0;
}