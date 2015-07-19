#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
int arr[1001001];
map<int,int> ma;
int nxt=0;
int primes[78500];
ll powr(ll x,ll y,ll mod){
    if(y==1) return x;
    ll u=(x*x)%mod;
    u=powr(u,y/2,mod);
    if(y&1) u=(u*x)%mod;
    return u;
} 
void init(){
    int i,j,n=1001000;
    for(i=2;i<n;i++){
        if(arr[i]) continue;
        primes[nxt++]=i;
        for(j=2*i;j<n;j+=i)
            arr[j]=1;
    }
}
void factor(int n){
    int j;
    for(j=0;j<nxt;j++){
        if(n==1) break;
        if(n%primes[j]==0){
            ma[primes[j]]=1;
            while(n%primes[j]==0)
                n/=primes[j];
        }
    }
    if(n!=1) ma[n]=1;
    return;
} 
int main(){
    init();
    int p,q,r;
    scanf("%d%d",&p,&q);
    while(p+q){
        ma.clear();
        factor(p-1);
        while(q--){
        if(p==2) {puts("YES");continue;}
        scanf("%d",&r);
        map<int,int>::iterator it=ma.begin();
        r%=p;
        if(r==0||r==1) {puts("No");continue;}
        int ans=1;
        while(it!=ma.end()){
            if(ans==0) break;
            if(powr(r,(p-1)/(it->first),p)==1)
                 ans=0;
            it++;
        }
        if(ans) puts("YES");
        else puts("NO");
        }
        scanf("%d%d",&p,&q);
    }
    return 0;
}
