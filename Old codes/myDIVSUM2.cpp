#include<cstdio>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
typedef long long ll;
using namespace std; 
map<ll,ll> ma;

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
ll powr(ll x,ll y,ll mod){
    if(y==1) return x;
    ll u=(mod>0)?((x*x)%mod):(x*x);
    u=powr(u,y/2,mod);
    if(y&1) u=(mod>0)?((u*x)%mod):(u*x);
    return u;
} 
ll f(ll x,ll y,ll mod){
    return (x*x+y)%(mod)+1;
}
int rabin_miller(ll p){
    if(p<2) return 0;
    if(p==2||p==3) return 1;
    if(p!=2 && p%2==0) return 0;
    ll s=p-1;
    while(s%2==0) s/=2;
    int cnt=0;
    ll a=-1;
    while(cnt++<10){
        a=f(a,21,s)+1;
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


ll gcd(ll a,ll b){
    if(b) return gcd(b,a%b);
    else return a;
}

ll rho(ll n){
    ll d,c,x,xx;
    srand ( time(NULL) );
    c=f(rand(),21,n);
    x=f(rand(),21,n);
    xx=x;
    if(n%2==0) return 2;
    do{
        x=f(x,c,n);
        xx=f(xx,c,n);
        xx=f(xx,c,n);
        d=gcd(abs(xx-x),n);
    }
    while(d==1);
    return d;
}
void factor(ll n){
    if(n==1) return;
    if(rabin_miller(n)){
        ma[n]+=1; 
        return;
    }
    ll d=rho(n);
    factor(d);
    factor(n/d);
}
ll compute(ll n){
    ma.clear();
    factor(n);
    
    map<ll,ll>::iterator it=ma.begin();
    ll ans=1;
    while(it!=ma.end()){
        ans*=((powr(it->first,it->second+1,0)-1)/(it->first-1));
        it++;
    }
    return ans;
}
int main(){
    ll t,n;
    //scanf("%lld",&t);
    t=scanInt();
    while(t--){
        //scanf("%lld",&n);
        n=scanInt();
        printf("%lld\n",compute(n)-n*(n>1));
        
    }
    return 0;
}
