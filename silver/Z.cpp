#include<iostream>
#include<cmath>

using namespace std;
int N,r,c, result = 0;


void solution(int r, int c, int N)
{
	if(r >= 1 && c >= 1){
		bool cmd[2] = {(r <= pow(2,N) && r > pow(2, N-1)), (c <= pow(2,N) && c > pow(2, N-1)) };
		// int cmd[2] = {0 ,1}; 
		cout << cmd[0] << "|" << cmd[1] << " N : " << N << " r|c : " << r <<"|"<<c<< endl;

		if(cmd[0] || cmd[1])
		{
			if(cmd[0] && cmd[1]){ // 1, 1;
				result += pow(pow(2,N-1),2) * 3;
				r = r - pow(2, N-1);
				c = c - pow(2, N-1);
			}
			else if(cmd[0]){ // 1,0
				result += pow(pow(2,N-1),2) * 2;
				r = r - pow(2, N -1);
			}
			else{  // 0, 1
				result += pow(pow(2,N-1),2);
				c = c - pow(2, N-1);
			}	
			// cout <<  po,pow(2,N-1)) << endl;
			// r = r - pow(2,N-1);
			// c = c - pow(2, N-1); 
		}
		return solution(r, c, N-1);
	} 
}
int main()
{
	cin >> N >> r >> c;
	solution(r+1, c+1, N);

	cout << result << endl; 
	return 0;
}