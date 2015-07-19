#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const ll MOD= 10000009;
int main(){
    int t,i,j;
    scanf("%d\n",&t);
    while(t--){
        string s;
        //gets(s);
        cin>>s;
        int l=s.size();
        int pos=1;
        ll ans=1;
        for(i=0,j=l-1;i<j && pos;i++,j--){
            if(s[i]!='?' && s[j]!='?'){
                if(s[i]!=s[j]) pos=0;
            }
            else if(s[i]=='?' && s[j]=='?')
                ans=(ans*26)%MOD;
        }
        if(i==j && pos){
            if(s[i]=='?') ans=(ans*26)%MOD;
        }
        if(pos==0) puts("0");
        else printf("%lld\n",ans);
    }
    return 0;
}
