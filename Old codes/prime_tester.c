#include<stdio.h>
typedef long long ll;
ll f(ll x,ll n){
    return (1024*x*x + 32767+21)%n+1;
}
ll powr(ll x,ll y,ll mod){
    if(y==1) return x;
    ll u=(x*x)%mod;
    u=powr(u,y/2,mod);
    if(y&1) u=(u*x)%mod;
    return u;
}

int isprime(ll p){
    if(p<2) return 0;
    if(p==2||p==3) return 1;
    if(p!=2 && p%2==0) return 0;
    ll s=p-1;
    while(s%2==0) s/=2;
    int cnt=0;
    ll a=20; 
    while(cnt++<10){
    a=f(f(a,s),s);
    ll temp=s;
    ll mod=powr(a,temp,p);
    while(temp!=p-1 && mod!=1 && mod!=p-1){
        mod=(mod*mod)%p;
        temp=temp*2;
    }
    if(mod!=p-1 && temp%2==0) return 0;
    }
    return 1;
}
int main(){
    FILE *fp=fopen("G:\\primes.txt","r");
    ll c=0,n;
    while(c<78000){
        fscanf(fp,"%lld",&n);
        if(isprime(n)==0) printf("FAILED :(");
        c++;
    }
    return 0;
}
    
