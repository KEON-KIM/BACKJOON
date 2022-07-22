#include<iostream>

using namespace std; 

int xs, ys;

int GCD(int a, int b)
{
	if(!(a%b)) return b;
	else return GCD(b, a%b);
}

int main()
{
	cin >> xs >> ys;
	int xe,ye, dx, dy, gcd;

	cin >> xe >> ye >> dx >> dy;
	if(dx > dy)
		gcd = GCD(dx, dy);
	else 
		gcd = GCD(dy, dx);
	dx = dx/gcd;
	dy = dy/gcd;

	int x = xs - dy;
	int y = ys + dx;

	cout << x << " " << y << endl;
	return 0;
}