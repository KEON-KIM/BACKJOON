#include <iostream>
#include <vector>
#include <cmath>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define DIGIT 10
using namespace std;
typedef long long ll;

int increase[DIGIT][DIGIT], cnt = 0;
vector<ll> answers;
int N;
void Init()
{
	FOR(i, DIGIT){
		increase[0][i] = 1;
		increase[i][0] = 1;
		answers.push_back(i);
		cnt++;
	}
}
void update_increase(int idx)
{
	for(int i = 1; i < DIGIT - idx; i++)
		increase[idx][i] += increase[idx][i-1] + increase[idx-1][i];	
}

void Solution()
{
	int sum = 0;
	for(int i = 1; i < DIGIT; i++)
	{
		int tmp = sum;

		sum = 0; 
		update_increase(i);
		for(int j = i, idx = 0; j < DIGIT && idx < DIGIT - i; j++, idx++)
		{
			sum += increase[i][idx];
			for(int k = 0; k < increase[i][idx]; k++)
			{
				answers.push_back( (j * pow(DIGIT, i)) + answers[tmp+k]);
				cnt++;
			}
		}
		sum = cnt - sum;
	}
}

int main()
{
	Init();
	Solution();

	cin >> N;

	if(N > answers.size()) cout << -1 << endl;
	else cout << answers[N-1] << endl; 
	
	return 0;
}

/*#include <iostream>
#include <vector>
#include <cmath>
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long ll;
int increase[10][10], cnt = 0;
vector<ll> answers;
int N;
void INIT()
{
	FOR(i, 10){
		increase[0][i] = 1;
		increase[i][0] = 1;
		answers.push_back(i);
		cnt++;
	}
}
void update_increase(int idx)
{
	for(int i = 1; i < 10 - idx; i++)
	// for(int i = idx; i < 10; i++)
	// for(int i = 1; i < 10 - idx; i++)
		increase[idx][i] += increase[idx][i-1] + increase[idx-1][i];	
}
int main()
{
	INIT();
	int sum = 0;
	for(int i = 1; i < 10; i++)
	{
		int tmp = sum;
		sum = 0;
		// if(i < 1) continue; 
		update_increase(i);
		cout << "====================TMP================== : " << tmp << endl;
		for(int j = i, idx = 0; j < 10 && idx < 10 - i; j++, idx++)
		{
			// cout << increase[i][j] <<" ";
			sum += increase[i][idx];
			for(int k = 0; k < increase[i][idx]; k++)
			{
				cout << (j * pow(10, i)) + answers[tmp+k] << "/"<< cnt+1 << " ";
				answers.push_back( (j * pow(10, i)) + answers[tmp+k]);
				cnt++;
			}
		}
		sum = cnt - sum;
		cout << endl;
		// cout << endl;
	}

	cin >> N;
	// cout << "====================PRINT====================" << endl;
	// for(int i : answers)
	// 	cout << i << " ";
	// cout << endl;

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++)
			cout << increase[i][j] << " ";
		cout << endl;
	}
	if(N > answers.size()) cout << -1 << endl;
	else cout << answers[N-1] << endl; 
	return 0;
}*/