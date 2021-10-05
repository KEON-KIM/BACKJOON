#include<stdio.h>
#include<iostream>

int T,M,N,K;
int a[52][52];

void f(int x,int y){
	if(!a[x][y])return;
	a[x][y]=0;
	f(x+1,y);f(x-1,y);f(x,y+1);f(x,y-1); // checking all direct
}

int main(){
	cin >> T;
	while(T--){
		cin >>M >> N >>K;
		for(int i=0; i<K; ++i){
			int X,Y;
			cin >> X >> Y
			a[X+1][Y+1] = 1;
		} // make board

		int c=0;

		for(int i=1;i <= M; ++i){
			for(int j=1;j <= N;++j){
				if(a[i][j]){
					f(i,j);
					++c;
				}
			}
		}
		cout << c << endl;
	}
}