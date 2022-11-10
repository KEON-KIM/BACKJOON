#include <algorithm>
#include <iostream>
#include <complex>
#include <string>
#include <vector>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

typedef complex<double> cpx;
const double PI = acos(-1);

void FFT(vector<cpx> &f, cpx w)
{
	int n = f.size();
	if(n == 1) return; // 원소가 하나 뿐이라면
	vector<cpx> even(n/2), odd(n/2);
	FOR(i, n) ( i%2 ? odd : even)[i/2] = f[i];

	FFT(even, w * w);
	FFT(odd, w * w);

	cpx wp(1);
	FOR(i, n/2)
	{
		f[i] = even[i] + wp * odd[i];
		f[i+n/2] = even[i] - wp * odd[i];
		wp *= w;
	}
}
vector<cpx> multiply(vector<cpx> a, vector<cpx> b)
{
	int n = 1;
	while(n < a.size() + 1 || n < b.size() + 1) n *= 2;
	n *= 2;

	a.resize(n);
	b.resize(n);
	vector<cpx> c(n);
	cpx w(cos(2*PI/n), sin(2*PI/n));
	FFT(a, w);
	FFT(b, w);

	FOR(i, n) c[i] = a[i] * b[i];

	FFT(c, cpx(1)/w);
	FOR(i, n)
	{
		c[i] /= cpx(n);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}

	return c;
}
int main()
{
	fastio;
	vector<cpx> x, y, z;
	string input1, input2;
	cin >> input1 >> input2;

	FOR(i, input1.length())
		x.push_back(cpx(input1[i] - '0'));

	FOR(i, input2.length())
		y.push_back(cpx(input2[i] - '0'));
	
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	z = multiply(x, y);

	int len = z.size();
	int carry = 0;
	vector<int> result;

	FOR(i, len)
	{
		int n = (int)round(z[i].real()) + carry;
		carry = n/ 10;
		result.push_back(n%10);
	}
	while(carry > 0)
	{
		result.push_back(carry%10);
		carry /= 10;
	}

	int i = result.size()-1;
	for(; i >= 0; i--)
		if(result[i] != 0) break;
	if(i < 0) cout << '0';
	else for(; i >= 0; i--) cout << result[i];

	return 0;
}