#include<stdio.h>
#include<ctype.h>
#include<iostream>
using namespace std;
int main(){
    int t;
    scanf("%d\n",&t);
    long long dp[100]={0}; 
    while(t--){
        int s[100];
        int a[100];
        char c=getchar();
        a[0]=c-'0';
        int i=1,j=1;
        while(1){
            c=getchar();
            if(c=='+') s[i++]=0;
            else if(c=='*') s[i++]=1;
            else if(isdigit(c)) a[j++]=c-'0';
            else break;
        }
        //for(i=1;i<j;i++)
          //  printf("%d ",s[i]);
        //printf("\n");
        dp[0]=a[0];
        for(i=1;i<j;i++){
            //printf("state:%d\n",i);
            if(a[i]==0){
                int res=i;
                while(res>0&&s[res]!=0)
                    res--;
                if(res==0) dp[i]=0;
                else dp[i]=dp[res-1];
            }
            else{
                dp[i]=(s[i]==0)?(dp[i-1]+a[i]):(dp[i-1]*a[i]);
                //printf("dp ini=%d\n",dp[i]);
                int res=i;
                long long prob=0;
                while(res>0&&s[res]!=1){
                    prob+=a[res];
                    res--;
                }
                if(res!=0){
                    prob+=a[res];
                    if(dp[i]<prob*dp[res-1]) dp[i]=prob*dp[res-1];
                }
            }
        }
        //for(i=0;i<j;i++)
          //  printf("%ld ",dp[i]);
        printf("%lld ",dp[j-1]);
        memset(dp,0,sizeof(dp));
        dp[0]=a[0];
        if(dp[0]==0&&s[1]==1)
            {printf("0\n");goto print;}
        for(i=1;i<j;i++){
            if(a[i]==0){
                if(i==j-1&&s[i]==1)
                    dp[i]=0;
                else if(s[i]==1&&s[i+1]==1)
                    {printf("0\n");goto print;}
                else if(s[i]==1) dp[i]=0;
                else if(s[i+1]==1) {printf("%ld\n",dp[i-1]);goto print;}
                else dp[i]=dp[i-1];
            }
            else{
                dp[i]=(s[i]==0)?(dp[i-1]+a[i]):(dp[i-1]*a[i]);
                int res=i,prob=1;
                while(res>0&&s[res]!=0){
                    prob*=a[res];
                    res--;
                }
                if(res!=0){
                    prob*=a[res];
                    if(dp[i]>(prob+dp[res-1])) dp[i]=prob+dp[res-1];
                }
            }
        }
     printf("%lld\n",dp[j-1]);     
    print:;
    }
    return 0;
}
