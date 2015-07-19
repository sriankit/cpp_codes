#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int t,i,ans;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        ans=0;
        for(i=0;i<s.size();i++)
            ans=ans+s[i]-'0';
        long long int m=1;
        for(i=1;i<s.size();i++){
            m=(m*2)%9;
        }
        printf("%d\n",(ans*m)%9);
    }
    system("pause");
    return 0;
}
