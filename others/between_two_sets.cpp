#include <iostream>
#include <vector>

#define MAX 101
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int gcd(int a, int b) { 
    if (b > a) {
        int temp = b;
        b = a;
        a = temp;
    }
    while (b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) { 
    return a * b / gcd(a, b);
}

int getTotalX(int a_count, int* a, int b_count, int* b) {
    int lcm_a = *a, gcd_b = *b, count = 0;

    for (int i=0;i<a_count && lcm_a<=100;i++) lcm_a = lcm(*(a+i), lcm_a); 
    for (int i=0;i<b_count;i++) gcd_b = gcd(*(b+i), gcd_b); 

    if ((gcd_b == 0) || (lcm_a > 100) || (lcm_a > gcd_b)) return 0;

    for (int i=lcm_a;i<=gcd_b;i++) 
        if ((gcd_b%i == 0) && (i%lcm_a == 0)) count++;
    
    return count;
}

int main()
{
	int N, M, a[MAX], b[MAX];
	cin >> N >> M;
	FOR(i, N)
		cin >> a[i];
	FOR(i, M)
		cin >> b[i];
	cout << solution(N, M, a, b);

	return 0;
}