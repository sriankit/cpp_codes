#include<iostream>
#include<map>
#include<ctime>
#define F(t) t->first
#define S(t) t->second
using namespace std;
typedef long long ll;
map<ll,ll>mapf;
ll gcd(ll a,ll b){
    if(b) return gcd(b,a%b);
    else return a;
}

/* this function calculates (a*b)%c taking into account that a*b might overflow */
ll f(ll x){
    return x*x+1;
}
long long modulo(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(long long p,int iteration){
    srand(time(NULL));
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=modulo(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}
ll find_fac(ll n){
    
    if(n%2==0)return 2;
    ll x=2;
    ll y=2;
    ll d=1;
    while(d==1){
        x=f(x)%n;
        y=f(f(y))%n;
        d=gcd(abs(x-y),n);
    }
    return d;
}
void factor(ll n){
    if(n==1) return; 
    if(Miller(n,5)) {mapf[n]+=1;return;}
    ll d=find_fac(n);
    factor(d);
    factor(n/d);
}
int main(){
    int nt;
    ll n;
    //scanf("%d",&nt);
    //while(nt--){
    while(1){
        mapf.clear();
        scanf("%lld",&n);
        //factor(n);
        map<ll,ll>::iterator it=mapf.begin();
        ll ans=1;
        if(Miller(n,2)) puts("prime");
        else puts("not prime");
        while(it!=mapf.end()){
            //ans*=(modulo(F(it),S(it)+1,(ll)1e17)-1)/((F(it))-1);
            printf("%lld %lld\n",it->first,it->second);
            it++;
        }
        //printf("%lld\n",ans);
    }
    return 0;
}
            
