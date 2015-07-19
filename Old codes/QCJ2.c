#include<stdio.h>
typedef long long ll;
ll table[105][105];
#define MOD 761238923
ll mod(ll x){
    if(x<0) return mod(x+MOD);
    return x%MOD;
}
int main(){
    int i,j,n;
    table[0][0]=1;
    for(i=1;i<=100;i++){
        table[i][0]=1;
        for(j=1;j<=i;j++)
            table[i][j]=mod(table[i-1][j]+table[i][j-1]);
    }
    while(scanf("%d",&n),n!=0){
        printf("%lld\n",table[n][n]);
    }
    return 0;
}
        
