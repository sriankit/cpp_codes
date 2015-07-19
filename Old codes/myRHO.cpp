#include<stdio.h>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;

ll ab(ll n){
    if(n<0) return -n;
    else return n;
}

ll f(ll x,ll n){
    return (x*x + 21)%n+1;
}
ll gcd(ll a,ll b){
    ll t;
    while(b){
        t=a%b;
        a=b;
        b=t;
    }
    return a;
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
    ll a=1; 
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
ll pollard(ll n){
    if(n%2==0) return 2;
    static ll x=1;
    ll y=x;
    ll d=1;
    while (d==1){
        x=f(x,n);
        y=f(y,n);
        y=f(y,n);
        d=gcd(ab(x-y),n);
        if(d==n) break;
    }
    return d;
}

ll ans(ll n){
    queue<ll> Q;
    if(n==1) return 1;
    if(isprime(n)) return 2;
    ll m;
    map<ll,ll>ma;
    Q.push(n);
    while(!Q.empty()){
        //puts("running");
        ll l=Q.front();
        Q.pop();
        if(isprime(l)) {ma[l]+=1;continue;}
        ll d=pollard(l);
        if(d==l) Q.push(l);
        else{
            Q.push(d);
            Q.push(l/d);
        }
    }
    map<ll,ll>::iterator it=ma.begin();
    ll ret=1;
    while(it!=ma.end()){
        ret*=it->second+1;
        it++;
    }
    //printf("%d\n",isprime(n));
    //system("pause");
    return ret;
}

int main(){
    ll n,q,m;
    scanf("%lld %lld",&n,&q);
    ll tot=ans(n);
    while(q--){
        int ch;
        scanf("%d %lld",&ch,&m);
        if(ch==1) {printf("%lld\n",ans(gcd(n,m)));continue;}
        if(n%m) {
            if(ch==2) puts("0");
            else printf("%lld\n",tot);
        }
        else{
            if(ch==2) printf("%lld\n",ans(n/m));
            else printf("%lld\n",tot-ans(n/m));
        }
    }
    return 0;
}
