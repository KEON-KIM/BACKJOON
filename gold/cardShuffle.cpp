#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>

#define MAX 49

using namespace std;
int N, result = 0;
vector<int> P(MAX), S(MAX), C(MAX);

bool solution()
{
	for(int i = 0; i < N; i++)
	{
		if(i%3 != P[C[i]]) return false;
	}
	// priority_queue<int> A[3], B[3];
	// for(int i = 0; i < N; i++)
	// {
	// 	A[i%3].push(C[i]);
	// 	B[P[i]].push(i);
	// }
	// for(int i = 0; i < 3; i++)
	// {
	// 	while(!A[i].empty() && !B[i].empty()){
	// 		// cout << "index : " << i << " A : " << A[i].top() <<  " B : " << B[i].top() << endl;
	// 		if(A[i].top() != B[i].top()) return false;
	// 		A[i].pop(); B[i].pop();
	// 	}
	// }
	return true;
}

vector<int> Shuffle()
{
	vector<int> temp(N);
	for(int i = 0; i < N; i++){
		temp[S[i]] = C[i];
	}
	// cout << "=======TEMP=========" << endl;
	// for(int i = 0; i < N; i++)
	// 	cout << temp[i] << " ";
	// cout << endl;
	return temp;
}
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> P[i];
	for(int i = 0; i < N; i++)
		cin >> S[i];

	for(int i = 0; i < N; i++)
		C[i] = i;
	
	while(result < 200000)
	{
		if(solution()){cout << result << endl; return 0;} 
		C = Shuffle();
		result++;
	}

	cout << -1 << endl;

	return 0;
}