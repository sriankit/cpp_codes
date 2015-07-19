#include<stdio.h>
#include<ctype.h>
#include<iostream>
using namespace std;
long long fun(long long a,long long b,int s){
    if(s==0) return a+b;
    else return a*b;
}
int main(){
    int t;
    scanf("%d",&t);
    long long dp[100]={0}; 
    while(t--){
        int s[100];
        long long int a[100];
        scanf("%d",&a[0]);
        int i=1,j=1;
        while(1){
            char c=getchar();
            if(c=='+') s[i++]=0;
            else if(c=='*') s[i++]=1;
            else if(isdigit(c)) a[j++]=c-'0';
            else break;
        }
        dp[0]=a[0];
        for(i=1;i<j;i++){
            if(a[i]==0){
                int res=i;
                while(res>0&&s[res]!=0)
                    res--;
                if(res==0) dp[i]=0;
                else dp[i]=dp[res-1];
            }
            else{
                dp[i]=fun(dp[i-1],a[i],s[i]);
                int res=i,prob=0;
                while(res>0&&s[res]!=1){
                    prob+=a[res];
                    res--;
                }
                if(res!=0 && ((prob+a[res])*dp[res-1])>dp[i])
                    dp[i]=(prob+a[res])*dp[res-1];
            }
        }
        cout<<dp[i-1];
    }
    return 0;
}
