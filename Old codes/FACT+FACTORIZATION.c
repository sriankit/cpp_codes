#include<stdio.h>
#include<math.h>
typedef long long ll;
int nxt=0;
long primes[78500];
ll fac[78500][2];
void init(){
    ll n=int(1e6)+1;
    int *arr=new int[n];
    int i,j;
    for(i=2;i<n;i++){
        if(arr[i]) continue;
        primes[nxt++]=i;
        for(j=2*i;j<n;j+=i)
            arr[j]=1;
    }
}
int main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        memset(fac,0,sizeof (fac));
        ll max=0;
        for(j=0;j<nxt;j++){
            if(k==1) break;
            if(k%primes[j]==0){
                fac[max][0]=primes[j];
                int lcnt=0;
                while(k%primes[j]==0){
                    k/=primes[j];
                    lcnt++;
                }
                fac[max++][1]=lcnt;
            }
        }
        if(k!=1){
            fac[max][0]=k;
            fac[max++][1]=1;
        }
        ll x;
        ll res=n;
        ll comp,win=INF;
        for(j=0;j<max;j++){
            n=res;
            x=fac[j][0];
            ll pw=0;
            while(n){
                n/=x;
                pw+=n;
            }
            comp=fac[j][1]-pw;
            if(comp<win) win=comp;
        }
        if(win>0) printf("%lld\n",win);
        else puts("0");
    }
    return 0;
}
