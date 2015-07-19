#include<cstdio>
#include<map>
typedef long long ll;
using namespace std;
map<ll,ll> solved;
int arr[1001001];
int nxt=0;
int primes[78500];

inline ll scanInt()
{
ll noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
};

void init(){
    int i,j,n=1001000;
    for(i=2;i<n;i++){
        if(arr[i]) continue;
        primes[nxt++]=i;
        for(j=2*i;j<n;j+=i)
            arr[j]=1;
    }
}
ll gcd(ll a,ll b){
    if(b) return gcd(b,a%b);
    else return a;
}
ll find_ans(ll n){
    ll tmp=solved[n];
    //printf("%lld %lld  ",n,tmp);
    
    if(tmp) {return tmp;}
    ll res=n;
    int j=0;
    ll ret = 1;
    solved[res/n]=ret;
    for(j=0;j<nxt;j++){
        if(n==1) break;
        int cnt=0;
        while(n%primes[j]==0){
            //tmp=solved[n];
            //if(tmp) return tmp*ret*(cnt+1);
            n/=primes[j];
            cnt++;
        }
        
        ret*=(cnt+1);
    }
    if(n!=1) solved[res]=ret*2;
    else solved[res]=ret;
    return solved[res];
}
int main(){
    init();
    ll n,q,k;
    int t;
    //scanf("%lld %lld",&n,&q);
    n=scanInt();
    q=scanInt();
    ll total=find_ans(n);
    while(q--){
        //scanf("%d%lld",&t,&k);
        t=scanInt();
        k=scanInt();
        if(t==1){
            printf("%lld\n",find_ans(gcd(n,k)));
            continue;
        }
        if(n%k==0){
            ll m=n/k;
            ll ans=find_ans(m);
            if(t==2) printf("%lld\n",ans);
            else printf("%lld\n",total-ans);
        }
        else{
            if(t==2) puts("0");
            else printf("%lld\n",total);
        }
    }
    return 0;
}
