//#2824
//@Reference degurii <https://degurii.tistory.com/196>
#include <bits/stdc++.h>
 
#define ft first
#define sd second
using namespace std;

typedef long long ll;

const int MOD = 1'000'000'000;
bool c = false;
int n, m;
map<ll, int> a, b;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        for (int j = 2; j * j <= x; j++) {
            while (x % j == 0) {
                a[j]++;
                x /= j;
            }
        }
        if (x > 1) a[x]++;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        for (int j = 2; j * j <= x; j++) {
            while (x % j == 0) {
                b[j]++;
                x /= j;
            }
        }
        if (x > 1) b[x]++;
    }

    auto pa = a.begin(), pb = b.begin();
    ll ans = 1;

    while (pa != a.end() && pb != b.end()) {
        if (pa->ft > pb->ft) {
            pb++;
        }
        else if (pa->ft < pb->ft) {
            pa++;
        }
        else {
            int cnt = min(pa->sd, pb->sd);
            while (cnt--) {
                ans *= pa->ft;
                if (ans >= MOD) {
                    c = true;
                    ans %= MOD;
                }
            }
            pa++;
            pb++;
        }
    }

    if (c) {
        cout.width(9);
        cout.fill('0');
    }
    cout << ans;
    return 0;
}

/*#include<iostream>
#include<string>
#include<vector>
// #include<set>

using namespace std;

#define MAX 1001
#define INF 1000000000
#define FOR(i, n) for(int i = 0; i < n ;i++)
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)

typedef long long ll;

int N, M;
// ll result = 1;
// set<ll> visited_A;
// set<ll> visited_B;
/*void divisor(ll input, bool flag)
{	
	for(int i = 1; i * i <= input; i++)
		if(!(input%i)){
			ll mok = input/i;
			if(mok == i)
			{
				set<ll>::iterator it = visited.find(i);
				if(it != visited.end()) {
					result *= i;
					// result = result%INF;
				}
				else
					visited.insert(i);
			}
			else
			{	
				set<ll>::iterator it = visited.find(i);
				if(it != visited.end()){
					result *= i;
					// result = result%INF;
				}
				else
					visited.insert(i);

				it = visited.find(mok);
				if(it != visited.end()){
					result *= mok;		
					// result = result%INF;
				}
				else	
					visited.insert(mok);
			}
			
		}
}

void divisor(ll input)
{
	for(int i = 1; i * i <= input; i++)
		if(!(input%i)){
			ll mok = input/i;
			visited.insert(i);
			visited.insert(mok);
		}
}
void divisor(ll input, bool flag)
{
	if(flag)
	{
		for(int i = 1; i * i <= input; i++)
			if(!(input%i)){
				ll mok = input/i;
				visited_A.insert(i);
				visited_A.insert(mok);
			}
	}
	else
	{
		for(int i = 1; i * i <= input; i++)
			if(!(input%i)){
				ll mok = input/i;
				visited_B.insert(i);
				visited_B.insert(mok);
			}
	}
}
void print()
{
	cout << "=====A=====" << endl;
	for(set<ll>::iterator it = visited_A.begin(); it != visited_A.end(); ++it)
		cout << *it << endl;
	cout << endl;

	cout << "=====B=====" << endl;
	for(set<ll>::iterator it = visited_B.begin(); it != visited_B.end(); ++it)
		cout << *it << endl;
	cout << endl;
}
int main()
{
	fastio;
	ll input;

	cin >> N;
	FOR(i, N)
	{
		cin >> input;
		divisor(input, true);
	}
	cin >> M;
	FOR(i, M)
	{
		cin >> input;
		divisor(input, false);
	}

	print();
	ll a = 8863;
	ll b = 29881;
	ll c = 9409;
	ll d = 7954;

	ll ans = 1;

	ans *= a;
	cout << "ANSWER : "<<ans<< endl;
	ans *= b;
	cout << "ANSWER : "<<ans<< endl;
	ans *= c;
	ans = ans%INF;
	cout << "ANSWER : "<<ans<< endl;
	ans *= d;
	ans = ans%INF;
	cout << "ANSWER : "<<ans<< endl;

	return 0;
}
ll GCD(ll a, ll b)
{
	if(!b) return a;
	else return GCD(b, a%b);
}

int main()
{
    fastio;
    vector<ll> vn, vm;
    ll k, result = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> k;
		vn.push_back(k);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> k;
		vm.push_back(k);
	}

	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vm[j] == 1)continue;
			ll gcd = GCD(vn[i], vm[j]);
			vn[i] /= gcd;
			vm[j] /= gcd;
			result *= gcd;
			if (result >= INF) {
				result %= INF;
				flag = true;
			}
		}
	}
	if (flag == false)
		cout << result << endl;
	else {
		int id = 0;
		int temp = result;
		for (int i = 0; i < 9; i++) {
			if (temp != 0) {
				id++;
				temp /= 10;
			}
			else
				break;
		}

		for (int i = 0; i < 9 - id; i++)
			cout << '0';

		cout << result;
	}

    
	ll A = 1, B = 1, input;
	cin >> N;
	FOR(i, N){
		cin >> input;
		A *= input;
	}

	cin >> M;
	FOR(i, M){
		cin >> input;
		B *= input;
	}
	cout << result << endl;
	if (flag == false)
		cout << result;

	else{
		string str = to_string(result);
	    for(int i = 9; i > 0; i--)
		    cout << str[str.length()-i];
	}

	return 0;
}
*/
