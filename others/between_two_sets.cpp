#include <iostream>
#include <vector>

#define MAX 101
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int gcd(int a, int b) 
{ 
    if (b > a) //swap
    {
        int temp = b;
        b = a;
        a = temp;
    }
    while (b) 
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long lcm(long long a, long long b) 
{ 
    return a * b / gcd(a, b);
}


int solution(vector<int> a, vector<int> b) {
    long long lcm_a = a[0], gcd_b = b[0], cnt = 0;
    for (int i=0;i<a.size(); i++) {cout << lcm_a << endl; lcm_a = lcm(a[i], lcm_a); }
    for (int i=0;i<b.size(); i++) gcd_b = gcd(b[i], gcd_b); 

    if ((gcd_b == 0) || (lcm_a >= MAX) || (lcm_a > gcd_b)) return 0;
    for (int i=lcm_a;i<=gcd_b;i++) 
        if ((gcd_b%i == 0) && (i%lcm_a == 0)) 
        	cnt++;
    
    return cnt;
}

int main()
{
	int N, M, input;
	vector<int> a, b;

	cin >> N >> M;
	FOR(i, N)
	{
		cin >> input;
		a.push_back(input);
	}

	FOR(i, M)
	{
		cin >> input;
		b.push_back(input);
	}
	cout << solution(a, b);

	return 0;
}