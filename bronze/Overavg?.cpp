//#4434

#include<iostream>
#include<stdio.h>
#define MAX 1001
#define endl '\n'

using namespace std;

int N;
double students[MAX];

int main()
{
	float M, points, sum, avg;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> M;
		sum = 0;
		for(int j = 0; j < M; j++)
		{
			cin >> points;
			students[j] = points;
			sum += points;
		}
		avg = sum/ M;
		sum = 0;
		for(int j = 0; j < M; j++)
			if(avg < students[j])
				sum++;
		
		
		printf("%.3f%%\n", sum/ M * 100);
	}

	return 0;
}