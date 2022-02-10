//#1990
#include<iostream>
#include<cstring>
#include<cmath>

#define MAX 1000000
#define PAL 1000
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M;

/*bool isPalin(int idx)
{
	string str = to_string(idx);
	int l = 0, r = str.length()-1;
	while(l < r)
	{
		if(str[l] != str[r])
			return false;
		l++;
		r--;
	}

	return true;
}
*/
bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2 ; i <= sqrt(num) ; i++) {
        if(num % i == 0) return false;
    }

    return true;
}

int main()
{
	int cnt = 0;
	fastio;
	cin >> N >> M;

	for(int i = 2; i <= 11; i++)
		if(N <= i && isPrime(i) && i <= M){
			cnt++;
			cout << i << endl;
		}

	for(int i = 1; i < 1000; i++)
	{
		string str = to_string(i);

		for(int j = 0; j <= 9; j++){
			char ch = j + '0';
			string tmp = str + ch;
			for(int k = str.length() - 1 ; k >= 0; k--)
				tmp += str[k];
			
			int result = stoi(tmp);
			if(result >= N && result <= M && isPrime(result))
				cout << result << endl;
		}
	}	

	//Prime
	/*for(int i = 2; i <= sqrt(M); i++)
		if(!prime[i])
			for(int j = 2; j * i <= M; j++)
				prime[i] = true;*/
	

	cout << -1;
	return 0;
}
