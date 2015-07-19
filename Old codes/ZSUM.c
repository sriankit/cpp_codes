#include<stdio.h>
typedef long long ll;
#define MOD 10000007
long long int power(int x, unsigned int y,ll mod)
{
    // printf("%d\n",y);
    long long int temp=0;
    if( y == 0)
        return 1;
    else if(y==1)
        return x;
    else if (y%2 == 0)
    {
        temp=power(x,y/2,mod)%mod;
        return (temp*temp)%mod;
    }
 
    else
    {
        temp=power(x,y/2,mod)%mod;
        return (x*((temp*temp)%mod))%mod;
    }
 
}
int main(){
    ll n,k;
    while(scanf("%lld%lld",&n,&k),n+k){
        ll s=0;
        s=(s+power(n,k,MOD))%MOD;
        s=(s+power(n,n,MOD))%MOD;
        s=(s+2*power(n-1,k,MOD))%MOD;
        s=(s+2*power(n-1,n-1,MOD))%MOD;
        printf("%lld\n",s);
    }
    return 0;
}
