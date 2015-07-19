#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int primes[78505];
int arr[1000005];
int nxt=1;
void init(){
    long long int i,j;
    primes[0]=2;
    arr[1]=1;
    for(i=2;i<1000003;i++){
        if(arr[i]) continue;
        primes[nxt++]=i;
        for(j=2*i;j<1000003;j+=i)
            arr[j]=1;
    }
}
int main(){
    init();
    long long int n,a,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        long long x=sqrt(a);
        if(x!=sqrt(a)){puts("NO");continue;}
        if(arr[x]) puts("NO");
        else puts("YES");
    }
    return 0;
}
