#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
string s;
long long dp[5001];
int main(){
    int l,i;
    cin>>s;
    while(s!="0"){
        l=s.size();
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        if(s[1]=='0') dp[1]=1; 
        else if((s[1]-'0')+10*(s[0]-'0')<=26) dp[1]=2;
        else dp[1]=1;
        for(i=2;i<l;i++){
            if(s[i]=='0') dp[i]=dp[i-2];
            else if(s[i-1]=='0') dp[i]=dp[i-1];
            else if(s[i]-'0'+10*(s[i-1]-'0')<=26) dp[i]=dp[i-1]+dp[i-2];
            else dp[i]=dp[i-1];
        }
        cout<<dp[l-1]<<endl;
        cin>>s;
    }
    return 0;
}
