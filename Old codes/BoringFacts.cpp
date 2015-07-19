typedef long long ll;

ll power(ll base, ll exponent, ll mod) {
    ll res = 1, k = base;
    if(k == 1) return 1 % mod;
    for (ll p = exponent; p > 0; p >>= 1) {
        if ((p & 1) == 1) res = (res * k) % mod;
        k = (k * k) % mod;
    }
    return res % mod;
}

main(){
	int q;
	scanf("%d"m&q);
	while(q--){
		int n,p;
		scanf("%d%d",&n,&p);
		if(n>=p) puts("0");
		else if(n==p-1) printf("%d\n",n);
		else{
			ll prod=1;
			ll i=p-1;
			for(;i>n;i--) prod=(prod*i)%p;
			printf("%d\n",(power(prod,p-2,p)*(p-1))%p);
		}
	}
	return 0;
}
