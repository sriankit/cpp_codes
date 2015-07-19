#include<stdio.h>
int m,n;
const long INF=9999999;
int a[501][501];
long f(int i,int j){
    long s=0;
    if(i<n && j+1<m && a[i][j+1]<0) s+=a[i][j+1];
     if(i<n && j-1>=0 && a[i][j-1]<0) s+=a[i][j-1];
     if(i+1<n && j+1<m && a[i+1][j+1]<0) s+=a[i+1][j+1];
     if(i+1<n && j<m && a[i+1][j]<0) s+=a[i+1][j];
     if(i+1<n && j-1>=0 && a[i+1][j-1]<0) s+=a[i+1][j-1];
     if(i-1>=0 && j+1<m && a[i-1][j+1]<0) s+=a[i-1][j+1];
     if(i-1>=0 && j<m && a[i-1][j]<0) s+=a[i-1][j];
     if(i-1>=0 && j-1>=0 && a[i-1][j-1]<0) s+=a[i-1][j-1];
    return s;
}
long find_ans(int i,int j){
    long max=0,prob;
    if(a[i][j]<0) return -INF;
    if(i+1<n) max=find_ans(i+1,j);
    if(j+1<m) {prob=find_ans(i,j+1); if(max<prob) max=prob;}
    if(max==0) return 0;
    return a[i][j]+f(i,j)+max;
}
int main(){
    scanf("%d,%d",&n,&m);
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m-1;j++)
            scanf("%d",&a[i][j]);
        scanf("%d",&a[i][j]);
    }
    printf("%ld",find_ans(0,0));
    return 0;
}
