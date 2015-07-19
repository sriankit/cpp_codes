#include<stdio.h>
typedef long long ll;
const ll MOD=1000003;
ll ans[1000001];
ll mod(ll x){
    if(x<0) return mod(x+MOD);
    else return x%MOD;
}
inline int scanInt()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
};
ll getInverse(ll i)
{
	if(i == 1)
		return 1;
	ll ans = 1;
	ll pow = MOD-2;
	while(pow)
	{
		if(pow %2 == 1)
			ans *= i;
	
		i = (i*i) % MOD;
		pow /= 2;
		ans = ans % MOD;
	}
 
	return ans;
}
void init(){
    int i;
    /*for(i=1;i<=1000000;i++)
        inv[i]=getInverse(i);*/
    ans[0]=1;
    ans[1]=3;
    for(i=2;i<=1000000;i++)
        ans[i]=mod(mod(((6*i-3)*ans[i-1])-mod((i-1)*ans[i-2]))*power(i,MOD-2,MOD));
}
int main(){
    init();
    int t,n;
    scanf("%d",&t);
    //t=100000;
    //n=1000000;
    while(t--){
        //scanf("%d",&n);
        n=scanInt();
	printf("%lld\n",ans[n-1]);
    	//ans[n-1];
	//--n;
    }
    //puts("done");
    return 0;
}
