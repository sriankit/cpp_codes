#include<stdio.h>
#include<string.h>
int a[101][101];
int risk[101][101];
int visited[101];
long table[101][251];
int ans[101][251];
const long INF=9999999;
int n;
long find_ans(int st,int tym){
    visited[st]=1;
    if(tym<0) return INF;
    if(table[st][tym]!=-1) return table[st][tym];
    if(st==n-1){
        if(tym<0) return INF;
        else return 0;
    }
    int i=st,j;
    long k;
    long int min=INF;
    for(j=0;j<n;j++)
        if(!visited[j]){
            if(min>(k=risk[st][j]+find_ans(j,tym-a[st][j]))){
                min=k;
                i=j;
            }
        }
    ans[st][tym]=i;
    return table[st][tym]=min;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int tym;
        scanf("%d%d",&n,&tym);
        int tt=tym;
        int i,j;
        memset(table,-1,sizeof(table));
        memset(ans,-1,sizeof(ans));
        memset(visited,0,sizeof(visited));
        for(i=0;i<n;i++)
            for (j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&risk[i][j]);
        //system("pause");
        printf("%ld ",find_ans(0,tym));
        i=0;
        //for(i=0;i<=tym;i++)
            //printf("%d %d",table[1][4],ans[1][4]);
        while(i!=n-1){
            //printf("\tval=%d tym=%d\n",ans[i][tym],tym);
            j=ans[i][tym];
            tym=tym-a[i][j];
            i=j;
        }
        printf("%d\n",tt-tym);
    }
    return 0;
}  
