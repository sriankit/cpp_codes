#include<stdio.h>
long arr[101][101];
long long table[101][101];
int n,m;
long find_ans(int i,int j){
    if(i<0||j>m||j<0||i>n) return 9999999;
    if(table[i][j]!=0) return table[i][j];
    long k;long long ret=0,temp;
    if(i==0){
        for(k=j-1;;k++){
            if(k>j+1) break;
            if(k>=0&&k<m)
                 if(arr[i][k]<ret)
                    ret=arr[i][k];
            }
        }
    else
        for(k=j-1;k<=j+1;k++){
            table[i-1][k]=find_ans(i-1,k);
            if(table[i-1][k]<ret) ret=table[i-1][k];
        }
    return table[i][j]=ret;      
int main(){
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%ld",&arr[i][j]);
    long long min=0,cur;
    for(j=0;j<m;j++){
        memset(table,0,sizeof(table));
        if((cur=find_ans(n-1,j))<min)
            min=cur;
    }
    printf("%ld\n",min);
    return 0;
}              
