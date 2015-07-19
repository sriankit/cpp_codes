#include<stdio.h>
typedef long long ll;
int arr[1001001];
int nxt=0;
int primes[78500];
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
    int j=0;
    ll ret = 1;
    for(j=0;j<nxt;j++){
        if(n==1) break;
        int cnt=0;
        while(n%primes[j]==0){
            n/=primes[j];
            cnt++;
        }
        ret*=(cnt+1);
    }
    return ret;
}
int main(){
    init();
    ll n,q,k;
    int t;
    scanf("%lld%lld",&n,&q);
    ll total=find_ans(n);
    while(q--){
        scanf("%d%lld",&t,&k);
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
