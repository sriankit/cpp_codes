#include<stdio.h>
#include<iostream>
using namespace std;
void find_ans(long *a,int n,long long dec,long long k){
    //printf("dec=%ld k=%I64d\n",dec,k);
    cout<<"dec="<<dec<<"  "<<"k="<<k<<endl;
    int i=0;
    if(k<n){
        long cnt=0;
        while(cnt!=k){
            //i%=n;
            if(a[i%n]-dec-i/n>0) cnt++;
            i++;
        }
        dec+=i/n;
        int res=i%n;
        cout<<"res="<<res<<'\t';
        for(i=res;i<n;i++)
            if(a[i]-dec>0) printf("%d ",i+1);
        for(i=0;i<res;i++)
            if(a[i]-dec-1>0) printf("%d ",i+1);
        return;
    }
    long long d=k/n;
    long j=k%n;
    dec+=d;
    for(i=0;i<n;i++)
        if(a[i]-dec<0) j+=dec-a[i];
    find_ans(a,n,dec,j);
}
int main(){
    int n;
    long long int k,sum=0;
    //scanf("%d%I64d",&n,&k);
    cin>>n>>k;
    int i;
    long arr[n];
    for(i=0;i<n;i++){
        scanf("%ld",&arr[i]);
        sum+=arr[i];
    }
    if(sum<k) {puts("-1");return 0;}
    if(sum==k) return 0;
    find_ans(arr,n,0,k);
    return 0;
}
    
