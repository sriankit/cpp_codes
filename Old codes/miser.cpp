#include<stdio.h>
#include<string.h>
long min(long a,long b){
    if(a<b) return a;
    else return b;
}
long arr[101][101];
long long table[101][101];
int n,m;
long find_ans(int i,int j){
    if(i<0||j>=m||j<0||i>=n) return 9999999;
    if(table[i][j]!=0) return table[i][j];
    if (i==0)
        table[i][j]=arr[i][j];
    else
        table[i][j]=min(find_ans(i-1,j-1),find_ans(i-1,j+1))+arr[i][j];
    return table[i][j];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        m=3;
        int i,j;
        memset(table,0,sizeof(table));
        /*for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                printf("%d ",table[i][j]);
            printf("\n");
        }*/
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
              scanf("%ld",&arr[i][j]);
        long ans=9999999,cur;
        for(j=0;j<m;j++)
            if((cur=find_ans(n-1,j))<ans)
                ans=cur;
        
        printf("%ld\n",ans);
    }
    return 0;
}              
