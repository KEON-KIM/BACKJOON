#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int N,y = 0, m = 0;
	double sec;
    
	cin >> N;
	for(int i = 0; i < N ; i++)
	{
		cin >> sec;
		y += floor(sec / 30.0) + 1;
		m += floor(sec / 60.0) + 1;
	}
	y = y * 10;
	m = m * 15;
	if(y > m ) cout << "M " << m << endl; 
	else if(m > y) cout << "Y " << y << endl;
	else cout << "Y M " << y << endl;

	return 0;
}
