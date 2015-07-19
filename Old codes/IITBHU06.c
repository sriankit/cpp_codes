#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        ans=0;
        for(i=0;i<s.size();i++)
            ans=(ans+s[i]-'0')%9;
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
