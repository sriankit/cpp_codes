#include<stdio.h>
#include<string.h>
long long int table[46][2];
long long int find_ans(int n,int last){
    if(n==1||n==0)
        return 1;
    if(table[n][last]!=-1) return table[n][last];
    else return table[n][last]=find_ans(n-1,!last)+find_ans(n-2,!last);
}
int main(){
    int n;
    scanf("%d",&n);
    //printf("%lld",find_ans(n-1,0)+find_ans(n-1,1));
    memset(table,-1,sizeof(table));
    long long int ans;
    ans=find_ans(n-1,0);
    memset(table,-1,sizeof(table));
    ans+=find_ans(n-1,1);
    printf("%lld",ans);
    return 0;
}
