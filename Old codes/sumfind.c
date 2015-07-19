#include<stdio.h>
#include<assert.h>
typedef long long ll;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,m;
		scanf("%lld%lld",&m,&n);
		ll mod=n%m;
		ll s=((m-1)*m*n)/2;
		s-=mod*((m-1)*m)/2;
		printf("%lld\n",2*(s/m));
		printf("%lld\n",s);
		assert(s%m==0); 
	}
	return 0;
}
