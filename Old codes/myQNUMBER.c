#include<stdio.h>
typedef long long ll;
long primes[78500];
int arr[1000001];
ll gcd(ll a,ll b){
if(b) return gcd(b,a%b);
else return a;
}
 
void init(){
int i,j,nxt=0;
long n=1000001;
for(i=2;i<n;i++){
if(arr[i]) continue;
primes[nxt++]=i;
for(j=2*i;j<n;j+=i)
arr[j]=1;
}
}
ll ans(ll n){
ll ret=1,j=0;
while(primes[j]){
ll cnt=0;
while(n%primes[j]==0) {n/=primes[j];cnt++;}
ret*=(cnt+1);
j++;
}
if(n>1) return ret*2;
return ret;
}
int main(){
init();
ll n,q,m,tot,prob;
scanf("%lld %lld",&n,&q);
tot=ans(n);
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
