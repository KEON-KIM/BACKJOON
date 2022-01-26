#include<iostream>
#include<bitset>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
int N;
//TEST
// void OTP()
// {
// 	for(int i = 97; i <= 122; i++){ 	// a~z
// 		FOR(j, 10){
// 			long tmp = (bitset<8>(i^(j+48))).to_ulong();
// 			cout <<  tmp << " ";
// 		}
// 		cout << endl;
// 	}
// }

int main()
{
	string result = "";
	string hex;

	cin >> N;
	FOR(i, N)
	{
		cin >> hex;
		int dec = (int)stol(hex, NULL, 16);

		char tmp = (64<=dec) && (dec <=95) ? '-' : '.';
		result += tmp;
	}

	cout << result << endl;

	return 0;
}