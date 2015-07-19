#include<stdio.h>
typedef long long ll;
ll table[2000][2000];
ll refactor(int i,ll n){
    if(table[i][n]) return table[i][n];
    int k;
    ll ret=0;
    for(k=i;k*k<=n;k++){
        if(n%k==0) ret+=1+refactor(k,n/k);
    }
    return table[i][n]=ret;
}
int main(){
    ll n;
    while(1){
        memset(table,0,sizeof(table));
        scanf("%lld",&n);
        printf("%lld\n",refactor(2,n));
    }
    return 0;
}
    
    
