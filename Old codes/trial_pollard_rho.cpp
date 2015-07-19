#include<cstdio>
#include<map>
#include<queue>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
map<ll,ll> factors;

long long int powr(ll x, ll y,ll md)
{
    // printf("%d\n",y);
    ll temp=0;
    if( y == 0)
        return 1;
    else if(y==1)
        return x;
    else if (y%2 == 0)
    {
        temp=powr(x,y/2,md)%md;
        return (temp*temp)%md;
    }
 
    else
    {
        temp=powr(x,y/2,md)%md;
        return (x*((temp*temp)%md))%md;
    }
 
}

ll gcd(ll a ,ll b){
    if(b) return gcd(b,a%b);
    else return a;
}
int rabin_miller(ll p){
    if(p<2) return 0;
    if(p!=2 && p%2==0) return 0;
    ll s=p-1;
    while(s%2==0) s>>=1;
    for(int i=0;i<10;i++){
        ll a=rand()%(p-1)+1;
        ll temp=s;
        ll mod=powr(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=(mod*mod)%p;
            temp*=2;
        }
        if(mod!=p-1 && temp%2==0)
            return 0;
    }
    return 1;
}

ll brent(ll n){
    if(n%2==0) return 2;
    ll x=23432%n;
    ll c=4567%(n-1)+1;
    ll m=20%(n-1)+1;
    ll y=x,r=1,q=1;
    ll g=0,ys=0,k,i;
    while(1){
        x=y;
        for(i=0;i<r;i++){
            y=(y*y+c)%n;
            k=0;
        }
        while(1){
            ll ys=y;
            for(i=0;i<min(m,r-k);i++){
                y=(y*y+c)%n;
                q=q*abs(x-y)%n;
            }
            g=gcd(q,n);
            k=k+m;
            if(k>=r || g>1) break;
        }
        r*=2;
        if(g>1) break;
    }
    if(g==n){
        while (1){
            ys=(x*x+c)%n;
            g=gcd(abs(x-ys),n);
            if(g>1) break;
        }
    }
    return g;
}

ll pollard(ll n){
    if(n%2==0) return 2;
    ll x=20;
    ll c=23424;
    ll y=x;
    ll d=1;
    while (d==1){
        x=(x*x+c)%n;
        y=(y*y+c)%n;
        y=(y*y+c)%n;
        d=gcd(x-y,n);
        if(d==n) break;
    }
    return d;
}

map<ll,ll> factor(ll n){
    queue<ll> Q;
    map<ll,ll>m;
    ll l;
    Q.push(n);
    while(!Q.empty()){
        l=Q.front();
        Q.pop();
        if(rabin_miller(l)){
            m[l]++;
            continue;
        }
        ll d=pollard(l);
        if(d==l) Q.push(l);
        else{
            Q.push(d);
            Q.push(l/d);
        }
    }
    return m;
}

int main(){
    ll n;
    scanf("%lld",&n);
    //while(~scanf("%d",&n))
    {
        map<ll,ll>ma;
        ma=factor(n);
        map<ll,ll>::iterator it=ma.begin();
        while(it!=ma.end()){
            printf("%lld  %lld\n",it->first,it->second);
            it++;
        }
    }
    //system("pause");
    return  0;
}           
