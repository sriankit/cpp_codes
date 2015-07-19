#include <stdio.h>
typedef long long ll;
ll dp[100][3];
int main(){
    FILE *fp=fopen("G:\\AMZSEQ.txt","w");
    dp[0][0]=dp[0][1]=dp[0][2]=1;
    int i=1;
    while(dp[i-1][1]<=1000000000){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i][0]+dp[i-1][0];
        fprintf(fp,"%lld,",dp[i][1]);
        i++;
    }
    system("pause");
    return 0;
}
    
