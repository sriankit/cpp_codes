#include<stdio.h>
#include<string.h>
int s[52][52];
int n,m,c;
int ok(int k){
    int temp[7][52]={0};
    int i,j;
    for(i=0;i<k;i++)
        for(j=0;j<m;j++)
            temp[(i<7)?i:i%7][j]+=s[i][j];
    int ret=0,min;
    for(i=0;i<7;i++){
        min=temp[i][0];
        for(j=1;j<m;j++)
            if(min>temp[i][j]) min=temp[i][j];
        ret+=min;
    }
    if(ret<=c) return 1;
    else return 0;
}
void solve(){
    int lo=0,hi=n,mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(ok(mid)) lo=mid+1;
        else hi=mid-1;
    }
    printf("%d\n",hi);
}
int main()
{
    int t,i,j,k,l;
    scanf("%d",&t);
    while(t--)
    {
        char s1[52];
        scanf("%d%d%d\n",&n,&m,&c);
        for(i=0;i<n;i++)
        {
            scanf("%s",s1);
            for(j=0;j<m;j++)
            {
                if(s1[j]>='0' && s1[j]<='9')
                s[i][j]=s1[j]-'0';
                else if(s1[j]>='a' && s1[j]<='z')
                s[i][j]=s1[j]-'a'+36;
                else
                s[i][j]=s1[j]-'A'+10;
            }
        }
        solve();
    }
    system("pause");
    return 0;
}
