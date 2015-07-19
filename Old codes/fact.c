#include<stdio.h>
typedef long long ll;
ll raise(ll a, ll n, ll MOD) {
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
long long factMOD(ll n, int MOD)
{
	long long res = 1;
	while (n > 1)
	{
		res = (res * raise(MOD - 1, n/MOD, MOD)) % MOD;
		int i,j;
		for (	i=2, j=n%MOD; i<=j; i++)
			res = (res * i) % MOD;
		n/=MOD;
	}
	return res;
}
int main(){
	ll n;
	int p;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%d",&n,&p);
		printf("%lld\n",factMOD(n,p));
	}
	return 0;
}
