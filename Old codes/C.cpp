#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int arr[(int)1e7];
int primes[(int)2e5];
ll rep1[(int)2e5];
ll rep2[(int)2e5];
vector<ll>ans1;
vector<ll>ans2;
vector<long>vp1;
vector<long>vpe1;
vector<long>vp2;
vector<long>vpe2;
int nxt=0,max1,max2;
void init(){
    int i,j,n=(int)1e7;
    for(i=2;i<n;i++){
        if(arr[i])continue;
        primes[nxt++]=i;
        for(j=2*i;j<n;j+=i)
            arr[j]=1;
    }
}
void factor1(ll n){
    int j=0;
    for(j=0;j<nxt;j++){
        if(n==1) break;
        while(n%primes[j]==0){
            n/=primes[j];
            rep1[j]++;
        }
    }
    max1=j;
    /*if(n==1) return ;
    for(j=0;j<vp1.size();j++){
        while(n%vp1[j]==0){
            n/=vp1[j];
            vpe1[j]++;
        }
    }
    if(n==1) return;
    vp1.push_back(n);
    vpe1.push_back(1);*/ 
}

void factor2(ll n){
    int j=0;
    for(j=0;j<nxt;j++){
        if(n==1) break;
        while(n%primes[j]==0){
            n/=primes[j];
            rep2[j]++;
        }
    }
    max2=j;
    /*if(n==1) return ;
    for(j=0;j<vp2.size();j++){
        while(n%vp2[j]==0){
            n/=vp2[j];
            vpe2[j]++;
        }
    }
    if(n==1) return;
    vp2.push_back(n);
    vpe2.push_back(1); */
}

int main(){
    init();
    int n1,n2;
    long long n;
    scanf("%d%d",&n1,&n2);
    while(n1--){
        cin>>n;
        factor1(n);
    }
    while(n2--){
        cin>>n;
        factor2(n);
    }
    max1=(max1>max2)?max1:max2;
    for(i=0;i<max1;i++){
        if(rep1[i]>rep2[i]){
            rep1[i]=rep1[i]-rep2[i];
            rep2[i]=0;
        }
        else{
            rep2[i]=rep2[i]-rep1[i];
            rep1[i]=0;
        }
    }
    ll ans=1;
    for(i=0;i<max1;i++){
        ll p=pow(primes[i],rep1[i]);
        if(ans*p<(long int)1e7) ans*=p;
        else ans1.push_back(ans);
        ans=p;
    }
    ans=1;
    for(i=0;i<max1;i++){
        ll p=pow(primes[i],rep2[i]);
        if(ans*p<(long int)1e7) ans*=p;
        else ans2.push_back(ans);
        ans=p;
    }
    printf("%ld %ld\n",ans1.size(),ans2.size());
    for(i=0;i<ans1.size();i++) printf("%ld ",ans1[i]);
    printf("\n");
    for(i=0;i<ans2.size();i++) printf("%ld ",ans2[i]);
    return 0;
}
