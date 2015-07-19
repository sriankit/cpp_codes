#include<stdio.h>
#include<assert.h>
typedef long long ll;
const ll MOD=1000000007;
ll pre[100005];

ll pow(ll a, ll n) {
	ll p = 1;
	while (n > 0) {
		if (n % 2 == 1) {
			p = (long long) (p * a) % MOD;
		}
		a = (long long) (a * a) % MOD;
		n /= 2;
	}
	return p;
}

ll getI(ll a){
	return pow(a,MOD-2);
}
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	ll r= (a*b)%MOD;
	ll g=gcd(a,b);
	ll ONE=1;
	if(g==ONE) return r;
	return (r*getI(g))%MOD;
}
ll ls[]={1,1,2,6,12,60,60,420,840,2520,2520,27720,27720,
 360360,360360,360360,720720,12252240,12252240,
 232792560,232792560,232792560,232792560,
 5354228880LL,5354228880LL,26771144400LL,26771144400LL,
 80313433200LL,80313433200LL};
int main(){
	int t;
	scanf("%d",&t);
	pre[1]=1;
	for(ll i=2;i<28;i++){
		pre[i]=lcm(pre[i-1],i);		
		printf("%lld %lld %lld\n",pre[i],ls[i],ls[i]%MOD);
	}
	while(t--){
		int n;
		scanf("%d",&n);
		assert(n!=0);
		printf("%lld\n",pre[n+1]);
		printf("%lld\n",(pre[n+1]*getI(n+1))%MOD);	
	}
	return 0;
}

