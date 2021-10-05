#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int N;
int** init(int N)
{
	int** ary = new int*[N];
	for(int i = 0; i < N; i++)
		ary[i] = new int[N];

	return ary;
}

// void fill_zero(int** ary, int N)
// {
// 	for(int i = 0; i< N; i++)
// 		for(int j = 0; j < N; j++)
// 			ary[i][j] = 0;
// }
void print(int** ary)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			cout << ary[i][j];
		cout << endl;
	}
}

bool isOne(int** ary,int n)
{
	// cout << "WHAT?" << endl;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n ; j++)
			if(ary[i][j] != ary[0][0]) return false;

	return true;
}

void solution(int** ary, int n)
{
	if(!isOne(ary,n)){
		if(n == 2)
		{cout << "(";
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					cout << ary[i][j];
		cout << ")";return;}
		else
		{cout << "(";
			if(!isOne(ary,n)){
				int** tmp = init(n/2);
				for(int i = 0; i < n/2; i++)
					for(int j = 0; j < n/2; j++)
						tmp[i][j] = ary[i][j];
				solution(tmp, n/2);

				for(int i = 0; i < n/2; i++)
					for(int j = n/2; j < n; j++)
						tmp[i][j-n/2] = ary[i][j];
				solution(tmp, n/2);

				for(int i = n/2; i < n; i++)
					for(int j = 0; j < n/2; j++)
						tmp[i-n/2][j] = ary[i][j];
				solution(tmp, n/2);

				for(int i = n/2; i < n; i++)
					for(int j = n/2; j < n; j++)
						tmp[i-n/2][j-n/2] = ary[i][j];
				solution(tmp, n/2);
			}
		cout << ")";}
	}
	else
	{
		if(ary[0][0]) cout << "1";
		else cout << "0";
		return;
	}
}

int main()
{
	cin >> N;
	string str;
	int** mat  = init(N);
	for(int i = 0; i < N; ++i)
	{
		cin >> str;
		for(int j = 0; j < str.size(); j++)
			mat[i][j] = str[j] - '0';
	}

	if(isOne(mat, N)){
		if(mat[0][0]) cout << "1";
		else cout << "0";
	}
	else
		solution(mat, N);
	
	
	// for(int num = 1; N*2 >= (num = num << 1);)
	// 	cout << num << endl;

	// cout <<  << endl;
	// for(int i = 0; i < N/2; i++)


	return 0;
}



// 6
// 0 1 1 0 0 0
// 0 1 1 0 1 1
// 0 0 0 0 1 1
// 0 0 0 0 1 1
// 1 1 0 0 1 0
// 1 1 1 0 0 0 