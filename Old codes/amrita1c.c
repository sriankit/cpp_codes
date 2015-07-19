#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,tm;
		scanf("%d%d%d",&n,&m,&tm);
		int tym=0;
		while(n>0){
			tym+=tm;
			n-=m;
			if(n>0)tym+=tm;	
		}
		printf("%d\n",tym+tm);
	}
	return 0;
}
