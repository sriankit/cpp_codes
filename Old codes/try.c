typedef long long ll;
main(){
  ll i;
  int t;
  for(scanf("%d",&t);t;t--){
  	ll n,k;
  	scanf("%d%d",&n,&k);
	ll r=1,d=k; 
	while(n>k){		
		r *= n--;
 
		/* divide (n - k)! as soon as we can to delay overflows */
		while (d > 1 && !(r % d)) r /= d--;
	}
	printf("%lld\n",r);
  }
}
