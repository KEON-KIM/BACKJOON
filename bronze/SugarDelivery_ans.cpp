#include <cstdio>

int main(){
	int t,k,p;
	scanf("%d",&t)
	k=t/5+(t%5)/3;
	p=t%5%3;
	k=!p ? k:p==1 ? k+1:p==2 ? k+2:0;
	if(p==1&&t/5<1||p==2&&t/5<2)
		k=-1;
	printf("%d",k);

	return 0;
}