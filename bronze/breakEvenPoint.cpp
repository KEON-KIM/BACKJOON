#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	long A, B, C;

	cin >> A >> B >> C;
	if (B > C || C == 0 || C == B)
		cout << -1 << endl;

	else
	{
		long long count = 0, cost = A + (B * count);
		if (A == 0)
			count = 1;
		else
			count = A/(C - B) +1;
		cout << count << endl;
	}
	return 0;
}