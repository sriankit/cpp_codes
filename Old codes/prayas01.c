#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		if(n<=2) puts("-1");
		else if(n%2==0) puts("-1");
		else {
			int a = n/2;
			long long ans = (a-1)*(a)/2;
			ans += a*(a+1)/2;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
